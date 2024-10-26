# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 16:02:18 by adjoly            #+#    #+#              #
#    Updated: 2024/10/19 15:15:37 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash

NAME = cub3D

CC = cc

OBJSDIR = obj/

SRCDIR = src/

I_DIR = includes/

LIBFT_DIR = libft/

MACRO_DIR = MacroLibX/

INCLUDE = -I $(I_DIR) -I $(LIBFT_DIR)/$(I_DIR) -I $(MACRO_DIR)/$(I_DIR)

SRCS = $(shell find src -name *.c)

OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))

FLAGS = -Wall -Werror -Wextra -g -MMD -MP 

LIB = libft/libft.a \
	  MacroLibX/libmlx.so

$(NAME): $(OBJS)
	@make -sj -C $(LIBFT_DIR)
	@echo "✅ Libft compiled"
	@#@make -sj -C $(MACRO_DIR)
	@#@echo "✅ MacroLibX compiled"
	@$(CC) $(OBJS) $(LIB) -o $(NAME) $(FLAGS) -lm -lSDL2
	@echo "✅ Compiled"

$(OBJSDIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDE) $(FLAGS) $< -c -o $@

all: $(NAME)

clean:
	@make -sC $(LIBFT_DIR) clean
	@#@make -sC $(MACRO_DIR) clean > /dev/null
	@rm -f $(OBJS)

fclean: clean
	@make -sC $(LIBFT_DIR) fclean
	@echo "🧹 Libft Cleaned"
	@#@make -sC $(MACRO_DIR) fclean > /dev/null
	@#@echo "🧹 MacroLibX Cleaned"
	@rm -f $(NAME)
	@rm -Rf $(OBJSDIR)
	@echo "🧹 Cleaned"

re: fclean all

.PHONY: clean all re fclean
