CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -g3

EXNAME = so_long
BEXNAME = so_long_bonus

LIBFT_DIR = includes/libft
PRINTF_DIR = includes/ft_printf
GET_NEXT_DIR = includes/get_next_line
MLX_DIR = includes/.minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBS = $(LIBFT) $(PRINTF)

SRCS = mandatory/so_long.c \
       mandatory/parsing_mapping/ber_map.c \
       mandatory/parsing_mapping/map.c \
       mandatory/parsing_mapping/flood_fill.c \
       mandatory/mlx/mlx.c \
       mandatory/mlx/mlx_helper.c \
       $(GET_NEXT_DIR)/get_next_line.c \
       $(GET_NEXT_DIR)/get_next_line_utils.c

BSRCS = bonus/so_long_bonus.c \
        bonus/parsing_mapping/ber_map_bonus.c \
        bonus/parsing_mapping/map_bonus.c \
        bonus/parsing_mapping/flood_fill_bonus.c \
        bonus/mlx/mlx_bonus.c \
        bonus/mlx/mlx_helper_bonus.c \
        bonus/mlx/mlx_helper_two_bonus.c \
        $(GET_NEXT_DIR)/get_next_line.c \
        $(GET_NEXT_DIR)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(EXNAME)

bonus: $(BEXNAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(EXNAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -L$(MLX_DIR) -lmlx -lXext -lX11 -o $(EXNAME)

$(BEXNAME): $(BOBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(BOBJS) $(LIBS) -L$(MLX_DIR) -lmlx -lXext -lX11 -o $(BEXNAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(EXNAME) $(BEXNAME)

re: fclean all

.PHONY: all bonus clean fclean re
