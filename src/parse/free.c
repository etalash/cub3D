/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:17:01 by stalash           #+#    #+#             */
/*   Updated: 2025/05/16 21:21:06 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	deallocate_map(t_data *data)
{
	int	i;

	if (!data->map)
		return ;
	if (data->map->map_cub)
	{
		i = 0;
		while (i < MAP_HEIGHT)
		{
			free(data->map->map_cub[i]);
			i++;
		}
		free(data->map->map_cub);
		data->map->map_cub = NULL;
	}
	free(data->map->north);
	free(data->map->south);
	free(data->map->east);
	free(data->map->west);
	data->map->north = NULL;
	data->map->south = NULL;
	data->map->east = NULL;
	data->map->west = NULL;
}


void	cleanup_mlx_and_textures(t_data *data)
{
	if (data->north)
		mlx_delete_texture(data->north);
	if (data->south)
		mlx_delete_texture(data->south);
	if (data->east)
		mlx_delete_texture(data->east);
	if (data->west)
		mlx_delete_texture(data->west);
	if (data->win)
		mlx_delete_image(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_terminate(data->mlx);
		data->mlx = NULL;
	}
}

void	cleanup(t_data *data)
{
	if (!data)
		return ;
	cleanup_mlx_and_textures(data);
	if (data->player)
	{
		free(data->player);
		data->player = NULL;
	}
	if (data->ray)
	{
		free(data->ray);
		data->ray = NULL;
	}
}

void	free_sub_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < MAP_HEIGHT)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}
