# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 16:03:32 by nide-mel          #+#    #+#              #
#    Updated: 2021/09/23 17:12:19 by nide-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -f
LIBX = -lmlx -framework OpenGL -framework AppKit

HEADER = ./includes/$(wildcard *.h)

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
MINILIBX_DIR = minilibx_mms_20200219

INCLUDES = -I libft/includes -I ./includes

SRC_PATH = ./src

OBJ_PATH = ./obj

SRC_NAME =	main.c\
			init_struct.c\
			utils.c\
			map/checkers_map.c\
			map/map_functions.c\
			map/organize_map.c\
			render/init_images.c\
			render/render_img.c\

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all : $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(MAKE) -C $(MINILIBX_DIR)
	@mv $(MINILIBX_DIR)/libmlx.dylib .
	@echo "\x1b[32m"
	@cat ./art/ok
	@echo ""
	@$(CC) $(CFLAGS) $(OBJ) $(LIBX) $(INCLUDES) $(LIBFT) -o $(NAME)
	@echo "[$(NAME) compiled]"
	@echo "\x1b[0m"


$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p obj
	@mkdir -p obj/map
	@mkdir -p obj/render
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
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
