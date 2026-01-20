# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maba <maba@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 13:17:27 by stalash           #+#    #+#              #
#    Updated: 2025/05/13 23:37:16 by maba             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# NAME = cub3D
# SRC_DIR = src
# SRCS = $(SRC_DIR)/parse/main.c $(SRC_DIR)/parse/free.c $(SRC_DIR)/parse/map_data.c \
# 		$(SRC_DIR)/parse/parsing.c $(SRC_DIR)/parse/process_texture_color.c \
# 		$(SRC_DIR)/parse/texture_color.c $(SRC_DIR)/parse/valid_map.c $(SRC_DIR)/exec/execution.c \
# 		$(SRC_DIR)/exec/ray_cast.c $(SRC_DIR)/exec/render.c $(SRC_DIR)/exec/utils.c \
# 		$(SRC_DIR)/exec/move.c

# OBJ = $(SRCS:.c=.o)

# MLX_DIR = lib/MLX42
# MLX_HEADER = $(MLX_DIR)/include/MLX42
# MLX_LIB = $(MLX_DIR)/build

# LIBFT_DIR = lib/libft
# LIBFT = $(LIBFT_DIR)/libft.a

# FT_PRINTF_DIR = lib/ft_printf
# FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# all: $(NAME)

# $(SRC_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) -I $(MLX_HEADER) -c $< -o $@

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

# $(FT_PRINTF):
# 	make -C $(FT_PRINTF_DIR)

# $(MLX_LIB)/libmlx42.a:
# 	cd $(MLX_DIR) && cmake -B build && cmake --build build

# $(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX_LIB)/libmlx42.a
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -I $(MLX_HEADER) \
# 	-L $(MLX_LIB) -lmlx42 -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf \
# 	-lglfw -pthread -lm -o $(NAME)

# clean:
# 	rm -f $(OBJ)
# 	make clean -C $(LIBFT_DIR)
# 	make clean -C $(FT_PRINTF_DIR)
# 	rm -rf $(MLX_LIB)

# fclean: clean
# 	rm -f $(NAME)
# 	make fclean -C $(LIBFT_DIR)
# 	make fclean -C $(FT_PRINTF_DIR)

# re: fclean all

# .PHONY: all clean fclean re


CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NAME = cub3D
SRC_DIR = src
SRCS = $(SRC_DIR)/parse/main.c $(SRC_DIR)/parse/free.c $(SRC_DIR)/parse/map_data.c \
		$(SRC_DIR)/parse/parsing.c $(SRC_DIR)/parse/process_texture_color.c \
		$(SRC_DIR)/parse/texture_color.c $(SRC_DIR)/parse/valid_map.c $(SRC_DIR)/exec/execution.c \
		$(SRC_DIR)/exec/ray_cast.c $(SRC_DIR)/exec/render.c $(SRC_DIR)/exec/utils.c \
		$(SRC_DIR)/exec/move.c

OBJ = $(SRCS:.c=.o)

MLX_DIR = lib/MLX42
MLX_HEADER = $(MLX_DIR)/include/MLX42
MLX_LIB = $(MLX_DIR)/build

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = lib/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(MLX_HEADER) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(MLX_LIB)/libmlx42.a:
	cd $(MLX_DIR) && cmake -B build && cmake --build build

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX_LIB)/libmlx42.a
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -I $(MLX_HEADER) \
	-L $(MLX_LIB) -lmlx42 -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf \
	-lglfw -pthread -lm -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)
	rm -rf $(MLX_LIB)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
