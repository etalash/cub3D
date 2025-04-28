
NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putdigit.c ft_putstr.c ft_strchr.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
