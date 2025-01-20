/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:46:41 by stalash           #+#    #+#             */
/*   Updated: 2025/01/20 19:42:14 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <math.h>
# include <unistd.h>
// # include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

// ******** 4K *********
# define RES_X 3840
# define RES_Y 2160
# define MAP_WIDE 120
# define MAP_HEIGHT 67

// ******* FULL HD *****
# define RES_X_F 1920
# define RES_Y_F 1080
# define MAP_WIDE_F 60
# define MAP_HEIGHT_F 33

typedef struct s_player
{
	int	x_p;
	int	y_p;
}	t_player;

typedef struct s_map
{
	char			*nord;
	char			*south;
	char			*east;
	char			*west;
	int				res_w; // horizontal resolution
	int				res_h; // vertical resolution
	int				p_x; // player x position
	int				p_y; // player y position
	char			**map_cub; // map of cub3d
	int				m_h; // map height
	int				m_w; // map wide
	char			p_p; // player position
	unsigned int	floor_color;
	unsigned int	ceiling_color;

}	t_map;

typedef struct s_data
{
	// mlx_t		*mlx;
	t_player	*player;
	t_map		*map;
}	t_data;

void	parsing(char *argv, t_data data);
char	*retrieve_texture_and_color(int fd, t_data	data);
int		process_map_line(char *line, t_data data);
char	*refrctoring_line(int fd);
char	*retrieve_map_data(int fd, t_data data, char *map_colors);
int		valid_map(t_data data);

// ********** free ***********
void	deallocate_map(t_data data);
void	free_tokens(char **tokens);

#endif
