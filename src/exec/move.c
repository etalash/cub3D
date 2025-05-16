/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:15:53 by stalash           #+#    #+#             */
/*   Updated: 2025/05/16 19:40:02 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


void	move_player(t_data *data, double move_x, double move_y)
{
	double	next_x = data->player->pos_x + move_x;
	double	next_y = data->player->pos_y + move_y;

	if (data->map->map_cub[(int)data->player->pos_y][(int)next_x] != '1')
		data->player->pos_x = next_x;
	if (data->map->map_cub[(int)next_y][(int)data->player->pos_x] != '1')
		data->player->pos_y = next_y;
}


void	rotate_player(t_player *player, int rot)
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
    // Réinitialiser les mouvements à chaque frame
    move_x = 0;
    move_y = 0;

    // Rotation
    if (data->player->rotation != 0)
        rotate_player(data->player, data->player->rotation);

    // Mouvements (simplifié pour un déplacement plus droit)
    if (data->player->vertical == 1) { // Avancer
        move_x = cos(data->player->angle) * PLAYER_SPEED;
        move_y = sin(data->player->angle) * PLAYER_SPEED;
    }
    if (data->player->vertical == -1) { // Reculer
        move_x = -cos(data->player->angle) * PLAYER_SPEED;
        move_y = -sin(data->player->angle) * PLAYER_SPEED;
    }
    if (data->player->horizontal == -1) { // Strafe gauche
        move_x = -sin(data->player->angle) * PLAYER_SPEED;
        move_y = cos(data->player->angle) * PLAYER_SPEED;
    }
    if (data->player->horizontal == 1) { // Strafe droite
        move_x = sin(data->player->angle) * PLAYER_SPEED;
        move_y = -cos(data->player->angle) * PLAYER_SPEED;
    }

    move_player(data, move_x, move_y);
}

void	key_release(mlx_key_data_t key_data, t_data *data)
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

void	key_hook(mlx_key_data_t key_data, void *pointer)
{
	t_data	*data;

	data = (t_data *)pointer;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	else if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
		data->player->rotation = 1;
	else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
		data->player->rotation = -1;
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
