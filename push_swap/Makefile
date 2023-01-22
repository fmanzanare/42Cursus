# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 11:29:11 by fmanzana          #+#    #+#              #
#    Updated: 2023/01/22 17:28:13 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix ./src/, init_stks.c large_sort.c mem_free.c movements.c position_and_cost_calc.c push.c reverse_r.c rotate.c small_sort.c stks_utils.c swap.c utils.c)
SRC_MAND = $(addprefix ./src_push_swap/, main.c)
SRC_BONUS = $(addprefix ./src_bonus/, checker.c)

OBJS = $(addsuffix .o, $(notdir $(basename $(SRCS))))
OBJ_PUSH_SWAP = $(addsuffix .o, $(notdir $(basename $(SRC_MAND))))
OBJ_BONUS = $(addsuffix .o, $(notdir $(basename $(SRC_BONUS))))

LIBFT = ./includes/libft_plus/libft.a
LIBFT_LINK = -L./includes/libft_plus -lft
FT_PRINTF_LINK = -L./includes/libft_plus/ft_printf -lftprintf

all:		$(NAME)

$(OBJS):	$(SRCS)
			@$(CC) $(CFLAGS) -g -c $(SRCS)

$(OBJ_PUSH_SWAP):	$(SRC_MAND)
			@$(CC) $(CFLAGS) -g -c $(SRC_MAND)

$(NAME):	$(OBJS) $(OBJ_PUSH_SWAP) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJS) $(OBJ_PUSH_SWAP) $(LIBFT_LINK) $(FT_PRINTF_LINK) -g -o $(NAME)
			@echo "Compilación done!"

$(LIBFT):
			@make -C ./includes/libft_plus

$(OBJ_BONUS):	$(SRC_BONUS)
			@$(CC) $(CFLAGS) -g -c $(SRC_BONUS)

bonus:		$(OBJS) $(OBJ_BONUS) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJS) $(OBJ_BONUS) $(LIBFT_LINK) $(FT_PRINTF_LINK) -g -o $(NAME_BONUS)
			@echo "Checker done!"

clean:
			@rm -f $(OBJS) $(OBJ_PUSH_SWAP) $(OBJ_BONUS)
			@make -C ./includes/libft_plus clean

fclean:		clean
			@rm -f $(NAME) $(NAME_BONUS)
			@make -C ./includes/libft_plus fclean
			@echo "Limpieza TOTAL done!"

re:			fclean all

.PHONY: all bonus clean fclean re
