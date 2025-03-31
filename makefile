CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

EXNAME = so_long

LIBFT_DIR = includes/libft
PRINTF_DIR = includes/ft_printf
GET_NEXT_DIR= includes/get_next_line

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBS = $(LIBFT) $(PRINTF)

SRCS = mandatory/so_long.c \
	   mandatory/parsing.c \
	   mandatory/load_map.c 

OBJS = $(SRCS:.c=.o)

all: $(EXNAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(EXNAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(EXNAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -rf $(EXNAME)

re: fclean all

.PHONY: all clean fclean re
