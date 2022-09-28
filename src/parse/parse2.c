/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:10:01 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/28 18:44:15 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Comprobamos el comando que nos escriben
 * 
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
	if (ft_strcmp(words[0], "echo", false))
		command = C_ECHO;
	else if (ft_strcmp(words[0], "cd", false))
		command = C_CD;
	else if (ft_strcmp(words[0], "export", false))
		command = C_EXPORT;
	else if (ft_strcmp(words[0], "env", false))
		command = C_ENV;
	else if (ft_strcmp(words[0], "exit", false))
		command = C_EXIT;
	else if (ft_strcmp(words[0], "unset", false))
		command = C_UNSET;
	else if (ft_strcmp(words[0], "pwd", false))
		command = C_PWD;
	else
		command = C_OTHERS;
	ft_free_split(words);
	free(inside_pipes);
	return (command);
}
