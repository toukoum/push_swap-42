NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MAIN = srcs/main.c
SRCS = $(wildcard srcs/*.c)
SRCS_BONUS = $(filter-out $(MAIN), $(wildcard srcs/*.c)) $(wildcard srcs_bonus/*.c)
DEPS = $(wildcard includes/*.h)

LIBFT_DIR = libft/
LIBFT_LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(SRCS) $(DEPS) 
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(LIBFT_LIB) $(DEPS) $(SRCS_BONUS)
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT_LIB) -o $(NAME_BONUS)

clean:
	make clean -C $(LIBFT_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
