/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:48:31 by maba              #+#    #+#             */
/*   Updated: 2025/03/15 06:52:05 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    if (x < 0 || x >= RES_X || y < 0 || y >= RES_Y)
        return;
    mlx_put_pixel(data->win, x, y, color);
}

float nor_angle(float angle)
{
    while (angle < 0)
        angle += (2 * M_PI);
    while (angle >= 2 * M_PI)
        angle -= (2 * M_PI);
    return angle;
}

void draw_floor_ceiling(t_data *data, int x, int top_pixel, int bottom_pixel)
{
    int i;

    // Draw the ceiling (above the wall)
    i = 0;
    while (i < top_pixel)
        my_mlx_pixel_put(data, x, i++, data->map->ceiling_color);

    // Draw the floor (below the wall)
    i = bottom_pixel;
    while (i < RES_Y)
        my_mlx_pixel_put(data, x, i++, data->map->floor_color);
}

int get_color(t_data *data, int flag)
{
    data->ray->rayAngle = nor_angle(data->ray->rayAngle); // Normalize the angle

    if (flag == 0) // Horizontal walls (North/South)
    {
        if (data->ray->rayAngle > M_PI / 2 && data->ray->rayAngle < 3 * (M_PI / 2))
            return (0xB5B5B5FF); // West wall
        else
            return (0xF5F5F5FF); // East wall
    }
    else // Vertical walls (East/West)
    {
        if (data->ray->rayAngle > 0 && data->ray->rayAngle < M_PI)
            return (0xFFAAAAFF); // South wall
        else
            return (0xAAAAFFFF); // North wall
    }
}

void draw_wall(t_data *data, int x, int top_pixel, int bottom_pixel)
{
    int color;

    color = get_color(data, data->ray->side);
    while (top_pixel < bottom_pixel)
        my_mlx_pixel_put(data, x, top_pixel++, color);
}

void render_wall(t_data *data, int x)
{
    double wall_height;
    double bottom_pixel;
    double top_pixel;

    // Fix the fisheye distortion
    double corrected_dist = data->ray->perpWallDist * cos(data->ray->rayAngle - data->player->angel);
    if (corrected_dist <= 0.1) // Prevent division by zero
        corrected_dist = 0.1;

    // Calculate the wall height
    wall_height = (TILE_SIZE / corrected_dist) * ((double)RES_Y / (2 * tan(FOV / 2)));

    // Determine where the wall starts and ends on the screen
    bottom_pixel = (RES_Y / 2) + (wall_height / 2);
    top_pixel = (RES_Y / 2) - (wall_height / 2);

    // Clamp values to ensure they stay within screen boundaries
    if (bottom_pixel > RES_Y)
        bottom_pixel = RES_Y;
    if (top_pixel < 0)
        top_pixel = 0;

    // Draw the wall
    draw_wall(data, x, (int)top_pixel, (int)bottom_pixel);

    // Draw the floor and ceiling only if the wall does not cover the entire height
    if (top_pixel > 0 || bottom_pixel < RES_Y)
    {
        draw_floor_ceiling(data, x, (int)top_pixel, (int)bottom_pixel);
    }
}
