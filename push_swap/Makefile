NAME = push_swap

SRCS = 

OBJS = ${SRCS:.c=.o}

LIBFT = LIBFT/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all:		$(NAME)

$(LIBFT):	$(LIBFT)
		make -C ./LIBFT

$(NAME):	$(OBJS) $(LIBFT)
		$(CC) $(OBJS) -Llibft -lft -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $< -o $@

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all, clean, fclean, re
