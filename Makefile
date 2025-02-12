# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stalash <stalash@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 13:17:27 by stalash           #+#    #+#              #
#    Updated: 2025/02/12 14:52:47 by stalash          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME        =   cub3D
# CC          =   cc
# CFLAGS      =   -Wall -Werror -Wextra -std=c99 -g3 -fsanitize=address

# # directories
# SRC_DIR      =  src/
# OBJ_DIR      =  obj/
# LIB_DIR      =  lib/
# INC_DIR      =  include/
# LIBFT_DIR    =  $(LIB_DIR)libft/
# PRINTF_DIR   =  $(LIB_DIR)ft_printf/
# MLX42_DIR    =  $(LIB_DIR)MLX42/

# # color codes
# RESET       =   \033[0m
# GREEN       =   \033[92m  # Bright green
# YELLOW      =   \033[93m  # Bright yellow
# BLUE        =   \033[94m  # Bright blue
# RED         =   \033[91m  # Bright red

# # source files
# SRC_FILES    =  free.c \
#                 main.c \
#                 map_data.c \
#                 parsing.c \
#                 process_texture_color.c \
#                 texture_color.c \
#                 valid_map.c

# OBJ_FILES    =   $(SRC_FILES:.c=.o)

# # paths
# SRC          =   $(addprefix $(SRC_DIR), $(SRC_FILES))
# OBJ          =   $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# # all rule
# all: $(NAME)

# # Build libraries first (ensure libraries are built before linking)
# $(OBJ): $(SRC)
# 	@echo "$(YELLOW)Building libft...$(RESET)"
# 	@$(MAKE) -C $(LIBFT_DIR)  # Build libft
# 	@echo "$(YELLOW)Building ft_printf...$(RESET)"
# 	@$(MAKE) -C $(PRINTF_DIR)  # Build ft_printf

# # Now, build the main project
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

# # compile the executable
# $(NAME): $(OBJ)
# 	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
# 	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) \
#         -L$(LIBFT_DIR) -L$(PRINTF_DIR) -L$(MLX42_DIR) \
#         -lft -lftprintf -lmlx42
# 	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

# # compile objects
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@mkdir -p $(OBJ_DIR)
    
# 	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
# 	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(MLX42_DIR) -o $@ -c $<
# 	@echo "$(GREEN)Finished [$@]$(RESET)"

# # clean rule
# clean:
# 	@if [ -d "$(OBJ_DIR)" ]; then \
#         rm -rf $(OBJ_DIR); \
#         echo "$(BLUE)Deleted all object files from $(OBJ_DIR)...$(RESET)"; \
#     else \
#         echo "$(RED)No objects to remove from $(OBJ_DIR).$(RESET)"; \
#     fi

#     # Clean libraries
# 	@echo "$(YELLOW)Cleaning libft...$(RESET)"
# 	@$(MAKE) -C $(LIBFT_DIR) clean
# 	@echo "$(YELLOW)Cleaning ft_printf...$(RESET)"
# 	@$(MAKE) -C $(PRINTF_DIR) clean

# # fclean rule
# fclean: clean
# 	@if [ -f "$(NAME)" ]; then \
#         rm -f $(NAME); \
#         echo "$(BLUE)Deleted executable $(NAME)...$(RESET)"; \
#     else \
#         echo "$(RED)No executable to remove from the project directory.$(RESET)"; \
#     fi

#     # Clean libraries
# 	@echo "$(YELLOW)Cleaning libft...$(RESET)"
# 	@$(MAKE) -C $(LIBFT_DIR) fclean
# 	@echo "$(YELLOW)Cleaning ft_printf...$(RESET)"
# 	@$(MAKE) -C $(PRINTF_DIR) fclean

# # re rule
# re: fclean all

# # phony rules
# .PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = cub3D
SRC_DIR = src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/free.c $(SRC_DIR)/map_data.c \
		$(SRC_DIR)/parsing.c $(SRC_DIR)/process_texture_color.c \
		$(SRC_DIR)/texture_color.c $(SRC_DIR)/valid_map.c
OBJ = $(SRCS:.c=.o)

MLX_HEADER = lib/MLX42/include/MLX42
MLX_LIB = lib/MLX42/build

LIBFT_DIR = lib/libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

FT_PRINTF_DIR = lib/ft_printf
FT_PRINTF_NAME = libftprintf.a
FT_PRINTF = $(FT_PRINTF_DIR)/$(FT_PRINTF_NAME)

all: $(NAME) $(LIBFT) $(FT_PRINTF)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -I $(MLX_HEADER) -L $(MLX_LIB) -lmlx42 -lglfw -pthread -lm -o $(NAME)

mlx :
	cd lib && git clone https://github.com/ashirzad313/MLX42.git

clean_mlx :
	rm -rf lib/MLX42

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

fclean:
	rm -f $(OBJ) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all mlx, mlx_clean clean fclean re