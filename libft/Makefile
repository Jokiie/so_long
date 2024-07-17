# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 12:04:14 by ccodere           #+#    #+#              #
#    Updated: 2024/07/11 17:52:16 by ccodere          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

HEADER = libft.h

RM = rm -rf

# Files
SRCS = $(wildcard *.c)
 
OBJECTS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) 
	ar -rcs $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
