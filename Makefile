# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stalash <stalash@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 13:17:27 by stalash           #+#    #+#              #
#    Updated: 2025/03/18 12:33:40 by stalash          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# NAME = cub3D
# SRC_DIR = src
# SRCS = $(SRC_DIR)/parse/main.c $(SRC_DIR)/parse/free.c $(SRC_DIR)/parse/map_data.c \
# 		$(SRC_DIR)/parse/parsing.c $(SRC_DIR)/parse/process_texture_color.c \
# 		$(SRC_DIR)/parse/texture_color.c $(SRC_DIR)/parse/valid_map.c $(SRC_DIR)/exec/init.c \
# 		$(SRC_DIR)/exec/hooks.c
# OBJ = $(SRCS:.c=.o)

# MLX_HEADER = lib/MLX42/include/MLX42
# MLX_LIB = lib/MLX42/build

# LIBFT_DIR = lib/libft
# LIBFT_NAME = libft.a
# LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

# FT_PRINTF_DIR = lib/ft_printf
# FT_PRINTF_NAME = libftprintf.a
# FT_PRINTF = $(FT_PRINTF_DIR)/$(FT_PRINTF_NAME)



# # color codes
# RESET       =   \033[0m
# GREEN       =   \033[92m  # Bright green
# YELLOW      =   \033[93m  # Bright yellow
# BLUE        =   \033[94m  # Bright blue
# RED         =   \033[91m  # Bright red



# all: $(NAME) $(LIBFT) $(FT_PRINTF)

# 	@echo "$(GREEN)░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░▒▓███████▓▒░░▒▓███████▓▒░$(RESET)"
# 	@echo "$(GREEN)░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ $(RESET)"
# 	@echo "$(GREEN)░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ $(RESET)"
# 	@echo "$(GREEN)░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░ $(RESET)"
# 	@echo "$(GREEN)░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ $(RESET)"
# 	@echo "$(GREEN)░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ $(RESET)"
# 	@echo "$(GREEN) ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓███████▓▒░▒▓███████▓▒░░▒▓███████▓▒░$(RESET)"
# 	@echo "$(GREEN)                                                                  $(RESET)"
# 	@echo "$(GREEN)                                                                  $(RESET)"
# 	@echo ""




# $(SRC_DIR)/%.o: $(SRC_DIR)/%.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

# $(FT_PRINTF):
# 	make -C $(FT_PRINTF_DIR)

# $(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -I $(MLX_HEADER) -L $(MLX_LIB) -lmlx42 -lglfw -pthread -lm -o $(NAME)

# clean_mlx :
# 	rm -rf lib/MLX42

# clean:
# 	rm -f $(OBJ)
# 	make clean -C $(LIBFT_DIR)
# 	make clean -C $(FT_PRINTF_DIR)

# fclean:
# 	rm -f $(OBJ) $(NAME)
# 	make fclean -C $(LIBFT_DIR)
# 	make fclean -C $(FT_PRINTF_DIR)

# re: fclean all

# .PHONY: all mlx, mlx_clean clean fclean re



# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# NAME = cub3D
# SRC_DIR = src
# SRCS = $(SRC_DIR)/parse/main.c $(SRC_DIR)/parse/free.c $(SRC_DIR)/parse/map_data.c \
# 		$(SRC_DIR)/parse/parsing.c $(SRC_DIR)/parse/process_texture_color.c \
# 		$(SRC_DIR)/parse/texture_color.c $(SRC_DIR)/parse/valid_map.c $(SRC_DIR)/exec/execution.c  $(SRC_DIR)/exec/ray_cast.c\
# 		# (SRC_DIR)/exec/init.c $(SRC_DIR)/exec/hooks.c
# OBJ = $(SRCS:.c=.o)

# MLX_HEADER = lib/MLX42/include/MLX42
# MLX_LIB = lib/MLX42/build

# LIBFT_DIR = lib/libft
# LIBFT_NAME = libft.a
# LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

# FT_PRINTF_DIR = lib/ft_printf
# FT_PRINTF_NAME = libftprintf.a
# FT_PRINTF = $(FT_PRINTF_DIR)/$(FT_PRINTF_NAME)

# all: $(NAME) $(LIBFT) $(FT_PRINTF)

# $(SRC_DIR)/%.o: $(SRC_DIR)/%.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

# $(FT_PRINTF):
# 	make -C $(FT_PRINTF_DIR)

# $(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -I $(MLX_HEADER) -L $(MLX_LIB) -lmlx42 -lglfw -pthread -lm -o $(NAME)

# mlx :
# 	cd lib && git clone https://github.com/ashirzad313/MLX42.git

# clean_mlx :
# 	rm -rf lib/MLX42

# clean:
# 	rm -f $(OBJ)
# 	make clean -C $(LIBFT_DIR)
# 	make clean -C $(FT_PRINTF_DIR)

# fclean:
# 	rm -f $(OBJ) $(NAME)
# 	make fclean -C $(LIBFT_DIR)
# 	make fclean -C $(FT_PRINTF_DIR)

# re: fclean all

# .PHONY: all mlx, mlx_clean clean fclean re



CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NAME = cub3D
SRC_DIR = src
SRCS = $(SRC_DIR)/parse/main.c $(SRC_DIR)/parse/free.c $(SRC_DIR)/parse/map_data.c \
		$(SRC_DIR)/parse/parsing.c $(SRC_DIR)/parse/process_texture_color.c \
		$(SRC_DIR)/parse/texture_color.c $(SRC_DIR)/parse/valid_map.c $(SRC_DIR)/exec/execution.c \
		$(SRC_DIR)/exec/ray_cast.c $(SRC_DIR)/exec/render.c $(SRC_DIR)/exec/utils.c $(SRC_DIR)/exec/hooks.c \
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