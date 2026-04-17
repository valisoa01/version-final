NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -I. -I$(LIBFT_DIR)

SRCS        = main.c \
              ft_select_strategy.c \
              ft_parse_args.c \
              ft_errors.c \
              fill_values.c \
              ft_parse_flag.c \
              ft_valid_number.c \
              ft_sort_simple.c \
              ft_selection_sort.c \
              ft_sort_medium.c \
              ft_medium_utils.c \
              ft_medium_chunk.c \
              ft_medium_push.c \
              ft_medium_restore.c \
              ft_sort_complex.c \
              ft_radix_utils.c \
              ft_radix_sort.c \
              ft_sort_adaptive.c \
              ft_compute_disorder.c \
              ft_stack_utils.c \
              ft_benchmark.c \
              ft_small_sort.c \
              ft_swap.c \
              ft_push.c \
              ft_rotate.c \
              ft_reverse_rotate.c \
              parse_utils.c\
              flag_utils.c
OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -L$(LIBFT_DIR) -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) --no-print-directory

re: fclean all

.PHONY: all clean fclean re