CC= cc
CFLAGS= -Wall -Wextra -Werror -g
DEPS= libft.h
DIR= Additional_Functions/
DIR2= Bonus_Functions/
FUNCS= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
	ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_striteri.c ft_strjoin.c ft_strmapi.c \
	ft_strmapi.c ft_strtrim.c ft_substr.c get_next_line.c get_next_line_utils.c\
	ft_printf.c ft_printf_utils.c ft_nbrlen.c ft_free_double_arr.c ft_split_redux.c
BONS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
NAME= libft.a
OBJECTS = ${FUNCS:.c=.o}
BOBJECTS = ${BONS:.c=.o}


$(NAME):$(OBJECTS)
	$(CC) -c $(CFLAGS) $(FUNCS)
	ar -rcs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re: fclean
	$(MAKE) all

bonus: $(OBJECTS) $(BOBECTJS)
	$(CC) -c $(CFLAGS) $(FUNCS) $(BONS)
	ar -rcs $(NAME) $(OBJECTS) $(BOBJECTS)
