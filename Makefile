#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 21:36:03 by ccodere           #+#    #+#              #
# **************************************************************************** #

NAME = so_long

CC = gcc

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx

MLX = $(MLX_DIR)/libmlx.a

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

SRC_DIR = source

SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(SRC:.c=.o)

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m

all: libs $(NAME)

libs:
	$(MAKE) -C $(MLX_DIR) all
	$(MAKE) -C $(LIBFT_DIR) all

%.o: %.c
	@echo -e "$(GREEN)Compiling: $< $(RESET)"
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@echo -e "$(YELLOW)Compiling : [$(SRC)] ...$(RESET)"
	@echo -e "$(GREEN)Completed : [$(SRC)] !$(RESET)"
	@echo
	@echo -e "$(YELLOW)Compiling : [$(NAME)] ...$(RESET)"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX) $(LIBFT) -o $(NAME)
	@echo -e "$(GREEN)Completed : [$(NAME)] !$(RESET)"

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	@echo -e "$(RED)Deleted : [$(OBJ)] $(RESET)"

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/libft.a
	@echo -e "$(RED)Deleted : [$(NAME)] [$(LIBFT)] $(RESET)"

re: fclean all

norm:
	norminette $(LIBFT_DIR) $(SRC)

.PHONY: all clean fclean re