NAME=rush-01

SRCS =	*.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cc $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
