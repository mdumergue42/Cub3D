SHELL = bash

NAME = cub3D

CC = gcc

OBJSDIR = obj/

SRCDIR = src/

I_DIR = includes/

LIBFT_DIR = libft/

MACRO_DIR = MacroLibX/

INCLUDE = -I $(I_DIR) -I $(LIBFT_DIR)/$(I_DIR) -I $(MACRO_DIR)/$(I_DIR)

SRCS = src/utils/mess_error.c \
	   src/utils/parse_utils.c \
	   src/utils/parse_utils_two.c \
	   src/utils/parse_utils_three.c \
	   src/utils/utils.c \
	   src/utils/clear_free.c \
	   src/parsing/check_image.c \
	   src/parsing/check_map.c \
	   src/parsing/check_arg.c \
	   src/parsing/check_id_text.c \
	   src/parsing/check_rgb.c \
	   src/parsing/color_utils.c \
	   src/parsing/find_player.c \
	   src/parsing/principal_pars.c \
	   src/cub3d.c

OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))

FLAGS = -Wall -Werror -Wextra -g -lm -lSDL2

LIB = libft/libft.a \
	  MacroLibX/libmlx.so

$(NAME): $(OBJS)
	@make -sj $(nproc) -C $(LIBFT_DIR)
	@echo "✅ Libft compiled"
	@make -sj $(nproc) -C $(MACRO_DIR) > /dev/null
	@echo "✅ MacroLibX compiled"
	@$(CC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "✅ Compiled"

$(OBJSDIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDE) $(FLAGS) $< -c -o $@

all: $(NAME)

clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MACRO_DIR) clean > /dev/null
	@rm -f $(OBJS)

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@echo "🧹 Libft Cleaned"
	@make -s -C $(MACRO_DIR) fclean > /dev/null
	@echo "🧹 MacroLibX Cleaned"
	@rm -f $(NAME)
	@rm -Rf $(OBJSDIR)
	@echo "🧹 Cleaned"

re: fclean all

.PHONY: clean all re fclean
