/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:04:33 by stalash           #+#    #+#             */
/*   Updated: 2025/05/05 02:07:30 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_contex_map(t_data data, t_map_info map_info, char **map)
{
	if (!check_walls(data, map_info.map_height, map_info.map_width))
		return (printf(RED"ERROR: map is not surrounded by walls\n"RESET), \
				free_sub_map(map), 1);
	if (!cheak_player(data, map_info.map_height, map_info.map_width, map))
		return (printf(RED"ERROR: Map player is invlid\n"RESET), \
				free_sub_map(map), 1);
	if (flood_fill(&map_info, map_info.player_x, map_info.player_y) != 0)
		return (printf(RED"ERROR : Map is not enclosed by walls\n"RESET),
			free_sub_map(map), 1);
	return (0);
}

// void	init_ray(t_data *data)
// {
// 	data->ray = malloc(sizeof(t_ray));
// 	if (!data->ray)
// 	{
// 		printf("Error: Failed to allocate memory for data->ray\n");
// 		exit(1);
// 	}
// }

void	init_map(t_map *map)
{
	map->nord = NULL;
	map->south = NULL;
	map->east = NULL;
	map->west = NULL;
	map->res_w = RES_X;
	map->res_h = RES_Y;
	map->p_x = 0;
	map->p_y = 0;
	map->map_cub = NULL;
	map->m_h = 0;
	map->m_w = 0;
	map->p_p = '0';
	map->floor_color = 0x000000;
	map->ceiling_color = 0x000000;
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_data	data;

	if (argc != 2 || !argv[1][0])
		return (ft_printf("ERROR : Not enough arguments\n"), 0);
	init_map(&map);
	data.map = &map;
	parsing(argv[1], &data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	// execution(&data);
	init_game(&data);
	mlx_loop(data.mlx);
	deallocate_map(&data);
	cleanup(&data);
	return (0);
}
