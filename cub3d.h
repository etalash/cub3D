/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:46:41 by stalash           #+#    #+#             */
/*   Updated: 2025/04/07 23:08:40 by maba             ###   ########.fr       */
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
# define RES_X 2560
# define RES_Y 1600
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

typedef struct s_image
{
	mlx_image_t		*background;
	mlx_image_t		*wall;
	mlx_image_t		*player;
}					t_image;

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

typedef struct s_ray
{
	int				i;
	float			ray_angle;
	double			perp_wall_dist;
	double			vert_x;
	double			vert_y;
	double			step_x;
	double			step_y;
	int				hit;
	int				side;
	int				flag;
}					t_ray;

typedef struct s_raycast_vars
{
	float			h_inter;
	float			v_inter;
	int				ray;
}					t_raycast_vars;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*win;
	t_player		*player;
	t_map			*map;
	t_ray			*ray;
	mlx_texture_t	*text;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	int				pixel;
}					t_data;

typedef struct s_display_vars
{
	double			x_o;
	double			y_o;
	double			factor;
	uint32_t		color;
}					t_display_vars;

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
void				execution(t_data *data);
void				game_loop(void *param);

// ************** Raycasting ***********************
void				raycast(t_data *data);
void				render_wall(t_data *data, int ray);
void				display_wall(t_data *data, int top_pix, int bottom_pix,
						double wall_h);
void				my_pixel_put(t_data *data, int x, int y, uint32_t color);
void				draw_map(t_data *data);
mlx_texture_t		*set_texture(t_data *data);
double				calc_wall_height(t_data *data);
double				distance(float x1, int x2, float y1, int y2);
float				check_angle(float angle);
int					reverse_bytes(int c);
void				move_player(t_data *data, double move_x, double move_y);
void				rotate_player(t_player *player, int rot);
void				hook(t_data *data, double move_x, double move_y);
void				key_release(mlx_key_data_t key_data, t_data *data);
void				key_hook(mlx_key_data_t key_data, void *pointer);

//********************** TEST*************** */
void				display_background(t_data *data);
void				*load_image(t_data *data, char *str);
void				key_hook(mlx_key_data_t key_data, void *param);

void				debug1(t_data *data);

void				init_ray(t_data *data);
float				nor_angle(float angle);
float				check_angle(float angle);
int					check_contex_map(t_data data, t_map_info map_info,
						char **map);
#endif
