/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:34:55 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 18:02:51 by amurcia-         ###   ########.fr       */
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
# include "libft.h"
# include "colors.h"
# include "enums.h"
# include "builtins.h"
# include "utils.h"
# include "env.h"
# include "pipes.h"
# include "errors.h"
# include "echo.h"

# define READ_END 0
# define WRITE_END 1

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
	int	double_quo;
	int	simple_quo;
	int	pipe;
	int	slash;
}	t_parse;

/*
* INPUT es la string que me dan por terminal
* TRACES es el array bidimensional en funcion de cuantos pipes haya
* QUO hace referencia a las comillas
* PIPE indica el numero de pipes que hay
*/
typedef struct s_minishell
{
	char		*input;
	char		**traces;
	t_command	*command;
	t_env		env;
	t_parse		*parse;
	int			status;
}	t_minishell;

extern t_minishell	*g_minishell;

//FILES IN UTILS
char	**ft_split_words(char *str);
void	ft_free_split(char **words);
bool	ft_strcmp(const char *s1, const char *s2);
char	*ft_strstr(const char *haystack, const char *needle);

//FILES IN HISTORY
void	ft_clear_history(void);
void	ft_read_history(void);
char	*ft_get_input(void);

//FILES IN MINISHELL: INIT
void	ft_init_minishell(void);
void	ft_read(t_minishell *minishell);


//FILES IN PARSE
void		ft_search_command_in_pipe(void);
void		ft_number_pipes(void);
void		ft_odd_quotes(char *traces);
t_builtins	ft_command_in_pipe(void);
t_builtins	ft_get_command(char *inside_pipes);
int			ft_is_cd(char **words);
int			ft_is_export(char **words);
int			ft_is_echo(char **words);
int			ft_is_exit(char **words);
int			ft_is_unset(char **words);
int			ft_is_env(char **words);
int			ft_is_pwd(char **words);

//FILES IN EXIT
void	ft_exit(char *str);
int	ft_its_not_digit(char *str, int len);
int		ft_after_exit(char *str, int count);
int		ft_empty_piece(char *str, int count);

//FILES IN BULTINGS: CD
void	ft_cd(char *input);
void	ft_parse_cd(char *input);
char	*ft_old_cd(void);
char	*ft_add_home_paths(char *word);

#endif
