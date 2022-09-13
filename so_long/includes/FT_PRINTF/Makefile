# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 16:33:24 by fmanzana          #+#    #+#              #
#    Updated: 2022/09/13 09:52:41 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_utils.c ft_printf.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

.c.o:		$(SRCS)
			@$(CC) -c $(CFLAGS) $(SRCS)
			@echo "Librería FT_PRINTF done!"

$(NAME):	${OBJS}
			@ar crs ${NAME} ${OBJS}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}
			@echo "Limpieza FT_PRINTF done!"

re:			fclean all

.PHONY: all, clean, fclean, re
