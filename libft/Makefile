NAME = libft.a

DEPS = ./libft_mandatory/includes/libft.h ./gnl/includes/get_next_line_bonus.h ./ft_printf/includes/ft_printf.h

PRINTF_SRCS = $(wildcard ./ft_printf/srcs/*.c)
GNL_SRCS = $(wildcard ./gnl/srcs/*.c)
LIBFT_SRCS = $(wildcard ./libft_mandatory/srcs/*.c)

SRC = $(LIBFT_SRCS) $(PRINTF_SRCS) $(GNL_SRCS)
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RED=\033[0;31m
ROSE=\033[0;95m
GREEN=\033[0;32m
NC=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(ROSE)Creating library $(NAME)...$(NC)"
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(DEPS)
	@echo "$(GREEN)Compiling $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Cleaning library $(NAME)...$(NC)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
