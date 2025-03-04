/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:56:54 by maba              #+#    #+#             */
/*   Updated: 2025/03/04 15:49:04 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// void key_press(mlx_key_data_t keydata, void *param)
// {
// 	t_data *data = (t_data *)param;

// 	// Gérer les touches enfoncées (W, A, S, D, flèches, etc.)
// 	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
// 		data->player->x_p += 1; // Déplacer le joueur vers l'avant
// 	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
// 		data->player->x_p -= 1; // Déplacer le joueur vers l'arrière
// 	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
// 		data->player->y_p -= 1; // Déplacer le joueur vers la gauche
// 	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
// 		data->player->y_p += 1; // Déplacer le joueur vers la droite
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

// void mouse_click(mlx_button_t button, mlx_button_action_t action, mlx_keymod_t mods, void *param)
// {
//     t_data *data = (t_data *)param;
//     // Gérer les clics de la souris
//     if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
//     {
//         // Exemple d'action lors d'un clic gauche
//         printf("Clic gauche détecté\n");
//     }
// }

// void game_loop(void *param)
// {
// 	t_data *data = (t_data *)param;
// 	// Mettre à jour et afficher la frame
// 	render_frame(data);
// }

// void render_frame(t_data *data)
// {
// 	(void)data;

// 	// Implémenter le rendu de la frame complète (murs, minimap, etc.)
// }
