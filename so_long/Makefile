# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 15:37:23 by fmanzana          #+#    #+#              #
#    Updated: 2022/09/13 09:54:46 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main_so_long.c\
		so_long_utils.c\
		map_control_functions.c\
		perimeter_control_functions.c\
		images_functions.c\
		hooks_functions.c\
		pj_moving_functions.c

OBJS = $(addprefix $(OBJDIR), ${SRCS:.c=.o})

MLX = mlx/libmlx.a

LIBFT = LIBFT/libft.a

FT_PRINTF = FT_PRINTF/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Imlx

OBJDIR = ./objects/

SRCDIR = ./sources/

all: 		obj $(NAME)

obj:
			@mkdir -p $(OBJDIR)

$(MLX):
			@make -C ./includes/mlx

$(LIBFT):
			@make -C ./includes/LIBFT

$(FT_PRINTF):
			@make -C ./includes/FT_PRINTF

$(NAME):	${OBJS} $(MLX) $(LIBFT) $(FT_PRINTF)
			@$(CC) $(OBJS) -L./includes/ft_printf -lftprintf -L./includes/libft -lft -L./includes/mlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)
			@echo "Compliación realizada!"
			
$(OBJDIR)%.o: $(SRCDIR)%.c
			@$(CC) -c $(CFLAGS) $< -o $@

clean:
			@rm -rf $(OBJDIR)
			@make -C ./includes/FT_PRINTF clean
			@make -C ./includes/LIBFT clean
			@make -C ./includes/mlx clean

fclean:		clean
			@rm -f ${NAME}
			@make -C ./includes/FT_PRINTF fclean
			@make -C ./includes/LIBFT fclean
			@echo "Limpieza TOTAL done!"

re:			fclean all

.PHONY: all, clean, fclean, re
