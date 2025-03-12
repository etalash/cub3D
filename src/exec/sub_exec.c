/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:35:14 by stalash           #+#    #+#             */
/*   Updated: 2025/03/11 12:36:45 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


// void move_player(t_data *data, double x_position, double y_position)
// {
//     int p_x;
//     int p_y;

//     printf("Current player position: (%d, %d)\n", data->player->x_p, data->player->y_p);

//     // Limiter le déplacement à une case à la fois
//     x_position = fmin(fmax(x_position, -1.0), 1.0);
//     y_position = fmin(fmax(y_position, -1.0), 1.0);

//     // Calculer les nouvelles positions du joueur
//     p_x = (int)(data->map->p_x + x_position);
//     p_y = (int)(data->map->p_y + y_position);
// 	data->map->m_w = ft_strlen(data->map->map_cub[0]);
//     printf("New player position: (%d, %d)\n", p_x, p_y);

// 	printf("px: %d\n", p_x);
// 	printf("py: %d\n", p_y);
//     // Vérifier que les nouvelles positions sont dans les limites de la carte
// 	printf("map_w: %d\n", data->map->m_w);
// 	printf("map_h: %d\n", data->map->m_h);
// 	printf("%f\n", x_position);
// 	printf("%f\n", y_position);
//     if (p_x >= 0 && p_x < data->map->m_w && p_y >= 0 && p_y < data->map->m_h)
//     {
//         // Vérifier que la nouvelle position n'est pas un mur
//         if (data->map->map_cub[p_y][p_x] != '1')
//         {
//             data->player->x_p += x_position;
//             data->player->y_p += y_position;
//         }
//         else
//         {
//             printf("Erreur: Collision avec un mur\n");
//         }
//     }
//     else
//     {
//         printf("Erreur: Position du joueur en dehors des limites de la carte\n");
//     }
// }
// 2 is rotation speed could be also slower and faster



// void key_press(mlx_key_data_t keydata, void *param)
// {
//     t_data *data = (t_data *)param;

//     // Gérer les touches enfoncées (W, A, S, D, flèches, etc.)
//     if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
//         move_player(data, cos(data->player->angle) * MOVE_SPEED, sin(data->player->angle) * MOVE_SPEED); // Déplacer le joueur vers l'avant
//     if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
//         move_player(data, -cos(data->player->angle) * MOVE_SPEED, -sin(data->player->angle) * MOVE_SPEED); // Déplacer le joueur vers l'arrière
//     if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
//         move_player(data, -sin(data->player->angle) * MOVE_SPEED, cos(data->player->angle) * MOVE_SPEED); // Déplacer le joueur vers la gauche
//     if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
//         move_player(data, sin(data->player->angle) * MOVE_SPEED, -cos(data->player->angle) * MOVE_SPEED); // Déplacer le joueur vers la droite
// }

// void key_release(mlx_key_data_t keydata, void *param)
// {
// 	t_data *data = (t_data *)param;

// 	// Gérer les touches relâchées (optionnel)
// 	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
// 		data->player->x_p = 0; // Arrêter le déplacement vers l'avant
// 	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
// 		data->player->x_p = 0; // Arrêter le déplacement vers l'arrière
// 	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
// 		data->player->y_p = 0; // Arrêter le déplacement vers la gauche
// 	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
// 		data->player->y_p = 0; // Arrêter le déplacement vers la droite
// }

// void draw_map(t_data *data)
// {
//     int tile_size = 32; // Taille de chaque cellule de la carte
//     int color;

//     for (int y = 0; y < data->map->m_h; y++)
//     {
//         for (int x = 0; x < data->map->m_w; x++)
//         {
//             if (data->map->map_cub[y][x] == '1')
//                 color = 0x000000; // Noir pour les murs
//             else
//                 color = 0xFFFFFF; // Blanc pour les espaces vides

//             for (int i = 0; i < tile_size; i++)
//             {
//                 for (int j = 0; j < tile_size; j++)
//                 {
//                     mlx_put_pixel(data->win, x * tile_size + i, y * tile_size + j, color);
//                 }
//             }
//         }
//     }
// }
