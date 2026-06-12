CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap

LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a
CFLAGS   += -I$(LIBFT_DIR)

SOURCES = main.c \
          parse.c \
          choose_algorytm.c \
          stack_utils.c \
          rank_stack.c \
          ops_swap.c \
          ops_push.c \
          ops_rotate.c \
          ops_rrotate.c \
          bubble_sort.c \
          chunk_sort.c \
          radix_sort.c \
          adptative_sort.c \
          sort3.c \
          sort5.c \
          disorder.c \
          show_benchmark.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

# This rule triggers the libft Makefile if libft.a is missing or needs updating
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Link push_swap with your object files AND the compiled libft.a
$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean push_swap objects, and call libft's clean rule
clean:
	rm -f $(OBJECTS)
	@make -C $(LIBFT_DIR) clean

# Full clean for push_swap, and call libft's fclean rule
fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re