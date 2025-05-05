/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:53:54 by stalash           #+#    #+#             */
/*   Updated: 2025/05/05 19:06:31 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	cheak_player(t_data data, int map_height, int map_wide, char **map)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	map = data.map->map_cub;
	while (++i < map_height)
	{
		j = 0;
		while (++j < map_wide - 1)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				player_count++;
				data.map->p_x = j;
				data.map->p_y = i;
				data.map->p_p = map[i][j];
			}
		}
	}
	if (player_count == 1)
		return (1);
	return (0);
}

int	flood_fill(t_map_info *map_info, int x, int y)
{
	if (x < 0 || x >= map_info->map_width || y < 0 || y >= map_info->map_height)
		return (1);
	if (map_info->map[y][x] == '1' || map_info->map[y][x] == 'F')
		return (0);
	if (map_info->map[y][x] == ' ')
		return (1);
	map_info->map[y][x] = 'F';
	if (flood_fill(map_info, x + 1, y) != 0)
		return (1);
	if (flood_fill(map_info, x - 1, y) != 0)
		return (1);
	if (flood_fill(map_info, x, y + 1) != 0)
		return (1);
	if (flood_fill(map_info, x, y - 1) != 0)
		return (1);
	return (0);
}

static char	**initialize_map(t_data data)
{
	char	**map;
	int		i;

	map = (char **)ft_calloc(MAP_HEIGHT, sizeof(char *));
	if (!map)
	{
		printf(RED"ERROR: Memory allocation failed\n"RESET);
		return (NULL);
	}
	i = -1;
	while (++i < MAP_HEIGHT)
	{
		map[i] = ft_strdup(data.map->map_cub[i]);
		if (!map[i])
		{
			printf(RED"ERROR: with ft_strdup\n"RESET);
			free_sub_map(map);
			return (NULL);
		}
	}
	return (map);
}

int is_valid_border(char c)
{
    return (c == '1' || c == ' ');
}

int check_walls(t_data data, int map_height)
{
    int     i;
    size_t  len;
    int     j;

    i = -1;
    while (++i < map_height)
    {
        len = ft_strlen(data.map->map_cub[i]);
        if (len == 0)
            continue;
        if (i == 0 || i == map_height - 1)
        {
            j = -1;
            while (++j < (int)len)
                if (!is_valid_border(data.map->map_cub[i][j]))
                    return (0);
            continue;
        }
        if (!is_valid_border(data.map->map_cub[i][0]) || 
            !is_valid_border(data.map->map_cub[i][len - 1]))
            return (0);
    }
    return (1);
}

int	valid_map(t_data data)
{
	char		**map;
	int			map_width;
	int			i;
	t_map_info	map_info;

	map = initialize_map(data);
	if (!map)
		return (0);
	map_width = 0;
	i = -1;
	while (++i < MAP_HEIGHT_F)
		if (ft_strlen(data.map->map_cub[i]) > (size_t)map_width)
			map_width = ft_strlen(data.map->map_cub[i]);
	map_info.map = map;
	map_info.map_height = data.map->m_h;
	map_info.map_width = map_width;
	map_info.player_x = data.map->p_x;
	map_info.player_y = data.map->p_y;
	if (check_contex_map(data, map_info, map))
		return (1);
	free_sub_map(map);
	return (0);
}
