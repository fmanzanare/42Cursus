# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana < fmanzana@student.42malaga.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 13:44:37 by fmanzana          #+#    #+#              #
#    Updated: 2022/05/13 15:28:36 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

LIBFT = LIBFT

DIR_S = sources

DIR_O = obj

HEADER = includes

SOURCES = 

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all = $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT)
		@cp LIBFT/libft.a ./$(NAME)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.C $(HEADER)/ft_printf.h
		@mkdir -p obj
		@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
		norminette ./LIBFT/
		@echo
		norminette ./$(HEADER)/
		@echo
		norminette ./$(DIR_S)/

clean:
		@rm -f $(OBJS)
		@rm -rf $(DIR_O)
		@make clean -C $(LIBFT)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT)

re: fclean all

bonus: re

.PHONY: fclean re norme all clean
