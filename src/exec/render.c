/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:48:31 by maba              #+#    #+#             */
/*   Updated: 2025/03/19 13:05:43 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static double calculate_proj_distance(t_data *dt)
{
    return ((dt->map->res_w / 2.0) / tan(FOV * M_PI / 360.0));
}

double calc_wall_height_1(t_data *dt)
{
	double wall_height;

	wall_height = (TILE_SIZE / dt->ray->perpWallDist) * calculate_proj_distance(dt); //(dt->map->res_w / 2);
	return (wall_height);
}

void draw_map(t_data *dt)
{
	int x;
	int y;
	int median;

	x = 0;
	median = dt->map->res_h / 2;
	while (x < dt->map->res_w)
	{
		y = 0;
		while (y < median)
		{
			mlx_put_pixel(dt->win, x, y, dt->map->ceiling_color);
			mlx_put_pixel(dt->win, x, dt->map->res_h - 1 - y, dt->map->floor_color);
			y++;
		}
		x++;
	}
}

void my_pixel_put(t_data *dt, int x, int y, uint32_t color)
{
	if (x < 0 || x >= dt->map->res_w)
		return;
	if (y < 0 && y >= dt->map->res_h)
		return;
	mlx_put_pixel(dt->win, x, y, color);
}

void display_wall(t_data *dt, int top_pix, int bottom_pix, double wall_h)
{
	double x_o;
	double y_o;
	double factor;
	uint32_t color;

	color = 0;
	dt->text = set_texture(dt);
	factor = (double)dt->text->height / wall_h;
	if (dt->ray->flag == 1)
		x_o = (int)fmod((dt->ray->stepX * (dt->text->width / TILE_SIZE)),
						(dt->text->width));
	else
		x_o = (int)fmod((dt->ray->vert_y * (dt->text->width / TILE_SIZE)),
						(dt->text->width));

	// y_o = (top_pix - (dt->map->res_h / 2) + (wall_h / 2)) * factor;
	// x_o = fmax(0, x_o);
	// y_o = fmax(0, y_o);
	// while (top_pix < bottom_pix)
	// {
	// 	color = ((uint32_t *)dt->text->pixels)[(int)y_o *
	// 											   dt->text->width +
	// 										   (int)x_o];
	// 	my_pixel_put(dt, dt->ray->i, top_pix, reverse_bytes(color));
	// 	y_o += factor;
	// 	top_pix++;
	// }
	// Ensure x_o is within texture bounds
	x_o = fmod(fabs(x_o), dt->text->width);

	// Calculate initial y coordinate for texture mapping
	y_o = (top_pix - (dt->map->res_h / 2) + (wall_h / 2)) * factor;

	while (top_pix < bottom_pix)
	{
	    if (y_o >= 0 && y_o < dt->text->height)
	    {
	        color = ((uint32_t *)dt->text->pixels)[(int)y_o * dt->text->width + (int)x_o];
	        my_pixel_put(dt, dt->ray->i, top_pix, reverse_bytes(color));
	    }
	    y_o += factor;
	    top_pix++;
	}
}

void render_wall(t_data *dt, int ray)
{
	double wall_h;
	double bottom_pix;
	double top_pix;
	double angle_diff;

	// Calculate angle between ray and player direction for fish-eye correction
	angle_diff = check_angle(dt->ray->rayAngle - dt->player->angle);

	// Apply fish-eye correction
	dt->ray->perpWallDist *= cos(angle_diff);

	// Calculate wall height with proper perspective
	wall_h = calc_wall_height_1(dt);

	// Calculate wall position on screen
	bottom_pix = (dt->map->res_h / 2.0) + (wall_h / 2.0);
	top_pix = (dt->map->res_h / 2.0) - (wall_h / 2.0);

	// if (bottom_pix > dt->map->res_h)
	// 	bottom_pix = dt->map->res_h;
	// if (top_pix < 0)
	// 	top_pix = 0;
	// Clamp values to screen boundaries
	bottom_pix = fmin(bottom_pix, dt->map->res_h);
	top_pix = fmax(top_pix, 0);
	dt->ray->i = ray;
	display_wall(dt, top_pix, bottom_pix, wall_h);
}