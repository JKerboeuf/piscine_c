NAME=do-op

SRCS =	srcs/main.c \
		srcs/ope.c \
		srcs/ft_put.c

OBJS = $(SRCS:.c=.o)

INC = srcs

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(INC) -c $^ -o $@

$(NAME): $(OBJS)
	gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
