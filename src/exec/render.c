/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:48:31 by maba              #+#    #+#             */
/*   Updated: 2025/04/03 06:55:46 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_map(t_data *dt)
{
	int	x;
	int	y;
	int	median;

	x = 0;
	median = dt->map->res_h / 2;
	while (x < dt->map->res_w)
	{
		y = 0;
		while (y < median)
		{
			mlx_put_pixel(dt->win, x, y, dt->map->ceiling_color);
			mlx_put_pixel(dt->win, x, dt->map->res_h - 1 - y,
				dt->map->floor_color);
			y++;
		}
		x++;
	}
}

void	my_pixel_put(t_data *dt, int x, int y, uint32_t color)
{
	if (x < 0 || x >= dt->map->res_w)
		return ;
	if (y < 0 && y >= dt->map->res_h)
		return ;
	mlx_put_pixel(dt->win, x, y, color);
}

// void	display_wall(t_data *dt, int top_pix, int bottom_pix, double wall_h)
// {
// 	double		x_o;
// 	double		y_o;
// 	double		factor;
// 	uint32_t	color;

// 	color = 0;
// 	dt->text = set_texture(dt);
// 	factor = (double)dt->text->height / wall_h;
// 	if (dt->ray->flag == 1)
// 		x_o = (int)fmod((dt->ray->stepX * (dt->text->width / TILE_SIZE)),
// 				(dt->text->width));
// 	else
// 		x_o = (int)fmod((dt->ray->vert_y * (dt->text->width / TILE_SIZE)),
// 				(dt->text->width));
// 	x_o = fmod(fabs(x_o), dt->text->width);
// 	y_o = (top_pix - (dt->map->res_h / 2) + (wall_h / 2)) * factor;
// 	while (top_pix < bottom_pix)
// 	{
// 		if (y_o >= 0 && y_o < dt->text->height)
// 		{
// 			color = ((uint32_t *)dt->text->pixels)[(int)y_o * dt->text->width
// 				+ (int)x_o];
// 			my_pixel_put(dt, dt->ray->i, top_pix, reverse_bytes(color));
// 		}
// 		y_o += factor;
// 		top_pix++;
// 	}
// }

void	display_wall(t_data *dt, int top_pix, int bottom_pix, double wall_h)
{
	t_wall_vars	vars;

	vars.color = 0;
	dt->text = set_texture(dt);
	vars.factor = (double)dt->text->height / wall_h;
	if (dt->ray->flag == 1)
		vars.x_o = (int)fmod((dt->ray->stepX * (dt->text->width / TILE_SIZE)),
				(dt->text->width));
	else
		vars.x_o = (int)fmod((dt->ray->vert_y * (dt->text->width / TILE_SIZE)),
				(dt->text->width));
	vars.x_o = fmod(fabs(vars.x_o), dt->text->width);
	vars.y_o = (top_pix - (dt->map->res_h / 2) + (wall_h / 2)) * vars.factor;
	while (top_pix < bottom_pix)
	{
		if (vars.y_o >= 0 && vars.y_o < dt->text->height)
		{
			vars.color = ((uint32_t *)dt->text->pixels)[(int)vars.y_o
				* dt->text->width + (int)vars.x_o];
			my_pixel_put(dt, dt->ray->i, top_pix, reverse_bytes(vars.color));
		}
		vars.y_o += vars.factor;
		top_pix++;
	}
}

void	render_wall(t_data *dt, int ray)
{
	double	wall_h;
	double	bottom_pix;
	double	top_pix;
	double	angle_diff;

	angle_diff = check_angle(dt->ray->rayAngle - dt->player->angle);
	dt->ray->perpWallDist *= cos(angle_diff);
	wall_h = calc_wall_height_1(dt);
	bottom_pix = (dt->map->res_h / 2.0) + (wall_h / 2.0);
	top_pix = (dt->map->res_h / 2.0) - (wall_h / 2.0);
	bottom_pix = fmin(bottom_pix, dt->map->res_h);
	top_pix = fmax(top_pix, 0);
	dt->ray->i = ray;
	display_wall(dt, top_pix, bottom_pix, wall_h);
}
