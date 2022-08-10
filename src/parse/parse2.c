/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:10:01 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/10 15:50:45 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_split(char **words)
{
	int	count;

	count = 0;
	while (words[count])
	{
		free(words[count]);
		count++;
	}
	free(words);
}

t_builtins	ft_get_command(char *inside_pipes)
{
	t_builtins	command;
	char		**words;

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

//En caso de que nos hayan pasado mas de un comando con pipes

t_builtins	ft_command_in_pipe(t_minishell *minishell)
{
	ft_get_command(minishell->traces[0]);
	if (ft_get_command(minishell->traces[0]) == C_ECHO)
		return (C_ECHO);
	if (ft_get_command(minishell->traces[0]) == C_CD)
		return (C_CD);
	if (ft_get_command(minishell->traces[0]) == C_EXPORT)
		return (C_EXPORT);
	if (ft_get_command(minishell->traces[0]) == C_ENV)
		return (C_ENV);
	if (ft_get_command(minishell->traces[0]) == C_EXIT)
		return (C_EXIT);
	if (ft_get_command(minishell->traces[0]) == C_PWD)
		return (C_PWD);
	if (ft_get_command(minishell->traces[0]) == C_UNSET)
		return (C_UNSET);
	return (C_OTHERS);
}
