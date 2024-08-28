NAME = philo

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

SRCS = srcs/philos.c srcs/utils.c srcs/main.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o philo
	@echo "-->Objects created<--"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "->Objects cleaned<-"

fclean: clean
	@rm -f philo
	@echo "->$(NAME) erase<-"

re: fclean all

.PHONY: all clean fclean re
