#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_minishell
{
	int tokens;
	int pid;
	int input;
	int line;
	int double_quo;
	int simple_quo;
	int phrases;
	int separator;
}	t_minishell;

#endif
