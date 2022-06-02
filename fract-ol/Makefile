# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 15:37:23 by fmanzana          #+#    #+#              #
#    Updated: 2022/06/02 18:20:53 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = test.c

OBJS = ${SRCS:.c=.o}

MLX = mlx/libmlx.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Imlx -c

RM = rm -f

all: 		$(NAME)

$(MLX):		$(MLX)
			make -C ./mlx

$(NAME):	${OBJS} $(MLX)
			$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)
			
%.o: %.c
			$(CC) $(CFLAGS) $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all, clean, fclean, re
