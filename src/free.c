/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:17:01 by stalash           #+#    #+#             */
/*   Updated: 2025/01/31 13:39:06 by stalash          ###   ########.fr       */
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

void	deallocate_map(t_data data)
{
	int	i;

	i = 0;
	if (data.map->map_cub[i])
	{
		while (i < MAP_HEIGHT)
		{
			if (data.map->map_cub[i])
			{
				free(data.map->map_cub[i]);
				data.map->map_cub[i] = NULL;
			}
			i++;
		}
		free(data.map->map_cub);
	}
}
