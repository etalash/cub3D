/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:04:33 by stalash           #+#    #+#             */
/*   Updated: 2025/01/17 07:41:27 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_data data)
{
	data.map->nord = NULL;
	data.map->south = NULL;
	data.map->east = NULL;
	data.map->west = NULL;
	data.map->res_w = RES_X;
	data.map->res_h = RES_Y;
	data.map->p_x = 0;
	data.map->p_y = 0;
	data.map->map_cub = NULL;
	data.map->m_h = MAP_HEIGHT;
	data.map->m_w = MAP_WIDE;
	data.map->floor_color = 0x000000;
	data.map->ceiling_color = 0x000000;
}

int	main(int argc, char **argv)
{

	t_data	data;

	if (argc != 2 || !argv[1][0])
		return (0);
	init_map(data);
	parsing(argv, data);
	return (0);
}