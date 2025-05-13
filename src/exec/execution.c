/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:33:38 by stalash           #+#    #+#             */
/*   Updated: 2025/05/13 23:25:10 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	game_loop(void *pointer)
{
	t_data	*data;

	data = (t_data *)pointer;
	mlx_delete_image(data->mlx, data->win);
	data->win = mlx_new_image(data->mlx, data->map->res_w, data->map->res_h);
	if (!data->win)
		return ;
	hook(data, 0, 0);
	raycast(data);
	mlx_image_to_window(data->mlx, data->win, 0, 0);
}

void exit_error(t_data *data, const char *msg)
{
    ft_printf("Error: %s\n", msg);
    if (data->mlx)
    {
        if (data->win)
            mlx_delete_image(data->mlx, data->win);
        mlx_terminate(data->mlx);
    }
    exit(1);
}


int	init_texture(t_data *dt)
{
	dt->north = mlx_load_png(dt->map->nord);
	if (!dt->north)
		return (ft_printf("Error loading north texture\n"), 1);
	dt->south = mlx_load_png(dt->map->south);
	if (!dt->south)
		return (ft_printf("Error loading south texture\n"), 1);
	dt->east = mlx_load_png(dt->map->east);
	if (!dt->east)
		return (ft_printf("Error loading east texture\n"), 1);
	dt->west = mlx_load_png(dt->map->west);
	if (!dt->west)
		return (ft_printf("Error loading west texture\n"), 1);
	return (0);
}

void	init_ray(t_data *data)
{
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
	{
		printf("Error: Failed to allocate memory for data->ray\n");
		exit(1);
	}
}



static void set_player_view(t_player *player, char direction)
{
    if (direction == 'N')
        player->angle = convert_to_radians(0);    // Nord = 0°
    else if (direction == 'S')
        player->angle = convert_to_radians(180);  // Sud = 180°
    else if (direction == 'E')
        player->angle = convert_to_radians(90);   // Est = 90°
    else if (direction == 'W')
        player->angle = convert_to_radians(270);  // Ouest = 270°
}



void init_player(t_data *data)
{
    // Allocation mémoire pour le joueur
    data->player = malloc(sizeof(t_player));
    if (!data->player)
    {
        printf("Error: Failed to allocate memory for player\n");
        exit(1);
    }
    // Vérification que la position initiale n'est pas dans un mur
    if (data->map->map_cub[data->map->p_y][data->map->p_x] == '1')
    {
        printf("Error: Player starts inside a wall\n");
        exit(1);
    }


   // Position initiale (centre de la case)
    data->player->pos_x = data->map->p_x + 0.5; // Position en cases, pas en pixels
    data->player->pos_y = data->map->p_y + 0.5;
    
    // Initialisation du champ de vision
    data->player->fov_rd = convert_to_radians(FOV_RD);
    
    // Initialisation des mouvements
    data->player->rotation = 0;
    data->player->horizontal = 0;
    data->player->vertical = 0;
    
    // Définition de l'angle de vue initial en fonction de l'orientation
    set_player_view(data->player, data->map->p_p);
    
    // Initialisation du raycasting
    init_ray(data);
}



void execution(t_data *data)
{
    data->mlx = mlx_init(data->map->res_w, data->map->res_h, "Cub3D", false);
    if (!data->mlx)
        exit_error(data, "MLX initialization failed");

    // Création de l'image principale (une seule fois)
    data->win = mlx_new_image(data->mlx, data->map->res_w, data->map->res_h);
    if (!data->win)
    {
        mlx_terminate(data->mlx);
        exit_error(data, "Image creation failed");
    }

    // Affichage de l'image (une seule fois)
    if (mlx_image_to_window(data->mlx, data->win, 0, 0) < 0)
    {
        mlx_delete_image(data->mlx, data->win);
        mlx_terminate(data->mlx);
        exit_error(data, "Failed to display image");
    }

    if (init_texture(data))
    {
        mlx_delete_image(data->mlx, data->win);
        mlx_terminate(data->mlx);
        exit_error(data, "Texture loading failed");
    }

    init_player(data);

    mlx_key_hook(data->mlx, key_hook, data);
    mlx_loop_hook(data->mlx, game_loop, data);
    mlx_loop(data->mlx);
    
    // Nettoyage à la fin seulement
    mlx_delete_image(data->mlx, data->win);
}
