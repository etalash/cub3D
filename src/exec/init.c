/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:26:40 by maba              #+#    #+#             */
/*   Updated: 2025/02/14 18:27:40 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void init_data(t_data *data, char *map_file)
{
    data->player = (t_player *)malloc(sizeof(t_player));
    if (!data->player)
        error_exit(data, "Erreur d'allocation mémoire pour t_player");

    // data->map = (t_map *)malloc(sizeof(t_map));
    // if (!data->map)
    //     error_exit(data, "Erreur d'allocation mémoire pour t_map");

    // init_map(data->map);
    load_map(data, map_file);
}

void load_map(t_data *data, char *map_file)
{
    (void)map_file;
    // parsing(map_file, data);

    if (!data->map->nord || !data->map->south || !data->map->east || !data->map->west)
        error_exit(data, "Erreur : textures manquantes dans le fichier .cub");

    // if (data->map->res_w <= 0 || data->map->res_h <= 0)
    //     error_exit(data, "Erreur : résolution invalide dans le fichier .cub");

    if (!data->map->map_cub)
        error_exit(data, "Erreur : carte manquante dans le fichier .cub");

    data->player->x_p = data->map->p_x;
    data->player->y_p = data->map->p_y;
}

void init_mlx(t_data *data)
{
    printf("\n%d\n", data->map->res_h);
	printf("\n%d\n", data->map->res_w);
    data->mlx = mlx_init(data->map->res_w, data->map->res_h, "cub3D", true);
    if (!data->mlx)
        error_exit(data, "Erreur d'initialisation de MLX");

    data->win = mlx_new_image(data->mlx, data->map->res_w, data->map->res_h);
    if (!data->win)
        error_exit(data, "Erreur de création de l'image MLX");

    mlx_image_to_window(data->mlx, data->win, 0, 0);

    // Configurer les hooks
    mlx_key_hook(data->mlx, key_press, data);
    // mlx_mouse_hook(data->mlx, mouse_click, data);
    mlx_close_hook(data->mlx, close_window, data);
    mlx_loop_hook(data->mlx, game_loop, data);
}


void error_exit(t_data *data, char *message)
{
    printf("Erreur : %s\n", message);
    if (data)
        cleanup(data);
    exit(EXIT_FAILURE);
}


void close_window(void *param)
{
    t_data *data = (t_data *)param;
    cleanup(data);
    exit(EXIT_SUCCESS);
}
