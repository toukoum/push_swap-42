NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCS = $(wildcard srcs/*.c)
DEPS = $(wildcard includes/*.h)

LIBFT_DIR = libft/
LIBFT_LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(SRCS) $(DEPS) 
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

