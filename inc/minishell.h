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
# include <stdbool.h>
# include "libft.h"
# include "colors.h"

typedef struct s_command
{
	int echo;
	int cd;
	int pwd;
	int export;
}	t_command;

/*
* INPUT es la string que me dan por terminal
* QUO hace referencia a las comillas
* PIPE indica el numero de pipes que hay
* TRACES hace referencia al array bidimensional en funcion de cuantos pipes haya
* FLAG indica si hemos encontrado un flag despues de echo
*/
typedef struct s_minishell
{
	int			pid;
	char		*input;
	int			double_quo;
	int			simple_quo;
	int			pipe;
	char		**traces;
	int			flag;
	t_command	*command;
}	t_minishell;

//FILES IN PARSE

void	print_string(char *str);
void	print_headline(void);
void	ft_parse(t_minishell *minishell);
void	ft_init_minishell(t_minishell *minishell);
void	ft_command_in_pipe(t_minishell *minishell);
void	ft_count_commands(t_minishell *minishell);
void	ft_which_command(t_minishell *minishell);
char	*strstr(const char *haystack, const char *needle);
int		ft_strncmp_mod(const char *s1, const char *s2, size_t n);

#endif
