NAME    = push_swap
CC      = gcc
CFLAGS  = -Werror -Wextra -Wall

SRC_PATH    = src/
OBJ_PATH    = obj/

LIBFT = libft/libft.a
PRINTF = ft_printf/ft_printf.a

SRC         = \
	radix_sort.c \
    dllistfunctions.c \
    alg.c \
    operations.c \
	operations_two.c \
    push_swap.c \
    main.c \
    error_and_checks.c

SRCS        = $(addprefix $(SRC_PATH), $(SRC))

OBJ         = $(SRC:.c=.o)
OBJS        = $(addprefix $(OBJ_PATH), $(OBJ))

INC         = -I ./include/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(MAKE) all -C libft
	$(MAKE) all -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re
