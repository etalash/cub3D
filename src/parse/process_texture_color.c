/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_texture_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:29:41 by stalash           #+#    #+#             */
/*   Updated: 2025/04/03 06:00:59 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	count_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (ft_strlen(tokens[i]) != 3)
			return (1);
		i++;
	}
	return (0);
}

uint32_t	set_color(char *line)
{
	char	**tokens;
	int		red;
	int		green;
	int		blue;

	tokens = ft_split(line, ',');
	if (!tokens)
		return (-1);
	if (count_tokens(tokens) == 1)
		return (free_tokens(tokens), -1);
	if (ft_isnumber(tokens[0]) || ft_isnumber(tokens[1])
		|| ft_isnumber(tokens[2]))
		return (free_tokens(tokens), -1);
	red = ft_atoi(tokens[0]);
	green = ft_atoi(tokens[1]);
	blue = ft_atoi(tokens[2]);
	free_tokens(tokens);
	if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0
		|| blue > 255)
		return (-1);
	return ((red << 16) | (green << 8) | blue);
}

int	process_color_line(char *line, t_data data, int *found)
{
	if ((strncmp(line, "F ", 2) == 0) && !found[4])
	{
		data.map->floor_color = set_color(line + 2);
		found[4] = 1;
		return (0);
	}
	if ((strncmp(line, "C ", 2) == 0) && !found[5])
	{
		data.map->ceiling_color = set_color(line + 2);
		found[5] = 1;
		return (0);
	}
	return (-1);
}

int	process_texture_line(char *line, t_data data, int *found)
{
	if ((strncmp(line, "NO ", 3) == 0) && !found[0])
	{
		data.map->nord = ft_strdup(line + 3);
		found[0] = 1;
		return (0);
	}
	if ((strncmp(line, "SO ", 3) == 0) && !found[1])
	{
		data.map->south = ft_strdup(line + 3);
		found[1] = 1;
		return (0);
	}
	if ((strncmp(line, "EA ", 3) == 0) && !found[2])
	{
		data.map->east = ft_strdup(line + 3);
		found[2] = 1;
		return (0);
	}
	if ((strncmp(line, "WE ", 3) == 0) && !found[3])
	{
		data.map->west = ft_strdup(line + 3);
		found[3] = 1;
		return (0);
	}
	return (-1);
}

int	process_map_line(char *line, t_data data)
{
	static int	result[6] = {0};

	if (line[0] == '1')
		return (1);
	if (process_texture_line(line, data, result) == 0)
		return (0);
	if (process_color_line(line, data, result) == 0)
		return (0);
	printf("ERROR : Invalid texture path or color format.\n");
	return (free(line), -1);
}
