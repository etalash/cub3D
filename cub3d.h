/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:46:41 by stalash           #+#    #+#             */
/*   Updated: 2025/03/19 13:03:14 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <unistd.h>
#include "lib/libft/libft.h"
#include "lib/ft_printf/ft_printf.h"
#include "lib/MLX42/include/MLX42/MLX42.h"

// ******** 4K *********
// # define RES_X 3840
// # define RES_Y 2160
#define MAP_WIDE 120
#define MAP_HEIGHT 67

// ******* FULL HD *****
#define RES_X 1900
#define RES_Y 1000
#define MAP_WIDE_F 60
#define MAP_HEIGHT_F 33
#define SIZE_OF_IMAGE 33
#define TILE_SIZE 32
#define PLAYER_ANGEL 90
#define MOVE_SPEED 4
// #define ROTATION_SPEED (2 * (M_PI / 180))
// # define FOV 1.0472 // Field of view (60 degrés en radians)
#define NUM_RAYS RES_X // Nombre de rayons (un par colonne de pixels)
#define MAX_HEIGHT 25
#define MAX_WIDTH 80
#define FOV 60
#define ROTATION_SPEED 2
#define PLAYER_SPEED 4
#define TILE 32

typedef struct s_image
{
	mlx_image_t		*background;
	mlx_image_t		*wall;
	mlx_image_t		*player;
}				t_image;

typedef struct s_player
{
	double			posX;
	double			posY;
	double			angle;
	float			fov_rd;
	int				rotation;
	int				horizontal;
	int				vertical;
}				t_player;

typedef struct s_map
{
	char			*nord;
	char			*south;
	char			*east;
	char			*west;
	int				res_w;		// horizontal resolution
	int				res_h;		// vertical resolution
	int				p_x;		// player x position
	int				p_y;		// player y position
	char			**map_cub; // map of cub3d
	int				m_h;		// map height
	int				m_w;		// map wide
	char			p_p;		// player position
	int32_t			floor_color;
	int32_t			ceiling_color;
}				t_map;

typedef struct s_ray
{
	int				i;				// Ray index for rendering
	float			rayAngle;		// Angle of the ray being cast
	float			perpWallDist; // Perpendicular wall distance
	double			vert_x;
	double			vert_y; // Coordinates of the vertical hit point
	int				stepX;
	int				stepY; // Step direction for the ray (1 or -1)
	int				hit;   // Hit status (1 = hit, 0 = no hit)
	int				side;  // Which wall side the ray hit (N/S/E/W)
	int				flag;  // Flag for ray direction (horizontal or vertical)
}				t_ray;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t 	*win;
	t_player		*player;
	t_map			*map;
	t_ray			*ray;
	mlx_texture_t	*text;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	int				pixel;
}				t_data;

//**************PARSING***************/
void			parsing(char *argv, t_data *data);
char			*retrieve_texture_and_color(int fd, t_data data);
int				process_map_line(char *line, t_data data);
char			*refrctoring_line(int fd);
int				retrieve_map_data(int fd, t_data data, char *map_colors);
int				valid_map(t_data data);
bool			is_valid_map_char(char c);
void			init_data(t_data *data);
void			init_map(t_map *map);

// ************ FREE *****************/
void			deallocate_map(t_data *data);
void			free_tokens(char **tokens);
void			cleanup(t_data *data);
void			free_sub_map(char **map);

// ************* EXECUTION ************/
void			execution(t_data *data);
void			game_loop(void *param);

// ************** Raycasting ***********************
void			raycast(t_data *data);
void			render_wall(t_data *data, int ray);
void			display_wall(t_data *data, int top_pix, int bottom_pix, double wall_h);
void			my_pixel_put(t_data *data, int x, int y, uint32_t color);
void			draw_map(t_data *data);
mlx_texture_t	*set_texture(t_data *data);
double			calc_wall_height(t_data *data);
double			distance(float x1, int x2, float y1, int y2);
float			check_angle(float angle);
int				reverse_bytes(int c);
void			move_player(t_data *data, double move_x, double move_y);
void			rotate_player(t_player *player, int rot);
void			hook(t_data *data, double move_x, double move_y);
void			key_release(mlx_key_data_t key_data, t_data *data);
void			key_hook(mlx_key_data_t key_data, void *pointer);

//********************** TEST*************** */
void display_background(t_data *data);
void *load_image(t_data *data, char *str);
void key_hook(mlx_key_data_t key_data, void *param);
// void	display_wall(t_data *data);
void debug1(t_data *data);

// Prototypes des fonctions du raycasting
void			init_data(t_data *data);
float			nor_angle(float angle);
float			check_angle(float angle);

#endif
