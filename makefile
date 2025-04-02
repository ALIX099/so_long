CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx #-lmlx -lXext -lX11

EXNAME = so_long

LIBFT_DIR = includes/libft
PRINTF_DIR = includes/ft_printf
GET_NEXT_DIR = includes/get_next_line
MLX_DIR = includes/.minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a

LIBS = $(LIBFT) $(PRINTF) $(MLX)

SRCS = mandatory/so_long.c \
       mandatory/parsing_mapping/ber_map.c \
       mandatory/parsing_mapping/map.c \
	   mandatory/parsing_mapping/flood_fill.c \
	   mandatory/mlx/mlx.c \
	   mandatory/mlx/mlx_helper.c \
       $(GET_NEXT_DIR)/get_next_line.c \
       $(GET_NEXT_DIR)/get_next_line_utils.c

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
