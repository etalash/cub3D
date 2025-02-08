/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:53:54 by stalash           #+#    #+#             */
/*   Updated: 2025/02/08 22:56:12 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// int	check_walls(t_data data, int map_height, int map_wide)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	j = -1;
// 	while (++j < map_wide)
// 	{
// 		if (ft_strlen(data.map->map_cub[0]) > (size_t)j 
// 			&& (data.map->map_cub[0][j] != '1' 
// 			|| data.map->map_cub[map_height - 1] 
// 			[j] != '1'))
// 			return (0);
// 	}
// 	printf("WE ARE HERE\n");
// 	while (++i < map_height)
// 	{
// 		if (data.map->map_cub[i][0] != '1' 
// 			|| (ft_strlen(data.map->map_cub[i]) > 0 
// 			&& data.map->map_cub[i][ft_strlen 
// 			(data.map->map_cub[i]) - 1] != '1'))
// 			return (0);
// 	}
// 	return (1);
// }

int cheak_player(t_data data, int map_height, int map_wide, char **map)
{
    int i;
    int j;
    int player_count;

    player_count = 0;
    i = 0;
    map = data.map->map_cub;
    while (++i < map_height)
    {
        j = 0;
        while (++j < map_wide - 1)
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
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

// int	valid_map(t_data data)
// {
// 	int		i;
// 	int		map_wide;
// 	char	**map;

// 	i = -1;
// 	map = data.map->map_cub;
// 	map_wide = 0;
// 	while (++i < MAP_HEIGHT)
// 		if (ft_strlen(data.map->map_cub[i]) > (size_t)map_wide)
// 			map_wide = ft_strlen(data.map->map_cub[i]);
// 	if (!cheak_player(data, data.map->m_h, map_wide, map))
// 		return (printf("ERROR : Map player is invalid\n"), 1);
// 	if (!check_walls(data, data.map->m_h, map_wide))
// 		return (printf("ERROR : Map data is invalid\n"), 1);
// 	return (0);
// }

int flood_fill(char **map, int x, int y, int map_height, int map_wide)
{
    if (x < 0 || x >= map_wide || y < 0 || y >= map_height)
	{

		printf("HERE ARE WE\n");
        return (1); // Out of bounds
	}
    if (map[y][x] == '1' || map[y][x] == 'F')
        return (0); // Wall or already filled
    // if (map[y][x] == ' ')
    //     return (1); // Space is not enclosed

    map[y][x] = 'F'; // Mark as filled

    if (flood_fill(map, x + 1, y, map_height, map_wide) != 0)
        return (1);
    if (flood_fill(map, x - 1, y, map_height, map_wide) != 0)
        return (1);
    if (flood_fill(map, x, y + 1, map_height, map_wide) != 0)
        return (1);
    if (flood_fill(map, x, y - 1, map_height, map_wide) != 0)
        return (1);

    return (0);
}

int valid_map(t_data data)
{
    int i;
    int map_wide;
    char **map;

    i = -1;
    map = data.map->map_cub;
    map_wide = 0;
    while (++i < MAP_HEIGHT)
        if (ft_strlen(data.map->map_cub[i]) > (size_t)map_wide)
            map_wide = ft_strlen(data.map->map_cub[i]);
    if (!cheak_player(data, data.map->m_h, map_wide, map))
        return (printf("ERROR : Map player is invalid\n"), 1);
    if (flood_fill(map, data.map->p_x, data.map->p_y, data.map->m_h, map_wide) != 0)
        return (printf("ERROR : Map is not enclosed by walls\n"), 1);
    return (0);
}
