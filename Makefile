NAME: minitalk

SRCS = server.c client.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wextra -Wall -Werror

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): server client

server: $(LIBFT) server.c
	$(CC) $(CFLAGS) server.c -o server -Llibft -lft

client: $(LIBFT) client.c
	$(CC) $(CFLAGS) client.c -o client -Llibft -lft

bonus: server client

$(LIBFT):
	make -C libft


clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: $(NAME) all bonus libft clean fclean re
