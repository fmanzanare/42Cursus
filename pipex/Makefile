# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 12:54:56 by fmanzana          #+#    #+#              #
#    Updated: 2022/09/14 18:04:33 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = ./sources/test.c \

OBJDIR = ./objects/
OBJS = $(addsuffix .o, $(notdir $(basename $(SRCS))))

LIBFT = ./includes/libft_plus/libft.a
LIBFT_LINK = -L./includes/libft_plus -lft
FT_PRINTF_LINK = -L./includes/libft_plus/ft_printf -lftprintf

all:		obj $(NAME) 

obj:		$(OBJS)
			@mkdir $(OBJDIR)
			@mv $(OBJS) $(OBJDIR)

$(OBJS):	$(SRCS)
			@$(CC) $(CFLAGS) -c $(SRCS)

$(NAME):	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(addprefix $(OBJDIR), $(OBJS)) $(LIBFT_LINK) $(FT_PRINTF_LINK) -o $(NAME)
			@echo "Compilación done!"

$(LIBFT):
			@make -C ./includes/libft_plus

clean:
			@rm -rf $(OBJDIR)
			@make -C ./includes/libft_plus clean

fclean:		clean
			@rm -f $(NAME)
			@make -C ./includes/libft_plus fclean
			@echo "Limpieza TOTAL done!"

re:			fclean, all

.PHONY: all, clean, fclean, re
