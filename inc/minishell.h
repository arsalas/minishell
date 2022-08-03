/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:34:55 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/03 14:23:37 by aramirez         ###   ########.fr       */
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

typedef struct s_minishell
{
	int		tokens;
	int		pid;
	int		input;
	int		line;
	int		double_quo;
	int		simple_quo;
	int		phrases;
	int		separator;
	t_env	env;
}	t_minishell;

extern t_minishell	*g_minishell;

#endif
