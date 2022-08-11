NAME = minitalk

SRCS = server.c client.c

CC = cc

CFLAGS = -Wextra -Wall -Werror

LIBFT = ./libft/libft.a

LIBFT_DIR = ./libft/

all: $(NAME)

$(NAME): server client

server: $(LIBFT) server.c
	$(CC) $(CFLAGS) server.c $(LIBFT) -o server

client: $(LIBFT) client.c
	$(CC) $(CFLAGS) client.c $(LIBFT) -o client

bonus: server_bonus client_bonus

server_bonus: $(LIBFT) server_bonus.c
	$(CC) $(CFLAGS) server_bonus.c $(LIBFT) -o server_bonus

client_bonus: $(LIBFT) client_bonus.c
	$(CC) $(CFLAGS) client_bonus.c $(LIBFT) -o client_bonus

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f server client server_bonus client_bonus
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: $(NAME) all bonus libft clean fclean re
