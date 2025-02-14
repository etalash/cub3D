/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:28:17 by stalash           #+#    #+#             */
/*   Updated: 2025/02/13 02:20:38 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int check_map_line(t_data data)
{
	int i, j;

	for (i = 0; i < data.map->m_h; i++)
	{
		for (j = 0; j < data.map->m_w; j++)
		{
			if (!is_valid_map_char(data.map->map_cub[i][j]))
				return (printf("Invalid character in map at (%d, %d)\n", i, j), -1);
		}
	}
	return (0);
}

char *remove_whitespace(char *line)
{
	int i, len, length;
	char *retrieved_line;

	i = 0;
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line) - 1;
	while (line[i] && ft_is_whitespace(line[i]))
		i++;
	while (len >= i && ft_is_whitespace(line[len]))
		len--;
	len++;
	length = len - i;
	if (length <= 0)
		return (NULL);
	retrieved_line = ft_strndup(line + i, length);
	if (retrieved_line == NULL)
		return (NULL);
	return (retrieved_line);
}

char *refrctoring_line(int fd)
{
	char *line;
	char *refrctored_line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		refrctored_line = remove_whitespace(line);
		free(line);
		if (!refrctored_line || *refrctored_line == '\0')
		{
			printf("Empty Line in the function\n");
			free(refrctored_line);
			return (NULL);
		}
		return (refrctored_line);
	}
}

char *retrieve_texture_and_color(int fd, t_data data)
{
	char *colors;
	int result;

	result = 0;
	while (1)
	{
		colors = refrctoring_line(fd);
		if (!colors)
			break;
		result = process_map_line(colors, data);
		if (result == -1)
		{
			free(colors);
			printf("ERROR : Invalid texture path or color format.\n");
			break ;
		}
		else if (result == 1)
		{
			if (check_map_line(data) == -1)
			{
				free(colors);
				printf("ERROR : Invalid map line.\n");
				break;
			}
			else
				return (colors);
		}
		free(colors);
	}
	printf("ERROR : Provided map data is invalid\n");
	return (NULL);
}
