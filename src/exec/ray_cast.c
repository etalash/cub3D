/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:00:24 by maba              #+#    #+#             */
/*   Updated: 2025/04/07 05:46:04 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	inter_check(float angle, float *inter, float *step, int is_horizon)
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

int	wall_hit(t_data *data, float x, float y)
{
	int	x_step;
	int	y_step;

	if (x < 0 || y < 0)
		return (0);
	x_step = floor(x / TILE_SIZE);
	y_step = floor(y / TILE_SIZE);
	if (x_step >= MAX_WIDTH || y_step >= MAX_HEIGHT)
		return (0);
	if (data->map->map_cub[y_step]
		&& x_step < (int)ft_strlen(data->map->map_cub[y_step]))
		if (data->map->map_cub[y_step][x_step] == '1')
			return (0);
	return (1);
}

float	get_h_inter(t_data *dt)
{
	int		unit_circle;
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;

	unit_circle = 0;
	x_step = TILE_SIZE / tan(dt->ray->ray_angle);
	y_step = TILE_SIZE;
	h_y = floor(dt->player->pos_y / TILE_SIZE) * TILE_SIZE;
	dt->pixel = inter_check(dt->ray->ray_angle, &h_y, &y_step, 1);
	h_x = dt->player->pos_x + (h_y - dt->player->pos_y)
		/ tan(dt->ray->ray_angle);
	if (dt->ray->ray_angle > (M_PI / 2) && dt->ray->ray_angle < (3 * M_PI) / 2)
		unit_circle = 1;
	if ((unit_circle && x_step > 0) || (!unit_circle && x_step < 0))
		x_step *= -1;
	while (wall_hit(dt, h_x, h_y - dt->pixel))
	{
		h_x += x_step;
		h_y += y_step;
	}
	dt->ray->step_x = h_x;
	dt->ray->step_y = h_y;
	return (distance(h_x, dt->player->pos_x, h_y, dt->player->pos_y));
}

float	get_v_inter(t_data *dt)
{
	int		unit_circle;
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;

	unit_circle = 0;
	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(dt->ray->ray_angle);
	v_x = floor(dt->player->pos_x / TILE_SIZE) * TILE_SIZE;
	dt->pixel = inter_check(dt->ray->ray_angle, &v_x, &x_step, 0);
	v_y = dt->player->pos_y + (v_x - dt->player->pos_x)
		* tan(dt->ray->ray_angle);
	if (dt->ray->ray_angle > 0 && dt->ray->ray_angle < M_PI)
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
	return (distance(v_x, dt->player->pos_x, v_y, dt->player->pos_y));
}

void	raycast(t_data *data)
{
	t_raycast_vars	vars;

	vars.ray = 0;
	data->ray->ray_angle = data->player->angle - (data->player->fov_rd / 2);
	while (vars.ray < data->map->res_w)
	{
		data->ray->flag = 0;
		data->ray->ray_angle = check_angle(data->ray->ray_angle);
		vars.h_inter = get_h_inter(data);
		vars.v_inter = get_v_inter(data);
		if (vars.v_inter <= vars.h_inter)
		{
			data->ray->perp_wall_dist = vars.v_inter;
			data->ray->flag = 0;
		}
		else
		{
			data->ray->perp_wall_dist = vars.h_inter;
			data->ray->flag = 1;
		}
		render_wall(data, vars.ray);
		vars.ray++;
		data->ray->ray_angle += (data->player->fov_rd / data->map->res_w);
	}
}
