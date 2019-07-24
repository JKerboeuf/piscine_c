NAME=libft.a

SRCS =	srcs/ft_putchar.c \
		srcs/ft_swap.c \
		srcs/ft_putstr.c \
		srcs/ft_strlen.c \
		srcs/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

INC = includes

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(INC) -c $^ -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all