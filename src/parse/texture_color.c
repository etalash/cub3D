/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:28:17 by stalash           #+#    #+#             */
/*   Updated: 2025/05/16 21:06:25 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_map_line(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.map->m_h)
	{
		j = 0;
		while (j < data.map->m_w)
		{
			if (!is_valid_map_char(data.map->map_cub[i][j]))
				return (printf(RED"Invalid character in map at \
								(%d, %d)\n" RESET, i, j),
					-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*remove_whitespace(char *line)
{
	char	*retrieved_line;
	int		i;
	int		len;
	int		length;

	i = 0;
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	if (len == 0)
		return (NULL);
	len--;
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
		free(line);
		if (!refrctored_line || *refrctored_line == '\0')
		{
			free(refrctored_line);
			continue ;
		}
		return (refrctored_line);
	}
}

char	*refrctoring_line_for_map(int fd)
{
	char	*input;
	char	*refrctored_line;
	char	*final_line;

	while (1)
	{
		input = get_next_line(fd);
		if (!input)
			return (NULL);
		refrctored_line = remove_whitespace(input);
		free(input);
		if (*refrctored_line == '\0')
		{
			free(refrctored_line);
			printf(RED"Error: Empty line in map."RESET);
			exit(1);
		}
		final_line = ft_strdup(refrctored_line);
		free(refrctored_line);
		return (final_line);
	}
}

char	*retrieve_texture_and_color(int fd, t_data data)
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
	printf(RED"ERROR : Provided map data is invalid\n"RESET);
	return (NULL);
}
