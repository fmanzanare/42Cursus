# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 11:29:11 by fmanzana          #+#    #+#              #
#    Updated: 2022/12/30 14:21:15 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = ./src/*.c

OBJDIR = ./objects/
OBJDIR_BONUS = ./objects_bonus/
OBJS = $(addsuffix .o, $(notdir $(basename $(SRCS))))

LIBFT = ./includes/libft_plus/libft.a
LIBFT_LINK = -L./includes/libft_plus -lft
FT_PRINTF_LINK = -L./includes/libft_plus/ft_printf -lftprintf

all:		obj $(NAME)

obj:
			@rm -rf $(OBJDIR)
			@mkdir $(OBJDIR)

$(OBJS):	$(SRCS)
			@$(CC) $(CFLAGS) -g -c $(SRCS)

$(NAME):	$(OBJS) $(LIBFT)
			@mv $(OBJS) $(OBJDIR)
			@$(CC) $(CFLAGS) $(addprefix $(OBJDIR), $(OBJS)) $(LIBFT_LINK) $(FT_PRINTF_LINK) -g -o $(NAME)
			@echo "Compilación done!"

$(LIBFT):
			@make -C ./includes/libft_plus

clean:
			@rm -rf $(OBJDIR) $(OBJDIR_BONUS)
			@rm -f ./*.o
			@make -C ./includes/libft_plus clean

fclean:		clean
			@rm -f $(NAME) checker
			@make -C ./includes/libft_plus fclean
			@echo "Limpieza TOTAL done!"

re:			fclean all

.PHONY: all, obj, clean, fclean, re
