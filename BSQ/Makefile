RED = \033[31m
GREEN = \033[32m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

NAME = bsq
DIR_NAME = BSQ_tmp

LIBFT_DIR = libft
LIBFT = -L $(LIBFT_DIR) -lft

FLAGS = -Wall -Wextra -Werror

INCS = $(INC)
INC = -I includes -I $(LIBFT_DIR)/includes

OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

SRCS_DIR = srcs
SRCS =	main.c \
		hunt.c \
		display.c \
		init.c \
		read.c \
		check.c \
		free.c

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "$(GREEN)Compiling $(BLUE)$^$(WHITE) > $(CYAN)$@$(WHITE)"
	@gcc $(FLAGS) $(INCS) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS_PRE)
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)Compiling $(MAGENTA)$(NAME)$(WHITE) < $(CYAN).o files$(WHITE)"
	@gcc $(FLAGS) $(OBJS_PRE) $(LIBFT) -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)Removed $(CYAN)objs from $(DIR_NAME)$(WHITE)"
	@rm -rf $(OBJS_DIR)

del:
	@make del -C $(LIBFT_DIR)
	@echo "$(RED)Removed $(MAGENTA)$(NAME)$(WHITE)"
	@rm -rf $(NAME)

fclean: clean del

re: fclean all
