SRCS = server.c client.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wextra -Wall -Werror

all: server client

bonus: server client







clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
