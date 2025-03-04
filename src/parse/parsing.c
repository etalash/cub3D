/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:36:56 by stalash           #+#    #+#             */
/*   Updated: 2025/03/03 02:35:48 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	debug(t_data *data)
{
	int i = 0, j = 0;
	printf("Nord: %s\n", data->map->nord);
	printf("south: %s\n", data->map->south);
	printf("east: %s\n", data->map->east);
	printf("west: %s\n", data->map->west);
	while (i < data->map->m_h)
	{
		while (data->map->map_cub[i][j])
		{
			printf("%c", data->map->map_cub[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}

	printf("\n%d\n", data->map->res_h);
	printf("\n%d\n", data->map->res_w);
}

int setup_map_storage(t_data data)
{
	int i;

	data.map->map_cub = (char **)ft_calloc(MAP_HEIGHT, sizeof(char *));
	if (!data.map->map_cub)
	{
		printf("allocation failure\n");
		deallocate_map(&data);
		return (1);
	}
	for (i = 0; i < MAP_HEIGHT; i++)
	{
		data.map->map_cub[i] = (char *)ft_calloc(MAP_WIDE, sizeof(char));
		if (!data.map->map_cub[i])
		{
			printf("allocation failure\n");
			deallocate_map(&data);
			return (1);
		}
		ft_memset(data.map->map_cub[i], '\0', MAP_WIDE);
	}
	return (0);
}

int valid_map_name(char *argv)
{
	int len;

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

void	debug1(t_data *data)
{
	printf("Nord: %s\n", data->map->nord);
	printf("south: %s\n", data->map->south);
	printf("east: %s\n", data->map->east);
	printf("west: %s\n", data->map->west);
	for(int i = 0; data->map->map_cub[i][0]; i++)
		printf("%s\n", data->map->map_cub[i]);
	printf("res height: %d\n", data->map->res_h);
	printf("res wide: %d\n", data->map->res_w);
	printf("floor: %d\n",data->map->floor_color);
	printf("ceil: %d\n",data->map->ceiling_color);
}

void parsing(char *argv, t_data *data)
{
	int fd;
	char *map_colors;

	if (valid_map_name(argv) == 1)
	return (printf("Map's name is invalid\n"), exit(1));
	fd = open(argv, O_RDONLY);
	if (fd <= 0)
	return (printf("can't open the given map\n"), exit(1));
	if (setup_map_storage(*data) == 1)
	return (close(fd), exit(1));
	map_colors = retrieve_texture_and_color(fd, *data);
	// debug1(data);
	
	if (map_colors == NULL)
	return (deallocate_map(data), close(fd), exit(1));
	if (retrieve_map_data(fd, *data, map_colors) != 0)
	return (deallocate_map(data), close(fd), exit(1));
	close(fd);
	// debug(data);	// Debug print
	if (valid_map(*data) == 1)
	return (deallocate_map(data), exit(1));
	// printf("Map data is valid\n"); // Debug print
}
