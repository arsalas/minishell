# COLORS
GREEN	:=\033[32m
NC	:=\033[m

# FLAGS
CFLAGS 	:= -Wall -Wextra -Werror
CC		:= gcc
RM 			= rm -f

# SRC
SRCS 	= ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

B_SRCS 	= ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

# FOLDERS
OBJS_DIR	:= obj
BIN_DIR		:= bin

# OBJECTS
OBJS 		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
B_OBJS 		= $(addprefix $(OBJS_DIR)/, $(B_SRCS:.c=.o))

# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPFLAGS			= -MMD -MF

# PROGRAM NAME
NAME 		:= libft.a

# BINARY PATH
BIN 		= $(BIN_DIR)/$(NAME)

.SECONDEXPANSION:

all: $(BIN_DIR) $(BIN)
	
$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@)

$(BIN):	$(OBJS)
	@ar rc $(BIN) $(OBJS)
	@echo "$(GREEN)libft compiled!$(NC)"

bonus: $(B_OBJS) $(OBJS)
	@ar rc $(NAME) $(OBJS) $(B_OBJS)

clean:
	@$(RM) $(OBJS) $(B_OBJS)
	@echo "$(GREEN)libft cleaned!$(NC)"

fclean:		clean
	@$(RM) $(BIN) $(DEPS)

re:			fclean all


$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)


-include $(DEPS)

.PHONY:		all clean fclean re