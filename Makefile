CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SOURCES = main.c \
		  parse.c \
		  parse_utils.c \
		  check_flags.c \
		  choose_algorytm.c \
		  stack_utils.c \
		  rank_stack.c \
		  ft_utils.c \
		  ops_swap.c \
		  ops_push.c \
		  ops_rotate.c \
		  ops_rrotate.c \
		  bubble_sort.c \
		  chunk_sort.c \
		  radix_sort.c \
		  insertion_sort.c \
		  adptative_sort.c \
		  disorder.c \
		  show_benchmark.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
