/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 01:23:44 by maba              #+#    #+#             */
/*   Updated: 2025/05/05 02:00:20 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void init_game(t_data *data)
{
    data->mlx = mlx_init(data->map->res_w, data->map->res_h, "Cub3D", true);
    if (!data->mlx)
        return (printf("Error: Failed to initialize mlx\n"), exit(1));
    data->win = mlx_new_image(data->mlx, data->map->res_w, data->map->res_h);
    if (!data->win)
        return (printf("Error: Failed to create window\n"), exit(1));
    data->img = mlx_new_image(data->mlx, data->map->res_w, data->map->res_h);
    if (!data->img)
        return (printf("Error: Failed to create image\n"), exit(1));
}
