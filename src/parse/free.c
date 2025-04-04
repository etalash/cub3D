/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:17:01 by stalash           #+#    #+#             */
/*   Updated: 2025/04/02 22:58:52 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void free_tokens(char **tokens)
{
	int i;

	i = 0;
	while (i < 3)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void deallocate_map(t_data *data)
{
	if (!data->map)
		return;

	if (data->map->map_cub)
	{
		for (int i = 0; i < MAP_HEIGHT; i++)
		{
			free(data->map->map_cub[i]);
		}
		free(data->map->map_cub);
		data->map->map_cub = NULL;
	}

	free(data->map->nord);
	free(data->map->south);
	free(data->map->east);
	free(data->map->west);
	// free(data->ray);
	// data->ray = NULL;


	data->map->nord = NULL;
	data->map->south = NULL;
	data->map->east = NULL;
	data->map->west = NULL;
}

void cleanup(t_data *data)
{
    if (!data)
        return;
        
    // Clean up textures
    if (data->north)
        mlx_delete_texture(data->north);
    if (data->south) 
        mlx_delete_texture(data->south);
    if (data->east)
        mlx_delete_texture(data->east);
    if (data->west)
        mlx_delete_texture(data->west);
    // if (data->text)
    //     mlx_delete_texture(data->text);

    // Clean up window/image
    if (data->win)
        mlx_delete_image(data->mlx, data->win);

    // Clean up MLX
    if (data->mlx)
    {
        mlx_terminate(data->mlx);
        data->mlx = NULL;
    }

    // Clean up player
    if (data->player)
    {
        free(data->player);
        data->player = NULL;
    }

    // Clean up ray
    if (data->ray)
    {
        free(data->ray);
        data->ray = NULL;
    }
}

void free_sub_map(char **map)
{
    int i;

    if (!map)
        return;
        
    for (i = 0; i < MAP_HEIGHT; i++)
    {
        if (map[i])
            free(map[i]);
    }
    free(map);
}