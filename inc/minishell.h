/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:34:55 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/13 19:44:49 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "colors.h"
# include "enums.h"
# include "builtins.h"
# include "utils.h"
# include "env.h"
# include "pipes.h"
# include "errors.h"
# include "echo.h"
# include "parse.h"
# include "input.h"
# include "commands.h"
# include "helpers.h"
# include "get_next_line.h"

# define READ_END 0
# define WRITE_END 1
# define REDIR_FILE ".redirs.txt"

typedef struct s_env_details
{
	char	*title;
	char	*content;
}	t_env_details;

typedef struct s_env
{
	int				count;
	t_env_details	*vars;
}	t_env;

typedef struct s_command
{
	int	echo;
	int	cd;
	int	pwd;
	int	export;
}	t_command;

typedef struct s_parse
{
	int	quo;
	int	double_quo;
	int	simple_quo;
	int	pipe;
	int	slash;
}	t_parse;

typedef struct s_memory
{
	int		quantity;
	void	**memory;
}	t_memory;

typedef struct s_tokens
{
	int		token;
	char	*content;
	char	*path;
}	t_tokens;

/*
* INPUT es la string que me dan por terminal
* TRACES es el array bidimensional en funcion de cuantos pipes haya
* QUO hace referencia a las comillas
* PIPE indica el numero de pipes que hay
*/
typedef struct s_minishell
{
	char			*input;
	char			**traces;
	char			*old_dir;
	t_command		*command;
	t_env			env;
	t_parse			parse;
	int				status;
	int				bloq;
	bool			finish;
	struct termios	term;
	t_builtins		last_command;
	t_process		process;
	t_memory		memory;
	t_tokens		tokens;
}	t_minishell;

extern t_minishell	*g_minishell;

//FILES IN HISTORY
void	ft_clear_history(void);
void	ft_read_history(void);
char	*ft_get_input(void);

//FILES IN MINISHELL: INIT
void	ft_init_minishell(char **env);
void	ft_read(void);
void	ft_signal(void);

//FILES IN SIGNAL
void	rl_replace_line(const char *text, int clear_undo);
int		ft_get_signal(void);

//FILES IN MEMORY
void	ft_free_usual(void);

//FILES IN REDIRECTIONS 
t_fd_redirs	ft_get_redir(t_pipe command);
int 		ft_redir_in(int fd);
int 		ft_trunc(int fd);
int 		ft_append(int fd);
int 		ft_fd(void);
void		empty_trash(void);


#endif
