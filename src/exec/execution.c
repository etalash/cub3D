/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:33:38 by stalash           #+#    #+#             */
/*   Updated: 2025/03/11 12:37:27 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_map(t_data *data)
{
	int	x;
	int	y;
	int	median;

	x = 0;
	median = data->map->res_h / 2;
	while (x < data->map->res_w)
	{
		y = 0;
		while (y < median)
		{
			mlx_put_pixel(data->win, x, y, data->map->ceiling_color);
			mlx_put_pixel(data->win, x, data->map->res_h \
				- 1 - y, data->map->floor_color);
			y++;
		}
		x++;
	}
}

void	move_player(t_data *data, double move_x, double move_y)
{
	int	p_x;
	int	p_y;

	p_x = roundf(data->player->x_p + move_x) / 32;
	p_y = roundf(data->player->y_p + move_y) / 32;
	if (data->map->map_cub[p_y][p_x] != '1')
	{
		data->player->x_p += move_x;
		data->player->y_p += move_y;
	}
}

void	rotation(t_data *data, int rotate)
{
	if (rotate == 1)
	{
		data->player->angel += 2 * (3.1415 / 180);
		if (data->player->angel > (2 * 3.1415))
			data->player->angel -= (2 * 3.1415);
	}
	else
	{
		data->player->angel -= 2 * (3.1415 / 180);
		if (data->player->angel < 0)
			data->player->angel += (2 * 3.1415);
	}
}

void put_hooks(t_data *data)
{
    double x_position = 0;
    double y_position = 0;

    if (data->player->rotation == 1)
        rotation(data, 1);
    if (data->player->rotation == -1)
        rotation(data, -1);
    if (data->player->vertical == 1)
    {
        x_position = -cos(data->player->angle) * MOVE_SPEED;
        y_position = -sin(data->player->angle) * MOVE_SPEED;
    }
    if (data->player->vertical == -1)
    {
        x_position = cos(data->player->angle) * MOVE_SPEED;
        y_position = sin(data->player->angle) * MOVE_SPEED;
    }
    if (data->player->horizontal == 1)
    {
        x_position = -sin(data->player->angle) * MOVE_SPEED;
        y_position = cos(data->player->angle) * MOVE_SPEED;
    }
    if (data->player->horizontal == -1)
    {
        x_position = sin(data->player->angle) * MOVE_SPEED;
        y_position = -cos(data->player->angle) * MOVE_SPEED;
    }
    move_player(data, x_position, y_position);
}

void	re_init(mlx_key_data_t key_data, t_data *data)
{
	if (key_data.key == MLX_KEY_W && key_data.action == 0)
		data->player->vertical = 0;
	else if (key_data.key == MLX_KEY_S && key_data.action == 0)
		data->player->vertical = 0;
	else if (key_data.key == MLX_KEY_D && key_data.action == 0)
		data->player->horizontal = 0;
	else if (key_data.key == MLX_KEY_A && key_data.action == 0)
		data->player->horizontal = 0;
	else if (key_data.key == MLX_KEY_RIGHT && key_data.action == 0)
		data->player->rotation = 0;
	else if (key_data.key == MLX_KEY_LEFT && key_data.action == 0)
		data->player->rotation = 0;
}

void	key_hook(mlx_key_data_t key_data, void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == 1)
		mlx_close_window(data->mlx);
	else if (key_data.key == MLX_KEY_W && key_data.action == 1)
		data->player->vertical = -1;
	else if (key_data.key == MLX_KEY_S && key_data.action == 1)
		data->player->vertical = 1;
	else if (key_data.key == MLX_KEY_D && key_data.action == 1)
		data->player->horizontal = 1;
	else if (key_data.key == MLX_KEY_A && key_data.action == 1)
		data->player->horizontal = -1;
	else if (key_data.key == MLX_KEY_RIGHT && key_data.action == 1)
		data->player->rotation = 1;
	else if (key_data.key == MLX_KEY_LEFT && key_data.action == 1)
		data->player->rotation = -1;
	re_init(key_data, data);
}

void	init_player(t_data *data)
{
	data->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return(printf("ERROR: can't malloc memory for the player\n"), exit(0));
	data->player->radian_FOV = PLAYER_ANGEL * (3.1415 / 180);
	data->player->x_p = (data->map->p_x * 32) + (32 / 2); 
	data->player->y_p = (data->map->p_y * 32) + (32 / 2);
	// if (data->map->p_p == 'N')
	// 	data->player->angle = 3 * 3.1415 / 2;
	// else if (data->map->p_p == 'S')
	// 	data->player->angle = 3.1415 / 2;
	// else if (data->map->p_p == 'W')
	// 	data->player->angle = 3.1415;
	// else if (data->map->p_p == 'E')
	// 	data->player->angle = 0;
	if (data->map->p_p == 'E')
		data->player->angel = 0;
	else if (data->map->p_p == 'N')
		data->player->angel = 3.1415 / 2;
	else if (data->map->p_p == 'W')
		data->player->angel = 3.1415;
	else if (data->map->p_p == 'S')
		data->player->angel = 3 * (3.1415 / 2);
}

void	game_loop(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	mlx_delete_image(data->mlx, data->win);
	data->win = mlx_new_image(data->mlx, data->map->res_w, data->map->res_h);
	if (!data->win)
		return (printf("ERROR: can't open new image\n"), exit(0));
	put_hooks(data);
	draw_map(data); // Draw the player on the screen
	raycast(data);
	mlx_image_to_window(data->mlx, data->win, 0, 0);
}

int	init_txt(t_data *data)
{
	if (!(data->nord = mlx_load_png(data->map->nord)))
		return (printf("ERROR: can't init nord txt\n"), 0);
	if (!(data->south = mlx_load_png(data->map->south)))
		return (printf("ERROR: can't init south txt\n"), 0);
	if (!(data->east = mlx_load_png(data->map->east)))
		return (printf("ERROR: can't init east txt\n"), 0);
	if (!(data->west = mlx_load_png(data->map->west)))
		return (printf("ERROR: can't init west txt\n"), 0);
	return (1);
}

void	execution(t_data *data)
{
	data->mlx = mlx_init(data->map->res_w, data->map->res_h, "Cub3D ", 0);
	if (!data->mlx)
	{
		printf("ERROR: can't init mlx\n");
		return(deallocate_map(data), exit(1));
	}
	if (!init_txt(data))
		return(deallocate_map(data), exit(1));
	init_player(data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}
