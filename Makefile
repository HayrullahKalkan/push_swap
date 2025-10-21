NAME = push_swap
SRC = push_swap.c push.c parser.c swap.c lst_function.c \
	  rotate.c rotate_re.c sort_helper.c cost.c utils.c sort_helper_utils.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
