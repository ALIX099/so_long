CC = cc

FLAGS = -Wall -Wextra -Werror

SRCs = ft_hex.c  ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_print_addr.c ft_putnbr_unsigned.c

OBJs = $(SRCs:.c=.o)

NAME = libftprintf.a

all: $(OBJs)
	ar rcs $(NAME) $(OBJs)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJs)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
