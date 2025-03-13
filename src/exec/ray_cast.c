/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:00:24 by maba              #+#    #+#             */
/*   Updated: 2025/03/13 15:55:25 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int unit_circle(float angle, char c) // Vérifie dans quel quadrant est l'angle
{
    if (c == 'x')
    {
        if (angle > 0 && angle < M_PI)
            return (1);
    }
    else if (c == 'y')
    {
        if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
            return (1);
    }
    return (0);
}

int inter_check(float angle, float *inter, float *step, int is_horizon)
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

int wall_hit(float x, float y, t_map *map)
{
    int x_m = floor(x / TILE_SIZE);
    int y_m = floor(y / TILE_SIZE);
    
    if (x < 0 || y < 0 || y_m >= map->m_h || x_m >= map->m_w)
        return (0); // Considérer comme un mur si hors limites

    if (!map->map_cub[y_m] || x_m >= (int)strlen(map->map_cub[y_m]))
        return (0);

    return (map->map_cub[y_m][x_m] == '1' ? 0 : 1);
}


float get_h_inter(t_data *data, float angle)
{
    float h_x, h_y, x_step, y_step;
    int pixel, max_steps = 1000;  // Protection anti-boucle infinie
    
    y_step = TILE_SIZE;
    x_step = TILE_SIZE / tan(angle);
    h_y = floor(data->player->y_p / TILE_SIZE) * TILE_SIZE;
    pixel = inter_check(angle, &h_y, &y_step, 1);
    h_x = data->player->x_p + (h_y - data->player->y_p) / tan(angle);

    if ((unit_circle(angle, 'y') && x_step > 0) || (!unit_circle(angle, 'y') && x_step < 0))
        x_step *= -1;

    while (wall_hit(h_x, h_y - pixel, data->map) && max_steps-- > 0)
    {
        h_x += x_step;
        h_y += y_step;
    }

    if (max_steps <= 0)
    {
        fprintf(stderr, "Error: Infinite loop detected in get_h_inter()\n");
        exit(1);
    }

    return sqrt(pow(h_x - data->player->x_p, 2) + pow(h_y - data->player->y_p, 2));
}

float get_v_inter(t_data *data, float angle)
{
    float v_x, v_y, x_step, y_step;
    int pixel, max_steps = 1000;  // Protection anti-boucle infinie
    
    x_step = TILE_SIZE;
    y_step = TILE_SIZE * tan(angle);
    v_x = floor(data->player->x_p / TILE_SIZE) * TILE_SIZE;
    pixel = inter_check(angle, &v_x, &x_step, 0);
    v_y = data->player->y_p + (v_x - data->player->x_p) * tan(angle);

    if ((unit_circle(angle, 'x') && y_step < 0) || (!unit_circle(angle, 'x') && y_step > 0))
        y_step *= -1;

    while (wall_hit(v_x - pixel, v_y, data->map) && max_steps-- > 0)
    {
        v_x += x_step;
        v_y += y_step;
    }

    if (max_steps <= 0)
    {
        fprintf(stderr, "Error: Infinite loop detected in get_v_inter()\n");
        exit(1);
    }

    return sqrt(pow(v_x - data->player->x_p, 2) + pow(v_y - data->player->y_p, 2));
}

void	raycast(t_data *data)
{
    if (!data->ray)
    {
        fprintf(stderr, "Error: data->ray is NULL in raycast()\n");
        exit(1);
    }

    float h_inter, v_inter;
    int ray = 0;
    float ray_angle = data->player->angel - (FOV / 2);
    
    while (ray < RES_X)
    {
        data->ray->hit = 0;
        data->ray->rayDirX = cos(ray_angle);
        data->ray->rayDirY = sin(ray_angle);
        
        h_inter = get_h_inter(data, ray_angle);
        v_inter = get_v_inter(data, ray_angle);

        if (v_inter <= h_inter)
        {
            data->ray->perpWallDist = v_inter;
            data->ray->side = 0;
        }
        else
        {
            data->ray->perpWallDist = h_inter;
            data->ray->side = 1;
        }

        if (data->ray->perpWallDist <= 0)
        {
            fprintf(stderr, "Error: Invalid wall distance (%f)\n", data->ray->perpWallDist);
            exit(1);
        }

        render_wall(data, ray);
        ray++;
        ray_angle += (FOV / RES_X);
    }
}
