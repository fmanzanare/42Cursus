# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 15:37:23 by fmanzana          #+#    #+#              #
#    Updated: 2022/09/12 13:00:07 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main_so_long.c so_long_utils.c map_control_functions.c perimeter_control_functions.c images_functions.c hooks_functions.c pj_moving_functions.c

OBJS = ${SRCS:.c=.o}

MLX = mlx/libmlx.a

LIBFT = LIBFT/libft.a

FT_PRINTF = FT_PRINTF/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Imlx -c

RM = rm -f

all: 		$(NAME)

$(MLX):		$(MLX)
			make -C ./mlx

$(LIBFT):	$(LIBFT)
			make -C ./LIBFT

$(FT_PRINTF):	$(FT_PRINTF)
			make -C ./FT_PRINTF/

$(NAME):	${OBJS} $(MLX) $(LIBFT) $(FT_PRINTF)
			$(CC) $(OBJS) -Lft_printf -lftprintf -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)
			
%.o: %.c
			$(CC) $(CFLAGS) $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all, clean, fclean, re
