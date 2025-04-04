/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:15:53 by stalash           #+#    #+#             */
/*   Updated: 2025/04/02 22:48:44 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void move_player(t_data *data, double move_x, double move_y)
{
    int p_x;
    int p_y;

    p_x = roundf(data->player->posX + move_x) / TILE_SIZE;
    p_y = roundf(data->player->posY + move_y) / TILE_SIZE;
    if (data->map->map_cub[p_y][p_x] != '1')
    {
        data->player->posX += move_x;
        data->player->posY += move_y;
    }
}

void rotate_player(t_player *player, int rot)
{
    if (rot == 1)
    {
        player->angle += (ROTATION_SPEED * M_PI) / 180;
        if (player->angle > 2 * M_PI)
            player->angle -= 2 * M_PI;
    }
    else
    {
        player->angle -= (ROTATION_SPEED * M_PI) / 180;
        if (player->angle < 0)
            player->angle += 2 * M_PI;
    }
}

void hook(t_data *data, double move_x, double move_y)
{
    if (data->player->rotation == 1)
        rotate_player(data->player, 1);
    if (data->player->rotation == -1)
        rotate_player(data->player, -1);
    if (data->player->horizontal == 1)
    {
        move_x = -sin(data->player->angle) * PLAYER_SPEED;
        move_y = cos(data->player->angle) * PLAYER_SPEED;
    }
    if (data->player->horizontal == -1)
    {
        move_x = sin(data->player->angle) * PLAYER_SPEED;
        move_y = -cos(data->player->angle) * PLAYER_SPEED;
    }
    if (data->player->vertical == 1)
    {
        move_x = cos(data->player->angle) * PLAYER_SPEED;
        move_y = sin(data->player->angle) * PLAYER_SPEED;
    }
    if (data->player->vertical == -1)
    {
        move_x = -cos(data->player->angle) * PLAYER_SPEED;
        move_y = -sin(data->player->angle) * PLAYER_SPEED;
    }
    move_player(data, move_x, move_y);
}

void key_release(mlx_key_data_t key_data, t_data *data)
{
    if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_RELEASE)
        data->player->rotation = 0;
    else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_RELEASE)
        data->player->rotation = 0;
    else if (key_data.key == MLX_KEY_D && key_data.action == MLX_RELEASE)
        data->player->horizontal = 0;
    else if (key_data.key == MLX_KEY_A && key_data.action == MLX_RELEASE)
        data->player->horizontal = 0;
    else if (key_data.key == MLX_KEY_W && key_data.action == MLX_RELEASE)
        data->player->vertical = 0;
    else if (key_data.key == MLX_KEY_S && key_data.action == MLX_RELEASE)
        data->player->vertical = 0;
}

void key_hook(mlx_key_data_t key_data, void *pointer)
{
    t_data *data;

    data = (t_data *)pointer;
    if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
        mlx_close_window(data->mlx);
    else if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
        data->player->rotation = -1;
    else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
        data->player->rotation = 1;
    else if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
        data->player->horizontal = -1;
    else if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS)
        data->player->horizontal = 1;
    else if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
        data->player->vertical = 1;
    else if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
        data->player->vertical = -1;
    key_release(key_data, data);
}