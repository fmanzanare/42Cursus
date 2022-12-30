# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 11:29:11 by fmanzana          #+#    #+#              #
#    Updated: 2022/12/30 15:11:33 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix ./src/, init_stks.c large_sort.c mem_free.c movements.c position_and_cost_calc.c push.c reverse_r.c rotate.c small_sort.c stks_utils.c swap.c utils.c)
SRC_MAND = $(addprefix ./src_push_swap/, main.c)
SRC_BONUS = $(addprefix ./src_bonus/, checker.c)

OBJDIR = ./objects/
OBJS = $(addsuffix .o, $(notdir $(basename $(SRCS))))
OBJ_PUSH_SWAP = $(addsuffix .o, $(notdir $(basename $(SRC_MAND))))
OBJ_BONUS = $(addsuffix .o, $(notdir $(basename $(SRC_BONUS))))

LIBFT = ./includes/libft_plus/libft.a
LIBFT_LINK = -L./includes/libft_plus -lft
FT_PRINTF_LINK = -L./includes/libft_plus/ft_printf -lftprintf

all:		obj $(NAME)

obj:
			@rm -rf $(OBJDIR)
			@mkdir $(OBJDIR)

$(OBJS):	$(SRCS) $(SRC_MAND)
			@$(CC) $(CFLAGS) -g -c $(SRCS) $(SRC_MAND)

$(NAME):	$(OBJS) $(LIBFT)
			@mv $(OBJS) $(OBJ_PUSH_SWAP) $(OBJDIR)
			@$(CC) $(CFLAGS) $(addprefix $(OBJDIR), $(OBJS)) $(addprefix $(OBJDIR), $(OBJ_PUSH_SWAP)) $(LIBFT_LINK) $(FT_PRINTF_LINK) -g -o $(NAME)
			@echo "Compilación done!"

$(LIBFT):
			@make -C ./includes/libft_plus

$(OBJ_BONUS):	$(SRCS) $(SRC_BONUS)
			@$(CC) $(CFLAGS) -g -c $(SRCS) $(SRC_BONUS)

bonus:		obj $(OBJ_BONUS) $(LIBFT)
			@mv $(OBJS) $(OBJ_BONUS) $(OBJDIR)
			@$(CC) $(CFLAGS) $(addprefix $(OBJDIR), $(OBJS)) $(addprefix $(OBJDIR), $(OBJ_BONUS)) $(LIBFT_LINK) $(FT_PRINTF_LINK) -g -o checker
			@echo "Checker done!"
clean:
			@rm -rf $(OBJDIR)
			@rm -f ./*.o
			@make -C ./includes/libft_plus clean

fclean:		clean
			@rm -f $(NAME) checker
			@make -C ./includes/libft_plus fclean
			@echo "Limpieza TOTAL done!"

re:			fclean all

.PHONY: all, obj, bonus, clean, fclean, re
