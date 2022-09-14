# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 11:08:13 by fmanzana          #+#    #+#              #
#    Updated: 2022/09/14 12:14:32 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCDIR = ./sources/
SRCS = test.c \

OBJDIR = ./objects/
OBJS = $(addprefix $(OBJDIR), $(SRCS):.c=.o))

LIBFT = ./includes/libft_plus/libft.a
LIBFT_DIR = ./includes/libft_plus/
LIBFT_LINK = -L ./includes/libft_plus -l ft

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

all: obj $(LIBFT) $(NAME)

obj:
			@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
			$(CC) $(CFLAGS) -I $(LIBFT_DIR) -g -o $@ -c $<

$(LIBFT):
			@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
			@$(CC) $(OBJS) $(LIBFT_LINK) -o $(NAME)
			@echo "Compilación done!"

clean:
			@rm -rf $(OBJDIR)
			@make -C $(LIBFT_DIR) clean

fclean:
			@rm -f $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@echo "Limpieza TOTAL done!"

re: fclean all

.PHONY: all, obj, clean, fclean, re
