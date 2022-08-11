/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:34:55 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 15:36:25 by aramirez         ###   ########.fr       */
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

/*
* INPUT es la string que me dan por terminal
* QUO hace referencia a las comillas
* PIPE indica el numero de pipes que hay
* TRACES hace referencia al array bidimensional en funcion de cuantos pipes haya
* FLAG indica si hemos encontrado un flag despues de echo
* PREV es el string de lo que hay antes del = en export
* POST es el string de lo que hay despues del = en export
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
	int			start;
	int			slash;
	int			previous_double;
	int			previous_simple;
	//PREV AND POST SON EL PREVIO Y EL POSTERIOR DEL = PARA EXPORT
	char		*prev;
	char		*post;
	t_command	*command;
	t_env		env;
	int			status;
}	t_minishell;


extern t_minishell	*g_minishell;

//FILES IN PARSE
void	print_string(char *str);
void	print_headline(void);
void	ft_parse(t_minishell *minishell);
void	ft_init_minishell(t_minishell *minishell);
t_builtins	ft_command_in_pipe(t_minishell *minishell);

void	ft_which_command(t_minishell *minishell);
char	*ft_strstr(const char *haystack, const char *needle);
bool	ft_strcmp(const char *s1, const char *s2);
void	ft_free_split(char **words);
void	ft_get_signal(t_minishell *minishell);
char	**ft_split_words(char *str);
void	ft_get_signal(t_minishell *minishell);
void	ft_odd_quotes(t_minishell *minishell, char *traces);

//PARSE3 and PARSE4
int		ft_is_pwd(char **words);
int		ft_is_env(char **words);
int		ft_is_unset(char **words);
int		ft_is_exit(char **words);
int		ft_is_export(char **words);
int		ft_is_cd(char **words);
int		ft_is_echo(char **words);
void	ft_free_split(char **words);
void	ft_get_signal(t_minishell *minishell);
char	**ft_split_tab(char const *s);
void	ft_get_signal(t_minishell *minishell);
//FILES IN SIGNAL
void	ft_get_signal(t_minishell *minishell);

//FILES IN BUILTINGS: ECHO
void	ft_look_for_flag(t_minishell *minishell, char *inside_pipes);
void	ft_quotes_error(t_minishell *minishell, char *inside);
void	ft_make_echo(t_minishell *minishell, char *inside_pipes);
void	ft_print_the_echo(t_minishell *minishell, char *words);
void	ft_start_command(t_minishell *minishell, char *word);

//FILES IN BULTINGS: EXPORT
void	ft_make_export(t_minishell *minishell, char *inside_pipes);
void	ft_save_the_export(t_minishell *minishell, char *words, int start, int len);
int		ft_start_export(char *word);
int		ft_end_export(int count, char *word);
void	ft_equal_error(char *words);

//FILES IN BULTINGS: EXIT
void	ft_exit(char *str);

//FILES IN BULTINGS: CD
void	ft_cd(char *input);
char	*ft_add_home_paths(char *word);

#endif
