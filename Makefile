SRCS =	ft_printf.c \
ft_putchar.c ft_putstr.c ft_putptr.c \
ft_putnbr_base.c ft_unsigned_putnbr_base.c \
ft_strchr.c

OBJS  = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
			ar crs $(NAME) $(OBJS)

bonus: $(OBJS_B)
			ar crs $(NAME)

.c.o:
	gcc -Werror -Wextra -Wall -c $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
