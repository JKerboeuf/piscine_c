NAME=ft_display_file

SRCS =	ft_display_file.c

OBJS = $(SRCS:.c=.o)

INC = includes

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