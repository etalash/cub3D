/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:36:56 by stalash           #+#    #+#             */
/*   Updated: 2025/04/08 00:01:13 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	setup_map_storage(t_data data)
{
	int	i;

	i = 0;
	data.map->map_cub = (char **)ft_calloc(MAP_HEIGHT, sizeof(char *));
	if (!data.map->map_cub)
	{
		printf(RED"allocation failure\n"RESET);
		deallocate_map(&data);
		return (1);
	}
	while (i < MAP_HEIGHT)
	{
		data.map->map_cub[i] = (char *)ft_calloc(MAP_WIDE, sizeof(char));
		if (!data.map->map_cub[i])
		{
			printf("allocation failure\n");
			deallocate_map(&data);
			return (1);
		}
		i++;
	}
	return (0);
}

int	valid_map_name(char *argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	if (len < 4)
		return (1);
	if (ft_strchr((argv + (len - 4)), '.') == 0)
		return (1);
	else if (ft_strchr((argv + (len - 3)), 'c') == 0)
		return (1);
	else if (ft_strchr((argv + (len - 2)), 'u') == 0)
		return (1);
	else if (ft_strchr((argv + (len - 1)), 'b') == 0)
		return (1);
	return (0);
}

void	parsing(char *argv, t_data *data)
{
	int		fd;
	char	*map_colors;

	if (valid_map_name(argv) == 1)
		return (printf(RED"Map's name is invalid\n"RESET), exit(1));
	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		return (printf(RED"can't open the given map\n"RESET), exit(1));
	if (setup_map_storage(*data) == 1)
		return (close(fd), exit(1));
	map_colors = retrieve_texture_and_color(fd, *data);
	if (map_colors == NULL)
		return (deallocate_map(data), close(fd), exit(1));
	if (retrieve_map_data(fd, *data, map_colors) != 0)
		return (deallocate_map(data), close(fd), exit(1));
	close(fd);
	if (valid_map(*data) == 1)
		return (deallocate_map(data), exit(1));
}
