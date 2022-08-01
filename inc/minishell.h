/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:34:55 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/01 19:34:53 by aramirez         ###   ########.fr       */
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

typedef struct s_minishell
{
	int	tokens;
	int	pid;
	int	input;
	int	line;
	int	double_quo;
	int	simple_quo;
	int	phrases;
	int	separator;
}	t_minishell;

void	print_headline(void);
void	not_implemented(void);
void	memory_error(void);

void	cmd_pwd(void);

#endif
