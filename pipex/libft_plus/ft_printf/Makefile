# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 16:33:24 by fmanzana          #+#    #+#              #
#    Updated: 2022/09/13 13:05:11 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_utils.c \
	   ft_printf.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	${OBJS}
			@gcc $(CFLAGS) -c $(SRCS)
			@ar crs ${NAME} ${OBJS}

.c.o:		$(SRCS)
			@gcc $(CFLAGS) -c $(SRCS)
			@echo "Librería FT_PRINTF done!"

clean:
			@rm -rf ${OBJS}

fclean:		clean
			@rm -rf ${NAME}
			@echo "Limpieza FT_PRINTF done!"

re:			fclean all

.PHONY: all, clean, fclean, re
