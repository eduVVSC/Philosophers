CC = cc
NAME = philo

#FLAGS
FLAGS = -g -I$(LIB_DIR) -Wall -Wextra -Werror
FLAGS1 = -fsanitize=thread -g -I$(LIB_DIR) -Wall -Wextra -Werror
FLAGS2 = -fsanitize=address -fsanitize=leak -fsanitize=undefined -fno-omit-frame-pointer -g -I$(LIB_DIR) -Wall -Wextra -Werror
FLAGS3 = -fsanitize=memory -g -I$(LIB_DIR) -Wall -Wextra -Werror

LIB_DIR = libft/
SRC_DIR = src/
OBJ_DIR = obj/

# FILES
LIBFT = $(LIB_DIR)libft.a
MAIN_FILE = main.c

SRC_FILES := $(shell find $(SRC_DIR) -name '*.c' ! -name 'main.c')

OBJ_FILES := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))

#PHONY TARGETS
.PHONY: all clean fclean re

#RULES
all: ${NAME}

${NAME}: ${LIBFT} ${MAIN_FILE} $(OBJ_FILES) | $(OBJ_DIR)
	@${CC} ${FLAGS} ${MAIN_FILE} $(OBJ_FILES) $(LIBFT) -o $(NAME)
	@echo "$(GRN)[ ${NAME} ] compiled successfully.$(RES)"

${LIBFT}:
	@make --silent -C $(LIB_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
		@rm -rf ${OBJ_DIR}
		@rm -f $(LIB_DIR)/*.o
		@echo "$(WHT)Clean command executed.$(RES)"

fclean: clean
		@rm -f ${NAME}
		@rm -f ${LIBFT}

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo


re: fclean all
