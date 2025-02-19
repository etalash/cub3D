/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:33:38 by stalash           #+#    #+#             */
/*   Updated: 2025/02/19 21:12:51 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


// void	move_player(t_data *data, double move_x, double move_y)
// {
// 	int	p_x;
// 	int	p_y;

// 	p_x = roundf(data->player->x_p + move_x) / 16;
// 	p_y = roundf(data->player->y_p + move_y) / 16;
// 	if (data->map->map_cub[p_y][p_x] != '1')
// 	{
// 		data->player->x_p += move_x;
// 		data->player->y_p += move_y;
// 	}
// }

// void	rotate_player(t_player *ply, int rot)
// {
// 	if (rot == 1)
// 	{
// 		ply->angel += (0.045 * M_PI) / 180;
// 		if (ply->angel > 0.045 * M_PI)
// 			ply->angel -= 0.045 * M_PI;
// 	}
// 	else
// 	{
// 		ply->angel -= (0.045 * M_PI) / 180;
// 		if (ply->angel < 0)
// 			ply->angel += 0.045 * M_PI;
// 	}
// }

// void	hook(t_data *data, double move_x, double move_y)
// {
// 	if (data->player->rotation == 1)
// 		rotate_player(data->player, 1);
// 	if (data->player->rotation == -1)
// 		rotate_player(data->player, -1);
// 	if (data->player->vertical == 1)
// 	{
// 		move_x = -sin(data->player->angel) * 2;
// 		move_y = cos(data->player->angel) * 2;
// 	}
// 	if (data->player->vertical == -1)
// 	{
// 		move_x = sin(data->player->angel) * 2;
// 		move_y = -cos(data->player->angel) * 2;
// 	}
// 	if (data->player->vertical == 2)
// 	{
// 		move_x = -cos(data->player->angel) * 2;
// 		move_y = -sin(data->player->angel) * 2;
// 	}
// 	if (data->player->vertical == -2)
// 	{
// 		move_x = cos(data->player->angel) * 2;
// 		move_y = sin(data->player->angel) * 2;
// 	}
// 	move_player(data, move_x, move_y);
// }

// void	game_loop(void *ptr)
// {
// 	t_data	*data;

// 	data = (t_data *)ptr;
// 	mlx_delete_image(data->mlx, data->win);
// 	data->win = mlx_new_image(data->mlx, data->map->res_w, data->map->res_h);
// 	hook(data, 0, 0);
// 	mlx_image_to_window(data->mlx, data->win, 0, 0);
// }

void	re_init(mlx_key_data_t key_data, t_data *data)
{
	if ((key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS) \
		|| (key_data.key == MLX_KEY_S && key_data.key == MLX_PRESS) \
		|| (key_data.key == MLX_KEY_D && key_data.key == MLX_PRESS) \
		|| (key_data.key == MLX_KEY_A && key_data.key == MLX_PRESS))
		data->player->vertical = 0;
	else if ((key_data.key == MLX_KEY_UP && key_data.key == MLX_PRESS) \
			|| (key_data.key == MLX_KEY_DOWN && key_data.key == MLX_PRESS))
		data->player->rotation = 0;
}

void	key_hook(mlx_key_data_t key_data, void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	else if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
		data->player->vertical = 1;
	else if (key_data.key == MLX_KEY_S && key_data.key == MLX_PRESS)
		data->player->vertical = -1;
	else if (key_data.key == MLX_KEY_D && key_data.key == MLX_PRESS)
		data->player->vertical = 2;
	else if (key_data.key == MLX_KEY_A && key_data.key == MLX_PRESS)
		data->player->vertical = -2;
	else if (key_data.key == MLX_KEY_UP && key_data.key == MLX_PRESS)
		data->player->rotation = 1;
	else if (key_data.key == MLX_KEY_DOWN && key_data.key == MLX_PRESS)
		data->player->rotation = -1;
	re_init(key_data, data);
}

void	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		return(printf("ERROR: can't malloc memory for the player\n"), exit(0));
	data->player->rotation = 0;
	data->player->vertical = 0;
	data->player->radian_FOV = PLAYER_ANGEL * (M_PI / 180);
	data->player->x_p = (data->map->p_x * 16) + (16 / 2); // 16 is the tile of the map could be 32 and 64 as well (it it position the player in the map and the + 16/2 position it in the middle of the tile)
	data->player->y_p = (data->map->p_y * 16) + (16 / 2);
	if (data->map->p_p == 'E')
		data->player->angel = 0;
	else if (data->map->p_p == 'N')
		data->player->angel = M_PI / 2;
	else if (data->map->p_p == 'W')
		data->player->angel = M_PI;
	else if (data->map->p_p == 'S')
		data->player->angel = 3 * (M_PI / 2);
}

void	init_textures(t_data *data)
{
	data->nord = (mlx_texture_t *)data->map->nord;
	data->south = (mlx_texture_t *)data->map->south;
	data->east = (mlx_texture_t *)data->map->east;
	data->west = (mlx_texture_t *)data->map->west;
	data->nord = mlx_load_png("assets/texture/clay.png");
	if (!data->nord)
		return (printf("ERROR: can't init texture\n"), exit(0));
	data->south = mlx_load_png("assets/texture/context_01.png");
	if (!data->south)
		return (printf("ERROR: can't init texture\n"), exit(0));
	data->east = mlx_load_png("assets/texture/brick_wall_09.png");
	if (!data->east)
		return (printf("ERROR: can't init texture\n"), exit(0));
	data->west = mlx_load_png("assets/texture/plaster_brick_pattern.png");
	if (!data->west)
		return (printf("ERROR: can't init texture\n"), exit)(0);

	// data->nord = load_image(data, "assets/texture/clay.png");
	// if (!data->nord)
	// 	return (printf("ERROR: can't init texture\n"), exit(0));
	// data->south = load_image(data, "assets/texture/context_01.png");
	// if (!data->south)
	// 	return (printf("ERROR: can't init texture\n"), exit(0));
	// data->east = load_image(data, "assets/texture/brick_wall_09.png");
	// if (!data->east)
	// 	return (printf("ERROR: can't init texture\n"), exit(0));
	// data->west = load_image(data, "assets/texture/plaster_brick_pattern.png");
	// if (!data->west)
	// 	return (printf("ERROR: can't init texture\n"), exit)(0);
}

void	execution(t_data *data)
{
	data->mlx = mlx_init(data->map->res_w, data->map->res_h, "Cub3D ", 0);
	if (!data->mlx)
	{
		printf("ERROR: can't init mlx\n");
		return ;
	}
	init_textures(data);
	init_player(data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
	deallocate_map(data);
}
