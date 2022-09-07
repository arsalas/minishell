/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:10:01 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/07 18:37:06 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_empty(char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] && (str[cont] == '\n'
			|| str[cont] == '\t' || str[cont] == ' '))
	{
		cont++;
	}
	return (cont);
}

/*
* Comprobamos el input con echo, cd, export, etc
* Si hay coincidencia, command = comando
*/
t_builtins	ft_get_command(char *inside_pipes)
{
	char		**words;
	int			empty;
	t_builtins	command;

	empty = ft_is_empty(inside_pipes);
	if (inside_pipes[empty] == '\0')
		return (C_OTHERS);
	words = ft_split_words(inside_pipes);
	if (ft_is_echo(words) == 0)
		command = C_ECHO;
	else if (ft_is_cd(words) == 0)
		command = C_CD;
	else if (ft_is_export(words) == 0)
		command = C_EXPORT;
	else if (ft_is_env(words) == 0)
		command = C_ENV;
	else if (ft_is_exit(words) == 0)
		command = C_EXIT;
	else if (ft_is_unset(words) == 0)
		command = C_UNSET;
	else if (ft_is_pwd(words) == 0)
		command = C_PWD;
	else
		command = C_OTHERS;
	ft_free_split(words);
	return (command);
}
