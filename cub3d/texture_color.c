/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:28:17 by stalash           #+#    #+#             */
/*   Updated: 2025/01/20 19:53:38 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_line(t_data data)
{
	if (!data.map->nord || !data.map->south \
		|| !data.map->east || !data.map->west)
		return (-1);
	if (data.map->floor_color == 0x000000 \
		|| data.map->ceiling_color == 0x000000 \
		|| data.map->floor_color == 0xFFFFFFFF \
		|| data.map->ceiling_color == 0xFFFFFFFF)
		return (-1);
	return (0);
}

char	*remove_whitespace(char *line)
{
	int		i;
	int		len;
	char	*retrieved_line;
	int		length;

	i = 0;
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line) - 1;
	while (line[i] && ft_is_whitespace(line[i]))
		i++;
	while (len >= i && ft_is_whitespace(line[len]))
		len--;
	length = len - i + 1;
	if (length <= 0)
		return (NULL);
	retrieved_line = ft_strndup(line + i, length);
	if (retrieved_line == NULL)
		return (NULL);
	return (retrieved_line);
}

char	*refrctoring_line(int fd)
{
	char	*line;
	char	*refrctored_line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		refrctored_line = remove_whitespace(line);
		if (!refrctored_line || refrctored_line[0] == '\0')
			return (printf("Empty Line in the function\n"), \
					free(line), NULL);
		else
			return (free(line), refrctored_line);
	}
}

char	*retrieve_texture_and_color(int fd, t_data	data)
{
	char	*colors;
	int		result;

	result = 0;
	while (1)
	{
		colors = refrctoring_line(fd);
		if (!colors)
			break ;
		result = process_map_line(colors, data);
		if (result == -1)
			break ;
		else if (result == 1)
		{
			if (check_map_line(data) == -1)
				break ;
			else
				return (colors);
		}
		free(colors);
	}
	printf("ERROR : Provided map data is invalid\n");
	return (NULL);
}
