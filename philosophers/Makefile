# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 16:27:25 by fmanzana          #+#    #+#              #
#    Updated: 2023/02/25 16:33:42 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix ./src/, main_philo.c)

OBJS = $(addsuffix .o, $(notdir $(basename $(SRCS))))

all:		$(NAME)

$(OBJS):	$(SRCS)
			@$(CC) $(CFLAGS) -g -c $(SRCS)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -g -o $(NAME)
			@echo "Compilación done!"

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)
			@echo "Limpieza TOTAL done!"

re:			fclean all

.PHONY: all, clean, fclean, re
