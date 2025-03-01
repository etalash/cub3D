/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:33:38 by stalash           #+#    #+#             */
/*   Updated: 2025/02/24 15:18:32 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "math.h"

void	ceil_floor(t_data *data)
{
	int	i;
	int	j;
	int	med;

	i = -1;
	med = data->map->res_h / 2;
	while (++i < data->map->res_w)
	{
		j = -1;
		while (++j < med)
		{
			// printf("WE ARE HERE\n");
			mlx_put_pixel(data->win, i, j, data->map->ceiling_color);
			mlx_put_pixel(data->win, i, data->map->res_h \
				- 1 - j, data->map->floor_color);
		}
	}
}

// 16 is here tile the same thing like inthe init_player function
void	move_player(t_data *data, double x_position, double y_position)
{
	int	p_x;
	int	p_y;

	// printf("here we are\n");
	p_x = roundf(data->player->x_p + x_position) / 32;
	p_y = roundf(data->player->y_p + y_position) / 32;
	if (data->map->map_cub[p_y][p_x] != '1')
	{
		data->player->x_p += x_position;
		data->player->y_p += y_position;
	}
}

// 2 is rotation speed could be also slower and faster

void	rotation(t_data *data, int rotate)
{
	if (rotate == 1)
	{
		data->player->angel += 2 * (3.1415 / 180);
		if (data->player->angel > 2 * 3.1415)
			data->player->angel -= 2 * 3.1415;
	}
	else
	{
		data->player->angel -= 2 * (3.1415 / 180);
		if (data->player->angel < 0)
			data->player->angel += 2 * 3.1415;
	}
}

void	put_hooks(t_data *data)
{
	double	x_position;
	double	y_position;

	x_position = 0;
	y_position = 0;
	if (data->player->rotation == 1)
		rotation(data, 1);
	if (data->player->rotation == -1)
		rotation(data, -1);
	if (data->player->vertical == 1)
	{
		x_position = -sin(data->player->angel) * 4;
		y_position = cos(data->player->angel) * 4;
	}
	if (data->player->vertical == -1)
	{
		x_position = sin(data->player->angel) * 4;
		y_position = -cos(data->player->angel) * 4;
	}
	if (data->player->vertical == -2)
	{
		x_position = -cos(data->player->angel) * 4;
		y_position = -sin(data->player->angel) * 4;
	}
	if (data->player->vertical== 2)
	{
		x_position = cos(data->player->angel) * 4;
		y_position = sin(data->player->angel) * 4;
	}
	move_player(data, x_position, y_position);
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
	ceil_floor(data);
	// ray_casting(); // function could be here
	raycast(data);
	mlx_image_to_window(data->mlx, data->win, 0, 0);
}


void	re_init(mlx_key_data_t key_data, t_data *data)
{
	if ((key_data.key == MLX_KEY_W && key_data.action == 1) \
		|| (key_data.key == MLX_KEY_S && key_data.key == 1) \
		|| (key_data.key == MLX_KEY_D && key_data.key == 1) \
		|| (key_data.key == MLX_KEY_A && key_data.key == 1))
		data->player->vertical = 0;
	else if ((key_data.key == MLX_KEY_UP && key_data.key == 1) \
			|| (key_data.key == MLX_KEY_DOWN && key_data.key == 1))
		data->player->rotation = 0;
}
void	key_hook(mlx_key_data_t key_data, void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == 1)
		mlx_close_window(data->mlx);
	else if (key_data.key == MLX_KEY_W && key_data.action == 1)
		data->player->vertical = 1;
	else if (key_data.key == MLX_KEY_S && key_data.key == 1)
		data->player->vertical = -1;
	else if (key_data.key == MLX_KEY_D && key_data.key == 1)
		data->player->vertical = 2;
	else if (key_data.key == MLX_KEY_A && key_data.key == 1)
		data->player->vertical = -2;
	else if (key_data.key == MLX_KEY_UP && key_data.key == 1)
		data->player->rotation = 1;
	else if (key_data.key == MLX_KEY_DOWN && key_data.key == 1)
		data->player->rotation = -1;
	re_init(key_data, data);
}

void	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		return(printf("ERROR: can't malloc memory for the player\n"), exit(0));
	data->player->rotation = 0;
	data->player->vertical = 0;
	data->player->radian_FOV = PLAYER_ANGEL * (3.1415 / 180);
	data->player->x_p = (data->map->p_x * 32) + (32 / 2); // 16 is the tile of the map could be 32 and 64 as well (it it position the player in the map and the + 16/2 position it in the middle of the tile)
	data->player->y_p = (data->map->p_y * 32) + (32 / 2);
	if (data->map->p_p == 'E')
		data->player->angel = 0;
	else if (data->map->p_p == 'N')
		data->player->angel = 3.1415 / 2;
	else if (data->map->p_p == 'W')
		data->player->angel = 3.1415;
	else if (data->map->p_p == 'S')
		data->player->angel = 3 * (3.1415 / 2);
}

void	*load_image(t_data *data, char *str)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(str);
	image = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

int	init_textures(t_data *data)
{
	// data->nord = (mlx_texture_t *)data->map->nord;
	// data->south = (mlx_texture_t *)data->map->south;
	// data->east = (mlx_texture_t *)data->map->east;
	// data->west = (mlx_texture_t *)data->map->west;
	// data->nord = mlx_load_png(data->map->nord);
	if (!data->nord)
		return (1);
	data->south = mlx_load_png(data->map->south);
	if (!data->south)
		return (1);
	data->east = mlx_load_png(data->map->east);
	if (!data->east)
		return (1);
	data->west = mlx_load_png(data->map->west);
	if (!data->west)
		return (1);

	// data->nord = load_image(data, "assets/texture/clay.png");
	// if (!data->nord)
	// 	return (printf("ERROR: can't init texture\n"), 1);
	// data->south = load_image(data, "assets/texture/context_01.png");
	// if (!data->south)
	// 	return (printf("ERROR: can't init texture\n"), 1);
	// data->east = load_image(data, "assets/texture/brick_wall_09.png");
	// if (!data->east)
	// 	return (printf("ERROR: can't init texture\n"), 1);
	// data->west = load_image(data, "assets/texture/plaster_brick_pattern.png");
	// if (!data->west)
	// 	return (printf("ERROR: can't init texture\n"), 1);
	return (0);
}

void	execution(t_data *data)
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


	data->mlx = mlx_init(data->map->res_w, data->map->res_h, "Cub3D ", 0);
	if (!data->mlx)
	{
		printf("ERROR: can't init mlx\n");
		return ;
	}
	if (init_textures(data))
		return (printf("ERROR: can't init texture\n"), deallocate_map(data), exit(1));
	init_player(data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}
