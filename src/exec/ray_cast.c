/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:00:24 by maba              #+#    #+#             */
/*   Updated: 2025/05/16 19:25:00 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"



// Cette fonction calcule la distance perpendiculaire entre le joueur et le mur touché par le rayon.
void	define_perp_wall_distance(t_ray *ray, t_player *player)
{
	double	angle_difference;

	if (ray->side == VERTICAL)
	{
		ray->perp_wall_dist = (ray->map.column - player->pos_x + \
							(1 - ray->step_x) / 2) / ray->dir_x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map.row - player->pos_y + \
							(1 - ray->step_y) / 2) / ray->dir_y;
	}
	angle_difference = ray->angle - player->angle;
	angle_difference = fmod(angle_difference + M_PI, 2 * M_PI) - M_PI;
	ray->perp_wall_dist *= cos(angle_difference);
	ray->dir_x /= cos(angle_difference);
	ray->dir_y /= cos(angle_difference);
	if (ray->perp_wall_dist < 0.0001)
        ray->perp_wall_dist = 0.0001;
	
}

// Cette fonction détermine quel côté du mur a été touché par le rayon.
void	define_wall_side(t_ray *ray)
{
	if (ray->side == VERTICAL)
	{
		if (ray->step_x > 0)
			ray->wall = EAST;
		else
			ray->wall = WEST;
	}
	else if (ray->side == HORIZONTAL)
	{
		if (ray->step_y > 0)
			ray->wall = SOUTH;
		else
			ray->wall = NORTH;
	}
}

// Cette fonction détecte la collision du rayon avec un mur.
void	define_wall_collision(t_data *data, t_ray *ray)
{
	int	wall_hit;

	wall_hit = 0;

	while (wall_hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map.column += ray->step_x;
			ray->side = VERTICAL;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map.row += ray->step_y;
			ray->side = HORIZONTAL;
		}
		int row = ray->map.row;
		int col = ray->map.column;
		if (row < 0 || row >= data->map->m_h || col < 0 || col >= data->map->m_w)
			break;
		if (data->map->map_cub[row][col] == '1')
			wall_hit = 1;
	}

	define_perp_wall_distance(ray, data->player);
	define_wall_side(ray);
}


// Cette fonction initialise les directions et les distances initiales pour le rayon.
void	define_step_direction(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map.column) \
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map.column + 1.0 - player->pos_x) \
							* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map.row) \
							* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map.row + 1.0 - player->pos_y) \
							* ray->delta_dist_y;
	}
}
// Cette fonction principale gère le lancer de rayons pour chaque colonne de l'écran.
void	raycast(t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < data->map->res_w)
	{
		ray.angle = data->player->angle + atan((2.0 * x / data->map->res_w - 1.0) \
					* tan(data->player->fov_rd / 2));
		ray.angle = fmod(ray.angle, convert_to_radians(360));
		if (ray.angle < 0)
			ray.angle += convert_to_radians(360);
		ray.dir_x = cos(ray.angle);
		ray.dir_y = sin(ray.angle);
		// printf("Ray Angle: %f, DirX: %f, DirY: %f\n", ray.angle, ray.dir_x, ray.dir_y);
		ray.map.row = (int)data->player->pos_y;
		ray.map.column = (int)data->player->pos_x;
		ray.delta_dist_x = fabs(1 / ray.dir_x);
		ray.delta_dist_y = fabs(1 / ray.dir_y);
		define_step_direction(&ray, data->player);
		define_wall_collision(data, &ray);
		rendering(data, &ray, x);
		x++;
	}
}
