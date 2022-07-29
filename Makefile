# COLORS
GREEN			:= \033[32m
NC				:= \033[m

# FLAGS
CC				:= gcc
CFLAGS 			:= -Wall -Wextra -Werror
EXTRA_FLAGS		:= -lreadline
FLAGS			:= $(CFLAGS)

RM 				:= rm -f

# SRC
MAIN			= main.c
SRCS 			= 

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

vpath %.c src

.SECONDEXPANSION:

all: make_libs $(BIN)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) $(EXTRA_FLAGS)

make_libs:
	@make -C $(LIBS_PATH)/libft

$(BIN): $(OBJS) $(BIN_DIR) $(LIBS)
	@$(CC) $(FLAGS) $(INC) $(OBJS) $(LIBS) -o $(BIN) $(EXTRA_FLAGS)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

run: all
	@./$(BIN)

leaks: $(BIN)
	@leaks -atExit -- ./$(BIN)

test: all
	@echo "$(GREEN)Executing tests...$(NC)"
	@make run -C tests/ OBJS_MAIN="$(OBJS_SRC)"

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