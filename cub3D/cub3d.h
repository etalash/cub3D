/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:26:05 by stalash           #+#    #+#             */
/*   Updated: 2024/12/30 18:46:04 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

typedef struct s_player
{
	int	x_p;
	int	y_p;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		w_size;
	int		l_size;
	int		p_x_p;
	int		p_y_p;
}	t_map;

typedef struct s_mlx
{
	mlx_t		mlx;
	t_player	*player;
	t_map		*map;
}	t_mlx;

#endif
