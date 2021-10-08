# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 16:03:32 by nide-mel          #+#    #+#              #
#    Updated: 2021/10/08 13:13:42 by nide-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

OS = $(shell uname)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -f

HEADER = ./includes/$(wildcard *.h)

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

ifeq ($(OS), Linux)
	MINILIBX_DIR = ./minilibx-linux/
	MLX_LIB = $(MINILIBX_DIR)libmlx_linux.a
	LIBX += -L $(MINILIBX_DIR) -l mlx -lXext -lX11 -lm -lz
else
	LIBX = -lmlx -framework OpenGL -framework AppKit
	MINILIBX_DIR = ./minilibx_mms_20200219/
endif

MLX_INC = -I $(MINILIBX_DIR)

INCLUDES = -I libft/includes -I ./includes/main
INCLUDES_BONUS = -I libft/includes -I ./includes/bonus

SRC_PATH = ./src/main
SRC_BONUS_PATH = ./src/bonus

OBJ_PATH = ./obj
OBJ_BONUS_PATH = ./obj_bonus

SRC_NAME =	main.c\
			init_struct.c\
			utils.c\
			map/checkers_map.c\
			map/map_functions.c\
			map/organize_map.c\
			render/init_images.c\
			render/render_img.c\
			render/game_moves.c\
			render/utils_move.c\

SRC_BONUS_NAME = main.c\

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

SRC_BONUS = $(addprefix $(SRC_BONUS_NAME)/, $(SRC_BONUS_NAME))

all : $(NAME) $(LIBFT) $(MLX_LIB)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(MINILIBX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBX) $(INCLUDES) $(LIBFT) -o $(NAME)
	@echo "\x1b[32m"
	@cat ./art/ok
	@echo ""
	@echo "[$(NAME) compiled]"
	@echo "\x1b[0m"


$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p obj
	@mkdir -p obj/map
	@mkdir -p obj/render
	@$(CC) -c $(CFLAGS) $(INCLUDES) $(MLX_INC) -o $@ -c $<

bonus : $(NAME_BONUS) $(LIBFT) $(MLX_LIB)
	@make -C $(LIBFT_PATH)
	@make -C $(MINILIBX_DIR)
	@$(CC) $(CFLAGS) $(OBJ_BONUS_PATH) $(LIBX) $(INCLUDES_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "\x1b[32m"
	@cat ./art/ok
	@echo ""
	@echo "[$(NAME) compiled]"
	@echo "\x1b[0m"

$(OBJ_BONUS_PATH)/%.o : $(SRC_BONUS_PATH)/%.c
	@mkdir -p obj_bonus
	@mkdir -p obj_bonus/map
	@mkdir -p obj_bonus/render
	@(CC) -c $(CFLAGS) $(INCLUDES_BONUS) $(MLX_INC) -o $@ -c $<

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MINILIBX_DIR)
	@rm -rf $(OBJ)
	@echo "\033[33m"
	@cat "./art/clean"
	@echo ""
	@echo "all $(NAME) .o files are removed"
	@echo "\033[0m"

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f libmlx.dylib
	@rm -f $(NAME)
	@echo "\033[31m"
	@cat ./art/fclean
	@echo ""
	@echo "$(NAME) is deleted"
	@echo "\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
