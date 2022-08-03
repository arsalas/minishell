# COLORS
GREEN			:= \033[32m
NC				:= \033[m

# FLAGS
CC				:= gcc
CFLAGS 			:= -Wall -Wextra -Werror
READ_FLAGS		:= -lreadline
FLAGS			:= $(CFLAGS)

RM 				:= rm -f

# SRC
MAIN			= main.c 

SRCS 			= prompt.c memory.c utils.c \
				errors.c \
				cd.c echo.c env.c exit.c export.c pwd.c unset.c \
				env_aux1.c env_aux2.c env_aux3.c \
				pipes.c \

# LIBS
LIBS_PATH		:= libs
LIBS 			:= $(LIBS_PATH)/libft/bin/libft.a

# FOLDERS
OBJS_DIR		:= obj
BIN_DIR			:= bin

#INCLUDES
INC_PATH		:= inc
INCLUDES 		:= $(LIBS_PATH)/libft/ $(INC_PATH)/
INC 			= $(addprefix -I , $(INCLUDES))

# OBJECTS
OBJS_MAIN		= $(addprefix $(OBJS_DIR)/, $(MAIN:.c=.o))
OBJS_SRC		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS			= $(OBJS_MAIN) $(OBJS_SRC)


# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPFLAGS			= -MMD -MF

# PROGRAM NAME
NAME 			:= minishell

# BINARY PATH
BIN = $(BIN_DIR)/$(NAME)

vpath %.c src src/utils src/errors src/builtins src/env src/pipes

.SECONDEXPANSION:

all: make_libs $(BIN)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 

make_libs:
	@make -C $(LIBS_PATH)/libft

$(BIN): $(OBJS) $(BIN_DIR) $(LIBS)
	@$(CC) $(FLAGS) $(INC) $(OBJS) $(LIBS) -o $(BIN) $(READ_FLAGS)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

run: all
	@./$(BIN)

leaks: $(BIN)
	@leaks -atExit -- ./$(BIN)

test: all
	@echo "$(GREEN)Executing tests...$(NC)"
	@make run -e -C tests/ OBJS_SRC="$(OBJS_SRC)"

clean:
	@make fclean -C $(LIBS_PATH)/libft
	@$(RM) $(OBJS) $(DEPS)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean:		clean
	@$(RM) $(BIN)

re:	fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

-include $(DEPS)

.PHONY:		all clean fclean re make_libs leaks test