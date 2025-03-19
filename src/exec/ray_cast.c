/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:00:24 by maba              #+#    #+#             */
/*   Updated: 2025/03/19 13:03:44 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int wall_hit(t_data *data, float x, float y)
{
	int x_step;
	int y_step;

	if (x < 0 || y < 0)
		return (0);

	x_step = floor(x / TILE_SIZE);
	y_step = floor(y / TILE_SIZE);

	if (x_step >= MAX_WIDTH || y_step >= MAX_HEIGHT)
		return (0);

	if (data->map->map_cub[y_step] &&
		x_step < (int)ft_strlen(data->map->map_cub[y_step]))
		if (data->map->map_cub[y_step][x_step] == '1')
			return (0);
	return (1);
}

float get_h_inter(t_data *dt)
{
	float h_x, h_y;
	float x_step, y_step;
	int unit_circle;

	unit_circle = 0;
	x_step = TILE_SIZE / tan(dt->ray->rayAngle);
	y_step = TILE_SIZE;
	h_y = floor(dt->player->posY / TILE_SIZE) * TILE_SIZE;
	dt->pixel = inter_check(dt->ray->rayAngle, &h_y, &y_step, 1);
	h_x = dt->player->posX + (h_y - dt->player->posY) / tan(dt->ray->rayAngle);

	if (dt->ray->rayAngle > (M_PI / 2) && dt->ray->rayAngle < (3 * M_PI) / 2)
		unit_circle = 1;
	if ((unit_circle && x_step > 0) || (!unit_circle && x_step < 0))
		x_step *= -1;

	while (wall_hit(dt, h_x, h_y - dt->pixel))
	{
		h_x += x_step;
		h_y += y_step;
	}

	dt->ray->stepX = h_x;
	dt->ray->stepY = h_y;
	return (distance(h_x, dt->player->posX, h_y, dt->player->posY));
}

float get_v_inter(t_data *dt)
{
	float v_x, v_y;
	float x_step, y_step;
	int unit_circle;

	unit_circle = 0;
	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(dt->ray->rayAngle);
	v_x = floor(dt->player->posX / TILE_SIZE) * TILE_SIZE;
	dt->pixel = inter_check(dt->ray->rayAngle, &v_x, &x_step, 0);
	v_y = dt->player->posY + (v_x - dt->player->posX) * tan(dt->ray->rayAngle);

	if (dt->ray->rayAngle > 0 && dt->ray->rayAngle < M_PI)
		unit_circle = 1;
	if ((unit_circle && y_step < 0) || (!unit_circle && y_step > 0))
		y_step *= -1;

	while (wall_hit(dt, v_x - dt->pixel, v_y))
	{
		v_x += x_step;
		v_y += y_step;
	}

	dt->ray->vert_x = v_x;
	dt->ray->vert_y = v_y;
	return (distance(v_x, dt->player->posX, v_y, dt->player->posY));
}

void raycast(t_data *data)
{
	float	h_inter;
	float	v_inter;
	int		ray;

	ray = 0;
	data->ray = ft_calloc(sizeof(t_ray), 1);
	data->ray->rayAngle = data->player->angle - (data->player->fov_rd / 2);
	// (FOV * M_PI / 360);

	while (ray < data->map->res_w)
	{
		data->ray->flag = 0;
		data->ray->rayAngle = check_angle(data->ray->rayAngle);
		h_inter = get_h_inter(data);
		v_inter = get_v_inter(data);
		if (v_inter <= h_inter)
		{
			data->ray->perpWallDist = v_inter;
			data->ray->flag = 0;
		}
		else
		{
			data->ray->perpWallDist = h_inter;
			data->ray->flag = 1;
		}
		render_wall(data, ray);
		ray++;
		data->ray->rayAngle += (data->player->fov_rd / data->map->res_w);
	}
}
