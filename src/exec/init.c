/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:26:40 by maba              #+#    #+#             */
/*   Updated: 2025/02/19 21:08:03 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// // // void init_data(t_data *data)
// // // {
// // // 	data->player = (t_player *)malloc(sizeof(t_player));
// // // 	if (!data->player)
// // // 		error_exit(data, "Erreur d'allocation mémoire pour t_player");
// // // 	load_map(data);
// // // }

// // // void load_map(t_data *data)
// // // {

// // // 	if (!data->map->nord || !data->map->south || !data->map->east || !data->map->west)
// // // 		error_exit(data, "Erreur : textures manquantes dans le fichier .cub");
// // // 	if (data->map->res_w <= 0 || data->map->res_h <= 0)
// // // 	    error_exit(data, "Erreur : résolution invalide dans le fichier .cub");
// // // 	if (!data->map->map_cub)
// // // 		error_exit(data, "Erreur : carte manquante dans le fichier .cub");

// // // 	data->player->x_p = data->map->p_x;
// // // 	data->player->y_p = data->map->p_y;
// // // }

// // void	*load_image(t_data *data, char *str)
// // {
// // 	mlx_texture_t	*texture;
// // 	mlx_image_t		*image;

// // 	texture = mlx_load_png(str);
// // 	image = mlx_texture_to_image(data->mlx, texture);
// // 	mlx_delete_texture(texture);
// // 	return (image);
// // }

// // void	display_background(t_data *data)
// // {
// // 	int i = 0;
// // 	int j  = 0;

// // 	data->image.background = load_image(data, "assets/texture/context_01.png");
// // 	while (data->map->map_cub[i][j])
// // 	{
// // 		j = 0;
// // 		while (data->map->map_cub[i][j])
// // 		{
// // 			if (data->map->map_cub[i][j])
// // 			{
// // 				printf("WE ARE HERE \n");
// // 				mlx_image_to_window(data->mlx, data->image.background, \
// // 									SIZE_OF_IMAGE * j, SIZE_OF_IMAGE * i);
// // 			}
// // 			j++;
// // 		}
// // 		i++;
// // 	}
// // }

// // void init_mlx(t_data *data)
// // {
// // 	mlx_set_setting(MLX_STRETCH_IMAGE, true);
// // 	data->mlx = mlx_init(data->map->res_w, data->map->res_h, "cub3D", true);
// // 	if (!data->mlx)
// // 		error_exit(data, "Erreur d'initialisation de MLX");
// // 	display_background(data);
// // 	// data->win = mlx_new_image(data->mlx, data->map->res_w, data->map->res_h);
// // 	// if (!data->win)
// // 	// 	error_exit(data, "Erreur de création de l'image MLX");

// // 	mlx_image_to_window(data->mlx, data->win, data->map->ceiling_color, data->map->floor_color);


// // 	// Configurer les hooks
// // 	mlx_key_hook(data->mlx, key_press, data);
// // 	// mlx_mouse_hook(data->mlx, mouse_click, data);
// // 	mlx_close_hook(data->mlx, close_window, data);
// // 	mlx_loop_hook(data->mlx, game_loop, data);
// // }

// // void error_exit(t_data *data, char *message)
// // {
// // 	printf("Erreur : %s\n", message);
// // 	if (data)
// // 		cleanup(data);
// // 	exit(EXIT_FAILURE);
// // }

// // void close_window(void *param)
// // {
// // 	t_data *data = (t_data *)param;
// // 	cleanup(data);
// // 	exit(EXIT_SUCCESS);
// // }


// void	*load_image(t_data *data, char *str)
// {
// 	mlx_texture_t	*texture;
// 	mlx_image_t		*image;

// 	texture = mlx_load_png(str);
// 	image = mlx_texture_to_image(data->mlx, texture);
// 	mlx_delete_texture(texture);
// 	return (image);
// }

// void	display_background(t_data *data)
// {
// 	int i = 0;
// 	int j  = 0;

// 	data->image.background = load_image(data, "assets/texture/brick_wall_09.png");
// 	while (data->map->map_cub[i])
// 	{
// 		j = 0;
// 		while (data->map->map_cub[i][j])
// 		{
// 			if (data->map->map_cub[i][j])
// 				mlx_image_to_window(data->mlx, data->image.background, \
// 									SIZE_OF_IMAGE * j, SIZE_OF_IMAGE * i);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	display_wall(t_data *data)
// {
// 	int i = 0;
// 	int j  = 0;

// 	data->image.wall = load_image(data, "assets/texture/wall.png");
// 	while (data->map->map_cub[i])
// 	{
// 		j = 0;
// 		while (data->map->map_cub[i][j])
// 		{
// 			if (data->map->map_cub[i][j] == '1')
// 				mlx_image_to_window(data->mlx, data->image.wall, \
// 									SIZE_OF_IMAGE * j, SIZE_OF_IMAGE * i);
// 			j++;
// 		}
// 		i++;
// 	}
// }


// // void	move_image(t_data *data, int x, int y)
// // {
// // 	if (y != 0)
// // 	{
// // 		data->map->p_y += y;
// // 		data->image.player->instances[0].y += (SIZE_OF_IMAGE * y);
// // 	}
// // 	else
// // 	{
// // 		data->map->p_x += x;
// // 		data->image.player->instances[0].x += (SIZE_OF_IMAGE * x);
// // 	}
// // 	data->map->move ++;
// // }


// // void	key_hook(mlx_key_data_t key_data, void *param)
// // {
// // 	t_data	*data;

// // 	data = (t_data *)param;
// // 	if (!data)
// // 		return ;
// // 	if (key_data.key == MLX_KEY_D && key_data.action == \
// // 		MLX_PRESS)
// // 		move(data, 1, 0);
// // 	else if (key_data.key == MLX_KEY_A && key_data.action == \
// // 		MLX_PRESS)
// // 		move(data, -1, 0);
// // 	else if (key_data.key == MLX_KEY_W && key_data.action == \
// // 		MLX_PRESS)
// // 		move(data, 0, -1);
// // 	else if (key_data.key == MLX_KEY_S && key_data.action == \
// // 		MLX_PRESS)
// // 		move(data, 0, 1);
// // 	else if (key_data.key == MLX_KEY_ESCAPE)
// // 		mlx_close_window(data->mlx);
// // }
