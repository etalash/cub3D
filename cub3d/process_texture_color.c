/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_texture_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:29:41 by stalash           #+#    #+#             */
/*   Updated: 2025/01/16 17:46:36 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

unsigned int	set_color(char *line)
{
	char	**tokens;
	int		i;
	int		red;
	int		green;
	int		bule;

	i = 0;
	tokens = ft_split(line, ',');
	if (!tokens)
	return(free(tokens), -1);
	if (count_tokens(tokens) == 1)
		return(free(tokens), -1);
	if (!ft_isnumber(tokens[0]) || !ft_isnumber(tokens[1]) \
		|| !ft_isnumber(tokens[2]))
	return(free(tokens), -1);
	red = ft_atoi(tokens[0]);
	green = ft_atoi(tokens[1]);
	bule = ft_atoi(tokens[2]);
	free_tokens(tokens);
	if (red < 0 || red > 255 || green < 0 \
		|| green > 255 || bule < 0 || bule > 255)
		return(free(tokens), -1);
	return ((red << 16) | (green << 8) | bule);
}

int	process_color_line(char *line, t_data data, int *found)
{
	if ((strncmp(line, "F ", 2) == 0) && !found[4])
	{
		data.map->floor_color = set_color(line + 2); 
		return ((found[4] = 1) ,0);
	}
	if ((strncmp(line, "C ", 2) == 0) && !found[5])
	{
		data.map->ceiling_color = set_color(line + 2);
		return ((found[5] = 1) ,0);
	}
	return (-1);
}

int	process_texture_line(char *line, t_data data, int *found)
{
	if ((strncmp(line, "NO ", 3) == 0) && !found[0])
	{
		data.map->nord = ft_strdup(line + 3);
		return ((found[0] = 1) ,0);
	}
	if ((strncmp(line, "SO ", 3) == 0) && !found[1])
	{
		data.map->south = ft_strdup(line + 3);
		return ((found[1] = 1) ,0);
	}
	if ((strncmp(line, "EA ", 3) == 0) && !found[2])
	{
		data.map->east = ft_strdup(line + 3);
		return ((found[2] = 1) ,0);
	}
	if ((strncmp(line, "WE ", 3) == 0) && !found[0])
	{
		data.map->west = ft_strdup(line + 3);
		return ((found[3] = 1) ,0);
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
	return(free(line), deallocate_map(data), -1);
}