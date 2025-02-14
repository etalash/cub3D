/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:46:41 by stalash           #+#    #+#             */
/*   Updated: 2025/02/14 18:37:41 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <math.h>
# include <unistd.h>
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/MLX42/include/MLX42/MLX42.h"


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
	mlx_t		*mlx;
	mlx_image_t	*win;
	t_player	*player;
	t_map		*map;
}	t_data;

void	parsing(char *argv, t_data *data);
char	*retrieve_texture_and_color(int fd, t_data	data);
int		process_map_line(char *line, t_data data);
char	*refrctoring_line(int fd);
// char	*retrieve_map_data(int fd, t_data data, char *map_colors);
int		retrieve_map_data(int fd, t_data data, char *map_colors);
int		valid_map(t_data data);
bool	is_valid_map_char(char c);

// ********** free ***********
void	deallocate_map(t_data *data);
void	free_tokens(char **tokens);


// ********** execution part ***********

void init_map(t_map *map);

void init_data(t_data *data, char *map_file);

void load_map(t_data *data, char *map_file);

void init_mlx(t_data *data);

void error_exit(t_data *data, char *message);

// int close_window(t_data *data);
void close_window(void *param);

void cleanup(t_data *data);

// hook config
void key_press(mlx_key_data_t keydata, void *param);

void key_release(mlx_key_data_t keydata, void *param);

void mouse_move(double x, double y, void *param);

void game_loop(void *param);

void mouse_click(mlx_button_t button, mlx_button_action_t action, mlx_keymod_t mods, void *param);
void render_frame(t_data *data);
#endif
