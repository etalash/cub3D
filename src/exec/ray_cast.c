/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:00:24 by maba              #+#    #+#             */
/*   Updated: 2025/03/04 15:47:07 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Function to advance the ray until it hits a wall
void add_until_wall(t_ray *ray, t_map *map)
{
    while (true)
    {
        if (ray->sideDistX < ray->sideDistY)
        {
            ray->sideDistX += ray->deltaDistX;
            ray->mapX += ray->stepX;
            ray->side = 0;
        }
        else
        {
            ray->sideDistY += ray->deltaDistY;
            ray->mapY += ray->stepY;
            ray->side = 1;
        }
        if (ray->mapX < 0 || ray->mapY < 0 || ray->mapX >= map->m_w || ray->mapY >= map->m_h || map->map_cub[ray->mapY][ray->mapX] == '1')
            break;
    }
}

// // Function to cast a ray and calculate the distance to the wall
float cast_ray(t_data *data, int x, float ray_angle)
{
    t_ray ray;
    t_player *player = data->player;
    t_map *map = data->map;

    ray.cameraX = 2 * x / (float)data->map->res_w - 1;
    ray.rayDirX = player->dirX * cos(ray_angle) - player->dirY * sin(ray_angle);
    ray.rayDirY = player->dirX * sin(ray_angle) + player->dirY * cos(ray_angle);

    ray.mapX = (int)player->posX;
    ray.mapY = (int)player->posY;

    ray.deltaDistX = fabs(1 / ray.rayDirX);
    ray.deltaDistY = fabs(1 / ray.rayDirY);

    if (ray.rayDirX < 0)
    {
        ray.stepX = -1;
        ray.sideDistX = (player->posX - ray.mapX) * ray.deltaDistX;
    }
    else
    {
        ray.stepX = 1;
        ray.sideDistX = (ray.mapX + 1.0 - player->posX) * ray.deltaDistX;
    }

    if (ray.rayDirY < 0)
    {
        ray.stepY = -1;
        ray.sideDistY = (player->posY - ray.mapY) * ray.deltaDistY;
    }
    else
    {
        ray.stepY = 1;
        ray.sideDistY = (ray.mapY + 1.0 - player->posY) * ray.deltaDistY;
    }

    add_until_wall(&ray, map);

    if (ray.side == 0)
        ray.perpWallDist = (ray.mapX - player->posX + (1 - ray.stepX) / 2) / ray.rayDirX;
    else
        ray.perpWallDist = (ray.mapY - player->posY + (1 - ray.stepY) / 2) / ray.rayDirY;

    // Debugging output
    // printf("Ray %d: angle=%.2f, posX=%.2f, posY=%.2f, dirX=%.2f, dirY=%.2f, perpWallDist=%.2f\n",
    //        x, ray_angle, player->posX, player->posY, ray.rayDirX, ray.rayDirY, ray.perpWallDist);

    return ray.perpWallDist;
}


void draw_wall(t_data *data, int x, float distance, float ray_angle)
{
    int wall_height;
    int draw_start;
    int draw_end;
    int y;

    // Correction de la distorsion du fish-eye
    float corrected_distance = distance * cos(ray_angle - data->player->angle);

    wall_height = (int)(data->map->res_h / corrected_distance);
    draw_start = -wall_height / 2 + data->map->res_h / 2;
    draw_end = wall_height / 2 + data->map->res_h / 2;

    // Ensure draw_start and draw_end are within screen bounds
    if (draw_start < 0) draw_start = 0;
    if (draw_end >= data->map->res_h) draw_end = data->map->res_h - 1;

    // Draw the wall
    for (y = 0; y < data->map->res_h; y++)
    {
        if (y >= draw_start && y <= draw_end)
            mlx_put_pixel(data->win, x, y, 0x000000); // Black color for walls
        else if (y < draw_start)
            mlx_put_pixel(data->win, x, y, 0x808080); // Gray color for ceiling
        else
            mlx_put_pixel(data->win, x, y, 0xFFFFFF); // White color for floor
    }
}

// Main function to cast rays and draw walls
void raycast(t_data *data)
{
    float ray_angle;
    float angle_increment;
    int x;

    x = 0;
    ray_angle = data->player->angle - FOV / 2;
    angle_increment = FOV / NUM_RAYS;

    // Cast the rays
    while (x < NUM_RAYS)
    {
        float distance = cast_ray(data, x, ray_angle);

        draw_wall(data, x, distance, ray_angle);

        ray_angle += angle_increment;
        x++;
    }
}