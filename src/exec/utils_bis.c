/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 06:46:06 by maba              #+#    #+#             */
/*   Updated: 2025/04/03 06:51:28 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static double	calculate_proj_distance(t_data *dt)
{
	return ((dt->map->res_w / 2.0) / tan(FOV * M_PI / 360.0));
}

double	calc_wall_height_1(t_data *dt)
{
	double	wall_height;

	wall_height = (TILE_SIZE / dt->ray->perpWallDist)
		* calculate_proj_distance(dt);
	return (wall_height);
}
