# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 12:54:56 by fmanzana          #+#    #+#              #
#    Updated: 2023/02/11 14:24:18 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix ./src/, main_pipex.c command_functions.c processes_functions.c)

OBJS = $(addsuffix .o, $(notdir $(basename $(SRCS))))

LIBFT = ./includes/libft_plus/libft.a
LIBFT_LINK = -L./includes/libft_plus -lft
FT_PRINTF_LINK = -L./includes/libft_plus/ft_printf -lftprintf

all:		$(NAME)

$(OBJS):	$(SRCS)
			@$(CC) $(CFLAGS) -g -c $(SRCS)

$(NAME):	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LINK) $(FT_PRINTF_LINK) -g -o $(NAME)
			@echo "Compilación done!"

$(LIBFT):
			@make -C ./includes/libft_plus

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -f $(NAME)
			@make -C ./includes/libft_plus fclean
			@echo "Limpieza TOTAL done!"

re:			fclean all

.PHONY: all, clean, fclean, re
