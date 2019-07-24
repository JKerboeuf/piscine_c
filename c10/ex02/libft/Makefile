NAME=libft.a

SRCS =	srcs/ft_atoi.c \
		srcs/ft_putchar.c \
		srcs/ft_putnbr.c \
		srcs/ft_putstr.c \
		srcs/ft_recursive_power.c \
		srcs/ft_split.c \
		srcs/ft_sqrt.c \
		srcs/ft_str_is_alpha.c \
		srcs/ft_str_is_lowercase.c \
		srcs/ft_str_is_numeric.c \
		srcs/ft_str_is_printable.c \
		srcs/ft_str_is_uppercase.c \
		srcs/ft_strcat.c \
		srcs/ft_strcmp.c \
		srcs/ft_strcpy.c \
		srcs/ft_strdup.c \
		srcs/ft_strjoin.c \
		srcs/ft_strlcat.c \
		srcs/ft_strlcpy.c \
		srcs/ft_strlen.c \
		srcs/ft_strlowcase.c \
		srcs/ft_strncat.c \
		srcs/ft_strncmp.c \
		srcs/ft_strncpy.c \
		srcs/ft_strstr.c \
		srcs/ft_strupcase.c

OBJS = $(SRCS:.c=.o)

INC = includes

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(INC) -c $^ -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

del:
	rm -f $(NAME)

fclean: clean del

re: fclean all
