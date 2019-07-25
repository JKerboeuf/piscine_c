RED = \033[31m
GREEN = \033[32m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

NAME = libft.a
DIR_NAME = libft

SRCS_DIR = srcs
SRCS =	ft_atoi.c \
		ft_atol.c \
		ft_memalloc.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putnbr.c \
		ft_putnbrnl.c \
		ft_putnbr_fd.c \
		ft_putnbrnl_fd.c \
		ft_putstr.c \
		ft_putstrnl.c \
		ft_putstr_fd.c \
		ft_putstrnl_fd.c \
		ft_realloc.c \
		ft_split.c \
		ft_str_is_alpha.c \
		ft_str_is_lowercase.c \
		ft_str_is_numeric.c \
		ft_str_is_printable.c \
		ft_str_is_uppercase.c \
		ft_strcat.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strlowcase.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strstr.c \
		ft_strupcase.c

OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

INC = -I $(INC_DIR)
INC_DIR = includes

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "$(GREEN)Compiling $(BLUE)$^$(WHITE) > $(CYAN)$@$(WHITE)"
	@gcc $(FLAGS) $(INC) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS_PRE)
	@echo "$(GREEN)Compiling $(MAGENTA)$(NAME)$(WHITE) < $(CYAN).o files$(WHITE)"
	@ar rcs $(NAME) $(OBJS_PRE)

clean:
	@echo "$(RED)Removed $(CYAN)objs from $(DIR_NAME)$(WHITE)"
	@rm -rf $(OBJS_DIR)

del:
	@echo "$(RED)Removed $(MAGENTA)$(NAME)$(WHITE)"
	@rm -f $(NAME)

fclean: clean del

re: fclean all
