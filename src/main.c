/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:04:33 by stalash           #+#    #+#             */
/*   Updated: 2025/02/08 22:56:52 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_map(t_map *map)
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

int main(int argc, char **argv)
{
	t_map map;
	t_data data;

	if (argc != 2 || !argv[1][0])
		return (printf("ERROR : Not enough arguments\n"), 0);
	init_map(&map);
	data.map = &map;
	parsing(argv[1], &data);
	return (0);
}
