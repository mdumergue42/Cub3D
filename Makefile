NAME = cub3D

CC = gcc

OBJSDIR = obj/

SRCDIR = src/

I_DIR = includes/

LIBFT_DIR = libft/

INCLUDE = -I $(I_DIR) -I $(LIBFT_DIR)/$(I_DIR)

SRCS = $(shell find src -name '*.c')

OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))

FLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a

$(NAME): $(OBJS)
	@make -sj $(nproc) -C libft
	@$(CC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "✅ Compiled"

$(OBJSDIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDE) $(FLAGS) $< -c -o $@

all: $(NAME)

clean:
	@make -s -C libft clean
	@rm -f $(OBJS)

fclean: clean
	@make -s -C libft fclean
	@rm -f $(NAME)
	@rm -Rf $(OBJSDIR)
	@echo "🧹 Cleaned"

re: fclean all

.PHONY: clean all re fclean
