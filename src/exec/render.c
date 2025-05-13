/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:48:31 by maba              #+#    #+#             */
/*   Updated: 2025/05/13 23:22:21 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


//  Define texture pixel 

int	get_pixel(mlx_texture_t *texture, int x, int y)
{
	int	index;
	int	pixel;

	if (!texture || x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
		return (0);
	index = (y * texture->width + x) * 4;
	pixel = (texture->pixels[index + 0] << 24) \
			| (texture->pixels[index + 1] << 16) \
			| (texture->pixels[index + 2] << 8) \
			| (texture->pixels[index + 3]);
	return (pixel);
}


//  Define wall textures

void	define_texture_values(t_data *data, t_ray *ray, \
							mlx_texture_t **texture, double *wall_x)
{
	// printf("Wall X: %f\n", *wall_x);
	if (ray->wall == NORTH)
		*texture = data->north;
	else if (ray->wall == SOUTH)
		*texture = data->south;
	else if (ray->wall == EAST)
		*texture = data->east;
	else if (ray->wall == WEST)
		*texture = data->west;
	// printf("Perp Wall Dist: %f, Dir X: %f, Dir Y: %f\n", ray->perp_wall_dist, ray->dir_x, ray->dir_y);
	if (ray->side == VERTICAL)
		*wall_x = data->player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		*wall_x = data->player->pos_x + ray->perp_wall_dist * ray->dir_x;
	
	*wall_x -= floor(*wall_x);
}


// Draw wall textures

void	draw_walls(t_data *data, t_ray *ray, int x)
{
	t_point_int		tex;
	double			wall_x;
	double			step;
	double			tex_pos;
	mlx_texture_t	*texture;
	int				y;

	wall_x = 0.0;
	texture = NULL;
	define_texture_values(data, ray, &texture, &wall_x);
	
	// Vérification si la texture est NULL
    if (!texture)
    {
        fprintf(stderr, "Error: Texture is NULL\n");
        return;
    }
	tex.x = (int)(wall_x * texture->width);
	if (tex.x < 0)
    	tex.x = 0;
	else if (tex.x >= (int)texture->width)
    	tex.x = (int)texture->width - 1;
	// printf("Tex X: %d, Texture Width: %d\n", tex.x, texture->width);

	if ((ray->side == VERTICAL && ray->dir_x < 0)
		|| (ray->side == HORIZONTAL && ray->dir_y > 0))
		tex.x = texture->width - tex.x - 1;
	
	
	step = (double)texture->height / ray->line_height;
	tex_pos = (ray->draw_start - RES_Y / 2 + ray->line_height / 2) * step;
	
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex.y = (int)tex_pos;
		if (tex.y >= (int)texture->height)
			tex.y = (int)texture->height - 1;
		tex_pos += step;
		mlx_put_pixel(data->win, x, y, get_pixel(texture, tex.x, tex.y));
		// printf("y: %d, tex.y: %d, tex_pos: %f, step: %f\n", y, tex.y, tex_pos, step);
		y++;
	}
}


void draw_ceiling_floor(t_data *data, t_ray *ray, int x)
{
    uint32_t y;
    const uint32_t width = data->win->width;
    const uint32_t height = data->win->height;
    
    if (!data->win || x < 0 || (uint32_t)x >= width)
        return;

    y = 0;
    while (y < (uint32_t)ray->draw_start && y < height)
    {
        mlx_put_pixel(data->win, x, y, data->map->ceiling_color);
        y++;
    }
    
    y = ray->draw_end;
    while (y < height)
    {
        mlx_put_pixel(data->win, x, y, data->map->floor_color);
        y++;
    }
}


// Render game 

void	rendering(t_data *data, t_ray *ray, int x)
{
	if (ray->line_height > RES_Y)
    	ray->line_height = RES_Y;
	
	ray->line_height = (int)(RES_Y / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + RES_Y / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + RES_Y / 2;
	if (ray->draw_end >= RES_Y)
		ray->draw_end = RES_Y - 1;
	// printf("Line Height: %d, Draw Start: %d, Draw End: %d\n", ray->line_height, ray->draw_start, ray->draw_end);
	draw_ceiling_floor(data, ray, x);
	draw_walls(data, ray, x);
}
