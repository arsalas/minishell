/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:44:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/12 15:03:23 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# include "minishell.h"

typedef enum e_builtins
{
	C_CD,
	C_ECHO,
	C_ENV,
	C_UNSET,
	C_EXIT,
	C_EXPORT,
	C_PWD,
	C_OTHERS
}	t_builtins;

typedef enum e_redir_type
{
	REIN,
	REOUT,
	DOUBBLE_REIN,
	DOUBBLE_REOUT
}	t_redir_type;

// 1	Catchall for general errors
// 2	Misuse of shell builtins (according to Bash documentation)
// 126	Command invoked cannot execute
// 127	Command not found
// 128	Invalid argument to exit command
// 128+n	Fatal error signal “n”
// 130	Bash script terminated by Control-C
// 255*	Exit status out of range
typedef enum e_exit_status
{
	GENERAL=1,
	MISUE=2,
	CN_EXEC=126,
	CN_FOUND=127,
	INV_ARG=128,
	FATAL_SIGNAL=128,
	CNT_C=130,
	OUT_RANGE=255
}	t_exit_status;

typedef struct s_redir_info
{
	t_redir_type	types;
	char			*files;
}	t_redir_info;

typedef struct s_redirs
{
	int				quantity; // 2
	t_redir_info	*info;	// [{type: REOUT, files: test2.txt}, {type: REOUT, files: test}]
}	t_redirs;

typedef struct s_pipe
{
	t_builtins	command; // C_OTHERS
	char		*raw;	// /bin/wc < test2.txt < test
	char		*input; // /bin/wc -> hola adios
	t_redirs	*redirs;

}	t_pipe;

typedef struct s_process
{
	int		quantity;
	t_pipe	*content;
}	t_process;

#endif
