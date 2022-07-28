CFLAGS 	:= -Wall -Wextra -Werror
CC		:= gcc

SRCS 	= main.c

# HEADERS 	= */*.h
# LIBS_INCLUDES = */*.a

OBJS_DIR	:= obj
BIN_DIR		:= bin

# INCLUDES 	:=  */
# INC 		= $(addprefix -I , $(INCLUDES))

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

NAME 	:= minishell

BIN = $(BIN_DIR)/$(NAME)

RM 		:= rm -f

vpath %.c src

.SECONDEXPANSION:

all:	make_libs $(BIN)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

make_libs:
#	@make -C libft

$(BIN): $(OBJS) $(BIN_DIR)
	@$(CC) $(CFLAGS)  $(OBJS)  -o $(BIN)
	@echo "\x1b[32m$(NAME) compiled!\x1b[0m"

run: $(BIN)
	@./$(BIN)

leaks: $(BIN)
	@leaks -atExit -- ./$(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "\x1b[32mcleaned!\x1b[0m"

fclean:		clean
	@$(RM) $(BIN)

re:	fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

.PHONY:		all clean fclean re make_libs leaks