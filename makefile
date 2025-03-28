CC = cc

CFLAGS = -Wall -Wextra -Werror

EXNAME = so_long

LIBFT_DIR = includes/libft
PRINTF_DIR = includes/ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libprintf.a

LIBS = $(LIBFT) $(PRINTF)

SRCS = mandatory/main.c \
       mandatory/game.c \
       mandatory/map.c \
       mandatory/render.c \
       mandatory/utils.c

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
