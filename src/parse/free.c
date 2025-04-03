/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:17:01 by stalash           #+#    #+#             */
/*   Updated: 2025/04/03 05:45:29 by maba             ###   ########.fr       */
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
	free(data->map->nord);
	free(data->map->south);
	free(data->map->east);
	free(data->map->west);
	free(data->ray);
	data->ray = NULL;
	data->map->nord = NULL;
	data->map->south = NULL;
	data->map->east = NULL;
	data->map->west = NULL;
}

void	cleanup(t_data *data)
{
	if (data->player)
		free(data->player);
	if (data->map)
	{
		deallocate_map(data);
		free(data->map);
	}
	if (data->mlx && data->win)
		mlx_delete_image(data->mlx, data->win);
	if (data->mlx)
		mlx_terminate(data->mlx);
}

void	free_sub_map(char **map)
{
	int	i;

	i = 0;
	while (map[i][0])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}
