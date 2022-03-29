# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 10:39:23 by gponti-s          #+#    #+#              #
#    Updated: 2021/07/25 10:39:26 by gponti-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= $(shell find src -type f -name "*.c")
LIB = $(shell find libft -type f -name "*.a")
INCLUDE	= $(addprefix -I, include)
OBJS	=$(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long

all: libft $(NAME)

libft:
	@$(MAKE) -C libft/

$(NAME):	libft $(OBJS)
	@$(CC) -o $(NAME) $(CFLAGS) $(INCLUDE) $(LIB) $(OBJS) -lmlx -framework OpenGL -framework AppKit

.c.o:
	@echo "Creating object: $@"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C libft/ clean

fclean:
	@$(MAKE) -C libft/ fclean
	@rm -f $(OBJS)
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re libft $(NAME)