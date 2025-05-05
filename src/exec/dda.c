/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:21:25 by stalash           #+#    #+#             */
/*   Updated: 2025/04/12 22:35:21 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "../../cub3d.h"

void init_delta_dists(t_dda_state *state, t_dda_ray *ray)
{
    state->delta_dist_x = (ray->ray_dir_x == 0) ? 1e30 : fabs(1 / ray->ray_dir_x);
    state->delta_dist_y = (ray->ray_dir_y == 0) ? 1e30 : fabs(1 / ray->ray_dir_y);
}

void state_setup(t_data *data, t_dda_state *state, t_dda_ray *ray)
{
    if (ray->ray_dir_x < 0)
    {
        state->step_x = -1;
        state->side_dist_x = (ray->map_x - (int)data->player->posX) * state->delta_dist_x;
    }
    else
    {
        state->step_x = 1;
        state->side_dist_x = ((int)data->player->posX + 1.0 - ray->map_x) * state->delta_dist_x;
    }
    
    if (ray->ray_dir_y < 0)
    {
        state->step_y = -1;
        state->side_dist_y = (ray->map_y - (int)data->player->posY) * state->delta_dist_y;
    }
    else
    {
        state->step_y = 1;
        state->side_dist_y = ((int)data->player->posY + 1.0 - ray->map_y) * state->delta_dist_y;
    }
}

void perform_dda(t_data *data, t_dda *dda)
{
    while (dda->hit_result->hit == 0)
    {
        if (dda->state->side_dist_x < dda->state->side_dist_y)
        {
            dda->state->side_dist_x += dda->state->delta_dist_x;
            dda->ray->map_x += dda->state->step_x;
            dda->hit_result->side = 0;
        }
        else
        {
            dda->state->side_dist_y += dda->state->delta_dist_y;
            dda->ray->map_y += dda->state->step_y;
            dda->hit_result->side = 1;
        }

        // Check map boundaries
        if (dda->ray->map_x < 0 || dda->ray->map_y < 0 || 
            dda->ray->map_x >= data->map->m_w || 
            dda->ray->map_y >= data->map->m_h)
            break;

        // Check if hit wall
        if (data->map->map_cub[dda->ray->map_y][dda->ray->map_x] == '1')
            dda->hit_result->hit = 1;
    }

    // Calculate perpendicular wall distance to avoid fisheye effect
    if (dda->hit_result->side == 0)
        dda->hit_result->perp_wall_dist = (dda->ray->map_x - data->player->posX + 
            (1 - dda->state->step_x) / 2) / dda->ray->ray_dir_x;
    else
        dda->hit_result->perp_wall_dist = (dda->ray->map_y - data->player->posY + 
            (1 - dda->state->step_y) / 2) / dda->ray->ray_dir_y;
}