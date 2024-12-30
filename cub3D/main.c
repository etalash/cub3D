/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:38:42 by stalash           #+#    #+#             */
/*   Updated: 2024/12/30 18:54:44 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player)
{

}

void	init_map(t_map	*map)
{
	map->map = calloc(10, sizeof(t_map));
	if (!map->map)
		return ;
	map->map[0] = "1111111111111111111111";
	map->map[1] = "1000000001000001000001";
	map->map[2] = "100000P000000100001001";
	map->map[3] = "1000000001000001000001";
	map->map[4] = "1000000001000000000001";
	map->map[5] = "1000000001000001000001";
	map->map[6] = "1000000001000001000001";
	map->map[7] = "1000000001000001000001";
	map->map[8] = "1111111111111111111111";
	map->map[9] = '\0';

	map->p_x_p = 7;
	map->p_y_p = 3;
	map->l_size = 9;
	map->w_size = 22;
}

int	main(int argc, char **argv)
{
	t_mlx	data;

	init_map(data.map);
	init_player(data.player);

	return (0);
}
