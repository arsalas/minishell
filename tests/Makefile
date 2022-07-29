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
SRCS 			= main.c

# LIBS
LIBS_PATH		:= ../libs
LIBS 			:= $(LIBS_PATH)/libft/bin/libft.a

# FOLDERS
OBJS_DIR		:= obj
BIN_DIR			:= bin

#INCLUDES
INC_PATH		:= ../inc
INCLUDES 		:= $(LIBS_PATH)/libft/ $(INC_PATH)/
INC 			= $(addprefix -I , $(INCLUDES))

# OBJECTS
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS_TEST	= $(addprefix ../, $(OBJS_MAIN))

# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPFLAGS			= -MMD -MF

# PROGRAM NAME
NAME 			:= minishell_test

# BINARY PATH
BIN = $(BIN_DIR)/$(NAME)

vpath %.c src

.SECONDEXPANSION:

all:	$(BIN)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(FLAGS)  $(INC) -c $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) $(READ_FLAGS)

$(BIN): $(OBJS) $(BIN_DIR) $(LIBS)
	@$(CC) $(FLAGS) $(INC) $(OBJS) $(OBJS_TEST) $(LIBS) -o $(BIN) $(READ_FLAGS)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

run: all
	@./$(BIN)

leaks: $(BIN)
	@leaks -atExit -- ./$(NAME)

clean:
	@make fclean -C $(LIBS_PATH)/libft
	@$(RM) $(OBJS)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean:		clean
	@$(RM) $(BIN)

re:	fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

.PHONY:		all clean fclean re leaks