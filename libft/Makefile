NAME    = libft.a

SRCS    = is/ft_isalpha.c \
			is/ft_isalnum.c \
			is/ft_isascii.c \
			is/ft_isdigit.c \
			is/ft_isprint.c \
			is/ft_is_space.c \
			str/ft_strlen.c \
			str/ft_toupper.c \
			str/ft_tolower.c \
			str/ft_strchr.c \
			str/ft_strrchr.c \
			str/ft_strncmp.c \
			str/ft_strnstr.c \
			str/ft_atoi.c \
			mem/ft_memset.c \
			mem/ft_memmove.c \
			mem/ft_memcpy.c \
			mem/ft_memchr.c \
			mem/ft_memcmp.c \
			mem/ft_bzero.c \
			mem/ft_calloc.c \
			str/ft_strlcpy.c \
			str/ft_strlcat.c \
			put/ft_putchar_fd.c \
			put/ft_putendl_fd.c \
			put/ft_putstr_fd.c \
			put/ft_putnbr_fd.c \
			str/ft_strdup.c \
			str/ft_strjoin.c \
			str/ft_substr.c \
			str/ft_strtrim.c \
			str/ft_itoa.c \
			str/ft_striteri.c \
			str/ft_strmapi.c \
			str/ft_split.c \
			str/ft_atoll.c \
			Ft_Printf/ft_printf_utils.c \
			Ft_Printf/ft_printf.c \
			Ft_Printf/ft_putnbr_hexa.c \
			Ft_Printf/ft_putnbr_uns_int.c \
			gnl/get_next_line.c \
			str/ft_count_word.c \
			str/ft_strcmp.c

OBJS    =  ${SRCS:.c=.o}

HEADERS    = includes/

all : ${NAME}

${OBJS} : 
	@gcc -Wall -Wextra -Werror -I ${HEADERS} -c ${@:.o=.c} -o $@

${NAME} : ${OBJS}
	@ar rcs ${NAME} ${OBJS}

clean :
	@rm -f ${OBJS}

fclean : clean
	@rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
