SRCS =	ft_printf.c

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
