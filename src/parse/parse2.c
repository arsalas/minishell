/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:10:01 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/03 20:22:33 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Miramos si tenemos flags
void	ft_count_commands(t_minishell *minishell)
{
	int	count;

	count = 0;
	while (minishell->input[count])
	{
		if (ft_strstr(minishell->input, "echo -n"))
			minishell->flag++;
		count++;
	}
}

void    ft_free_split(char **words)
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

t_builtins	ft_get_command(char *word)
{
	t_builtins	command;
	char		**words;

	words = ft_split(word, ' ');
	if (ft_strcmp("echo", words[0]))
		command = C_ECHO;
	else if (ft_strcmp("cd", words[0]))
		command = C_CD;
	else if (ft_strcmp("export", words[0]))
		command = C_EXPORT;
	else if (ft_strcmp("env", words[0]))
		command = C_ENV;
	else if (ft_strcmp("exit", words[0]))
		command = C_EXIT;
	else if (ft_strcmp("unset", words[0]))
		command = C_UNSET;
	else if (ft_strcmp("pwd", words[0]))
		command = C_PWD;
	else
		command = C_OTHERS;
	ft_free_split(words);
	return (command);
}

//En caso de que nos hayan pasado mas de un comando con pipes
void	ft_command_in_pipe(t_minishell *minishell)
{
	int	word;

	word = 0;
	while (minishell->traces[word])
	{
		ft_get_command(minishell->traces[word]);
		if (ft_get_command(minishell->traces[word]) == C_CD)
			printf("CD\n");
		if (ft_get_command(minishell->traces[word]) == C_EXPORT)
			printf("EXPORT\n");
		if (ft_get_command(minishell->traces[word]) == C_ECHO)
			printf("ECHO\n");
		if (ft_get_command(minishell->traces[word]) == C_ENV)
			printf("ENV\n");
		if (ft_get_command(minishell->traces[word]) == C_EXIT)
			printf("EXIT\n");
		if (ft_get_command(minishell->traces[word]) == C_PWD)
			printf("PWD\n");
		if (ft_get_command(minishell->traces[word]) == C_UNSET)
			printf("UNSET\n");
		if (ft_get_command(minishell->traces[word]) == C_OTHERS)
			printf("OTHERS\n");
		word++;
	}
}
