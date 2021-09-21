# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 16:03:32 by nide-mel          #+#    #+#              #
#    Updated: 2021/09/21 21:32:22 by nide-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -f

HEADER = ./includes/$(wildcard *.h)

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

INCLUDES = -I libft/includes -I ./includes

SRC_PATH = ./src/*

OBJ_PATH = ./obj

SRC_NAME =	main.c\
			init_struct.c\
			utils.c\
			checkers_map.c\
			map_functions.c\
			organize_map.c\
			init_images.c\

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all : $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@echo "\x1b[32m"
	@cat ./art/ok
	@echo ""
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBFT) -o $(NAME)
	@echo "[$(NAME) compiled]"
	@echo "\x1b[0m"


$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p obj
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
	@rm -f $(NAME)
	@echo "\033[31m"
	@cat ./art/fclean
	@echo ""
	@echo "$(NAME) is deleted"
	@echo "\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
