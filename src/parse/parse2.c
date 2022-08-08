/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:10:01 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/08 18:45:33 by amurcia-         ###   ########.fr       */
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
//FT_LOOK_FOR_FLAG es para mirar si tenemos un flag en el ECHO
void	ft_command_in_pipe(t_minishell *minishell)
{
	int		inside_pipes;

	inside_pipes = 0;
	while (minishell->traces[inside_pipes])
	{
		ft_get_command(minishell->traces[inside_pipes]);
		if (ft_get_command(minishell->traces[inside_pipes]) == C_ECHO)
			ft_look_for_flag(minishell->traces[inside_pipes]);
		else if (ft_get_command(minishell->traces[inside_pipes]) == C_CD)
			printf("CD\n");
		else if (ft_get_command(minishell->traces[inside_pipes]) == C_EXPORT)
			printf("EXPORT\n");
		else if (ft_get_command(minishell->traces[inside_pipes]) == C_ENV)
			printf("ENV\n");
		else if (ft_get_command(minishell->traces[inside_pipes]) == C_EXIT)
			printf("EXIT\n");
		else if (ft_get_command(minishell->traces[inside_pipes]) == C_PWD)
			printf("PWD\n");
		else if (ft_get_command(minishell->traces[inside_pipes]) == C_UNSET)
			printf("UNSET\n");
		else if (ft_get_command(minishell->traces[inside_pipes]) == C_OTHERS)
			printf("OTHERS\n");
		inside_pipes++;
	}
}
