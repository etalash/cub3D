/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:17:01 by stalash           #+#    #+#             */
/*   Updated: 2025/02/14 17:58:14 by maba             ###   ########.fr       */
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

    data->map->nord = NULL;
    data->map->south = NULL;
    data->map->east = NULL;
    data->map->west = NULL;
}


void cleanup(t_data *data)
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
