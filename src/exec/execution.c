/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:33:38 by stalash           #+#    #+#             */
/*   Updated: 2025/03/04 15:44:35 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "math.h"


void move_player(t_data *data, double x_position, double y_position)
{
    int p_x;
    int p_y;

    printf("Current player position: (%d, %d)\n", data->player->x_p, data->player->y_p);

    // Limiter le déplacement à une case à la fois
    x_position = fmin(fmax(x_position, -1.0), 1.0);
    y_position = fmin(fmax(y_position, -1.0), 1.0);

    // Calculer les nouvelles positions du joueur
    p_x = (int)(data->map->p_x + x_position);
    p_y = (int)(data->map->p_y + y_position);
	data->map->m_w = ft_strlen(data->map->map_cub[0]);
    printf("New player position: (%d, %d)\n", p_x, p_y);

	printf("px: %d\n", p_x);
	printf("py: %d\n", p_y);
    // Vérifier que les nouvelles positions sont dans les limites de la carte
	printf("map_w: %d\n", data->map->m_w);
	printf("map_h: %d\n", data->map->m_h);
	printf("%f\n", x_position);
	printf("%f\n", y_position);
    if (p_x >= 0 && p_x < data->map->m_w && p_y >= 0 && p_y < data->map->m_h)
    {
        // Vérifier que la nouvelle position n'est pas un mur
        if (data->map->map_cub[p_y][p_x] != '1')
        {
            data->player->x_p += x_position;
            data->player->y_p += y_position;
        }
        else
        {
            printf("Erreur: Collision avec un mur\n");
        }
    }
    else
    {
        printf("Erreur: Position du joueur en dehors des limites de la carte\n");
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
        x_position = cos(data->player->angle) * MOVE_SPEED;
        y_position = sin(data->player->angle) * MOVE_SPEED;
    }
    if (data->player->vertical == -1)
    {
        x_position = -cos(data->player->angle) * MOVE_SPEED;
        y_position = -sin(data->player->angle) * MOVE_SPEED;
    }
    if (data->player->vertical == -2)
    {
        x_position = -sin(data->player->angle) * MOVE_SPEED;
        y_position = cos(data->player->angle) * MOVE_SPEED;
    }
    if (data->player->vertical == 2)
    {
        x_position = sin(data->player->angle) * MOVE_SPEED;
        y_position = -cos(data->player->angle) * MOVE_SPEED;
    }
    move_player(data, x_position, y_position);
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
	data->player->angle = 0; // Initial angle
	data->player->rotation = 0;
	data->player->vertical = 0;
	data->player->radian_FOV = PLAYER_ANGEL * (3.1415 / 180);
	data->player->x_p = (data->map->p_x * 32) + (32 / 2); 
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



void key_press(mlx_key_data_t keydata, void *param)
{
    t_data *data = (t_data *)param;

    // Gérer les touches enfoncées (W, A, S, D, flèches, etc.)
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        move_player(data, cos(data->player->angle) * MOVE_SPEED, sin(data->player->angle) * MOVE_SPEED); // Déplacer le joueur vers l'avant
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        move_player(data, -cos(data->player->angle) * MOVE_SPEED, -sin(data->player->angle) * MOVE_SPEED); // Déplacer le joueur vers l'arrière
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        move_player(data, -sin(data->player->angle) * MOVE_SPEED, cos(data->player->angle) * MOVE_SPEED); // Déplacer le joueur vers la gauche
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        move_player(data, sin(data->player->angle) * MOVE_SPEED, -cos(data->player->angle) * MOVE_SPEED); // Déplacer le joueur vers la droite
}

void key_release(mlx_key_data_t keydata, void *param)
{
	t_data *data = (t_data *)param;

	// Gérer les touches relâchées (optionnel)
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		data->player->x_p = 0; // Arrêter le déplacement vers l'avant
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		data->player->x_p = 0; // Arrêter le déplacement vers l'arrière
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		data->player->y_p = 0; // Arrêter le déplacement vers la gauche
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		data->player->y_p = 0; // Arrêter le déplacement vers la droite
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
	raycast(data);
	draw_map(data); // Draw the player on the screen
	mlx_image_to_window(data->mlx, data->win, 0, 0);
}


void	execution(t_data *data)
{
	data->mlx = mlx_init(data->map->res_w, data->map->res_h, "Cub3D ", 0);
	if (!data->mlx)
	{
		printf("ERROR: can't init mlx\n");
		return ;
	}
	init_player(data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}


void draw_map(t_data *data)
{
    int tile_size = 32; // Taille de chaque cellule de la carte
    int color;

    for (int y = 0; y < data->map->m_h; y++)
    {
        for (int x = 0; x < data->map->m_w; x++)
        {
            if (data->map->map_cub[y][x] == '1')
                color = 0x000000; // Noir pour les murs
            else
                color = 0xFFFFFF; // Blanc pour les espaces vides

            for (int i = 0; i < tile_size; i++)
            {
                for (int j = 0; j < tile_size; j++)
                {
                    mlx_put_pixel(data->win, x * tile_size + i, y * tile_size + j, color);
                }
            }
        }
    }
}
int main(int argc, char **argv)
{
	t_map map;
	t_data data;

	if (argc != 2 || !argv[1][0])
		return (ft_printf("ERROR : Not enough arguments\n"), 0);
	init_map(&map);
	data.map = &map;
	parsing(argv[1], &data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	execution(&data);
	deallocate_map(&data);
	return (0);
}
