/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:17:01 by stalash           #+#    #+#             */
/*   Updated: 2025/02/12 10:42:37 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
    int i;

    if (data->map->map_cub)
    {
        for (i = 0; i < MAP_HEIGHT; i++)
        {
            if (data->map->map_cub[i])
            {
                free(data->map->map_cub[i]);
                data->map->map_cub[i] = NULL;
            }
        }
        free(data->map->map_cub);
        data->map->map_cub = NULL;
    }

    if (data->map->nord)
    {
        free(data->map->nord);
        data->map->nord = NULL;
    }
    if (data->map->south)
    {
        free(data->map->south);
        data->map->south = NULL;
    }
    if (data->map->east)
    {
        free(data->map->east);
        data->map->east = NULL;
    }
    if (data->map->west)
    {
        free(data->map->west);
        data->map->west = NULL;
    }
}

