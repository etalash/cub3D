/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:14:58 by stalash           #+#    #+#             */
/*   Updated: 2025/04/03 02:24:44 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

float	check_angle(float angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

double	distance(float x1, int x2, float y1, int y2)
{
	double	dis_two;
	double	dis_one;

	dis_one = pow(x1 - x2, 2);
	dis_two = pow(y1 - y2, 2);
	return (sqrt(dis_one + dis_two));
}

double	calc_wall_height(t_data *data)
{
	double	wall_height;

	wall_height = (TILE_SIZE / data->ray->perpWallDist) * (data->map->res_w
			/ 2);
	return (wall_height);
}

mlx_texture_t	*set_texture(t_data *data)
{
	if (data->ray->flag == 0)
	{
		if (data->ray->rayAngle > M_PI / 2 && data->ray->rayAngle < 3 * (M_PI
				/ 2))
			return (data->east);
		else
			return (data->west);
	}
	else
	{
		if (data->ray->rayAngle > 0 && data->ray->rayAngle < M_PI)
			return (data->south);
		else
			return (data->north);
	}
}
