/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:44:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/10 13:06:51 by aramirez         ###   ########.fr       */
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

typedef struct s_pipe
{
	t_builtins	command;
	char		*content;
}	t_pipe;


#endif