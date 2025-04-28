/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:18:24 by stalash           #+#    #+#             */
/*   Updated: 2025/04/07 22:33:06 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	is_valid_map_char(char c)
{
	return (c == ' ' || c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == '\n');
}

int	refrctoring_map_data(t_data data, char *map_colors)
{
	int		i;
	int		j;
	char	current_char;

	i = 0;
	j = 0;
	if (data.map->m_h >= MAP_HEIGHT)
		return (printf(RED"map exceeds the max height\n"RESET), 1);
	while (map_colors[i] != '\0' && j < MAP_WIDE)
	{
		current_char = map_colors[i];
		if (map_colors[i] == '\n')
			return (1);
		if (map_colors[i] == ' ')
			data.map->map_cub[data.map->m_h][j] = '1';
		else if (is_valid_map_char(current_char))
			data.map->map_cub[data.map->m_h][j] = current_char;
		else
			return (printf(RED"Invalid char in the map\n"RESET), 1);
		i++;
		j++;
	}
	data.map->map_cub[data.map->m_h][j] = '\0';
	return (0);
}

int	retrieve_map_data(int fd, t_data data, char *map_colors)
{
	char	*map_data;

	if (refrctoring_map_data(data, map_colors) == 1)
		return (free(map_colors), 1);
	free(map_colors);
	while (1)
	{
		++(data.map->m_h);
		map_data = refrctoring_line_for_map(fd);
		if (map_data == NULL)
			break ;
		if (refrctoring_map_data(data, map_data) == 1)
			return (free(map_data), 1);
		free(map_data);
	}
	return (0);
}
