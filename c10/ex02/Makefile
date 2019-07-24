NAME=ft_tail

LIB=libft.a

SRCS =	srcs/ft_tail.c \
		srcs/error.c \
		srcs/ft_putstr_fd.c \
		srcs/read.c

OBJS = $(SRCS:.c=.o)

INC = -I includes -I libft/includes

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) $(INC) -c $^ -o $@

$(NAME): $(OBJS)
	make -C libft
	gcc $(FLAGS) $(OBJS) -L libft -lft -o $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJS)

del:
	make del -C libft
	rm -f $(NAME)

fclean: clean del

re: fclean all
