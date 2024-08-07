CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = main.c mandelbrot.c julia.c setting.c hook.c input.c ft_printf.c move.c move_1.c
NAME = fractol
OBJS = $(SRCS:.c=.o)
LIB = libft/libft.a
all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	CC $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ $(LIB) -o $@

%.o: %.c
	cc $(CFLAGS) -Imlx -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus