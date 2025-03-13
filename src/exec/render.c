/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:48:31 by maba              #+#    #+#             */
/*   Updated: 2025/03/13 15:55:11 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	if (x < 0 || x >= RES_X || y < 0 || y >= RES_Y)
		return;
	mlx_put_pixel(data->win, x, y, color);
}

float	nor_angle(float angle)
{
	while (angle < 0)
		angle += (2 * M_PI);
	while (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void draw_floor_ceiling(t_data *data, int x, int top_pixel, int bottom_pixel)
{
    int i;

    i = bottom_pixel;
    while (i < RES_Y)
        my_mlx_pixel_put(data, x, i++, data->map->floor_color);
    i = 0;
    while (i < top_pixel)
        my_mlx_pixel_put(data, x, i++, data->map->ceiling_color);
    printf("Drawing floor and ceiling at x: %d, top_pixel: %d, bottom_pixel: %d\n", x, top_pixel, bottom_pixel);
}
int get_color(t_data *data, int flag)
{
    (void)data;
    if (flag == 0) // Mur horizontal (Nord/Sud)
        return (0xFF0000FF); // Rouge
    else // Mur vertical (Est/Ouest)
        return (0x0000FFFF); // Bleu
}
void draw_wall(t_data *data, int x, int top_pixel, int bottom_pixel)
{
    int color;

    color = get_color(data, data->ray->side);
    printf("Drawing wall at x: %d, top_pixel: %d, bottom_pixel: %d, color: %d\n", x, top_pixel, bottom_pixel, color);
    while (top_pixel < bottom_pixel)
        my_mlx_pixel_put(data, x, top_pixel++, color);
}

void render_wall(t_data *data, int x)
{
    double wall_height;
    double bottom_pixel;
    double top_pixel;
    double corrected_dist;

    // Correction de la distorsion du fish-eye
    corrected_dist = data->ray->perpWallDist * cos(data->player->angel - data->ray->rayDirX);
    if (corrected_dist <= 0.01) // Évite les murs infinis
        corrected_dist = 0.1;

    // Calculer la hauteur du mur
    wall_height = (TILE_SIZE / corrected_dist) * ((RES_X / 2) / tan(FOV / 2));
    bottom_pixel = (RES_Y / 2) + (wall_height / 2);
    top_pixel = (RES_Y / 2) - (wall_height / 2);

    // Limiter la hauteur du mur à la taille de l'écran
    if (bottom_pixel > RES_Y)
        bottom_pixel = RES_Y;
    if (top_pixel < 0)
        top_pixel = 0;

    printf("Rendering wall at x: %d, top_pixel: %f, bottom_pixel: %f\n", x, top_pixel, bottom_pixel);
    draw_wall(data, x, top_pixel, bottom_pixel);
    draw_floor_ceiling(data, x, top_pixel, bottom_pixel);
}
