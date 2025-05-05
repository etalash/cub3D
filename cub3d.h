/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:46:41 by stalash           #+#    #+#             */
/*   Updated: 2025/05/05 02:02:53 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

// ******** 4K *********
# define MAP_WIDE 120
# define MAP_HEIGHT 67
# define RED "\033[38;2;139;0;0m"
# define RESET "\033[0m"

// ******* FULL HD *****
# define RES_X 1600
# define RES_Y 1000
# define MAP_WIDE_F 60
# define MAP_HEIGHT_F 33
# define SIZE_OF_IMAGE 33
# define TILE_SIZE 32
# define MOVE_SPEED 2
# define NUM_RAYS RES_X
# define MAX_HEIGHT 25
# define MAX_WIDTH 80
# define ROTATION_SPEED 2
# define PLAYER_SPEED 4
# define TILE 32

// typedef struct s_image
// {
// 	mlx_image_t		*background;
// 	mlx_image_t		*wall;
// 	mlx_image_t		*player;
// }					t_image;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			angle;
	float			fov_rd;
	int				rotation;
	int				horizontal;
	int				vertical;
}					t_player;

typedef struct s_map
{
	char			*nord;
	char			*south;
	char			*east;
	char			*west;
	int				res_w;
	int				res_h;
	int				p_x;
	int				p_y;
	char			**map_cub;
	int				m_h;
	int				m_w;
	char			p_p;
	int32_t			floor_color;
	int32_t			ceiling_color;
}					t_map;


typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*win;
	mlx_image_t		*img;
	t_player		*player;
	t_map			*map;
	int				pixel;
}					t_data;

typedef struct s_map_info
{
	char			**map;
	int				map_height;
	int				map_width;
	int				player_x;
	int				player_y;
}					t_map_info;

//**************PARSING***************/
void				parsing(char *argv, t_data *data);
char				*retrieve_texture_and_color(int fd, t_data data);
int					process_map_line(char *line, t_data data);
char				*refrctoring_line(int fd);
char				*refrctoring_line_for_map(int fd);
int					retrieve_map_data(int fd, t_data data, char *map_colors);
int					valid_map(t_data data);
bool				is_valid_map_char(char c);
void				init_data(t_data *data);
void				init_map(t_map *map);
int					cheak_player(t_data data, int map_height, int map_wide,
						char **map);
int					flood_fill(t_map_info *map_info, int x, int y);
int					check_walls(t_data data, int map_height, int map_wide);

// ************ FREE *****************/
void				deallocate_map(t_data *data);
void				free_tokens(char **tokens);
void				cleanup(t_data *data);
void				free_sub_map(char **map);

// ************* EXECUTION ************/
void init_game(t_data *data);
// ************** Raycasting ***********************


//********************** TEST*************** */

void				debug1(t_data *data);

int					check_contex_map(t_data data, t_map_info map_info,
						char **map);
#endif
