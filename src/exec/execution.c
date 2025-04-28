/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:33:38 by stalash           #+#    #+#             */
/*   Updated: 2025/04/07 05:34:54 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	game_loop(void *pointer)
{
	t_data	*data;

	data = (t_data *)pointer;
	mlx_delete_image(data->mlx, data->win);
	data->win = mlx_new_image(data->mlx, data->map->res_w, data->map->res_h);
	if (!data->win)
		return ;
	hook(data, 0, 0);
	draw_map(data);
	raycast(data);
	mlx_image_to_window(data->mlx, data->win, 0, 0);
}

// int	init_texture(t_data *dt)
// {
// 	if (!(dt->north = mlx_load_png(dt->map->nord)))
// 		return (ft_printf("Error loading north texture\n"), 1);
// 	if (!(dt->south = mlx_load_png(dt->map->south)))
// 		return (ft_printf("Error loading south texture\n"), 1);
// 	if (!(dt->east = mlx_load_png(dt->map->east)))
// 		return (ft_printf("Error loading east texture\n"), 1);
// 	if (!(dt->west = mlx_load_png(dt->map->west)))
// 		return (ft_printf("Error loading west texture\n"), 1);
// 	return (0);
// }

int	init_texture(t_data *dt)
{
	dt->north = mlx_load_png(dt->map->nord);
	if (!dt->north)
		return (ft_printf("Error loading north texture\n"), 1);
	dt->south = mlx_load_png(dt->map->south);
	if (!dt->south)
		return (ft_printf("Error loading south texture\n"), 1);
	dt->east = mlx_load_png(dt->map->east);
	if (!dt->east)
		return (ft_printf("Error loading east texture\n"), 1);
	dt->west = mlx_load_png(dt->map->west);
	if (!dt->west)
		return (ft_printf("Error loading west texture\n"), 1);
	return (0);
}

void	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		return ;
	data->player->rotation = 0;
	data->player->horizontal = 0;
	data->player->vertical = 0;
	data->player->pos_x = (data->map->p_x * TILE_SIZE) + (TILE_SIZE / 2);
	data->player->pos_y = (data->map->p_y * TILE_SIZE) + (TILE_SIZE / 2);
	if (data->map->p_p == 'N')
		data->player->angle = 2 * M_PI;
	else if (data->map->p_p == 'S')
		data->player->angle = 3 * M_PI / 2;
	else if (data->map->p_p == 'W')
		data->player->angle = M_PI;
	else if (data->map->p_p == 'E')
		data->player->angle = 0;
	init_ray(data);
}

void	execution(t_data *data)
{
	data->mlx = mlx_init(data->map->res_w, data->map->res_h, "Cub3D", false);
	if (!data->mlx)
		return (ft_printf("Error initializing MLX\n"), exit(1));
	if (init_texture(data))
		return (mlx_terminate(data->mlx), exit(1));
	init_player(data);
	if (!data->player || !data->ray)
		return (mlx_terminate(data->mlx), exit(1));
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->win);
}
