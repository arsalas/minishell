/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:10:01 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/03 17:22:50 by amurcia-         ###   ########.fr       */
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

//En caso de que nos hayan pasado mas de un comando con pipes
void	ft_command_in_pipe(t_minishell *minishell)
{
	int	word;
	int	letter;

	word = 0;
	letter = 0;
	while (minishell->traces[word])
	{
		if (minishell->traces[word][letter] == ' '  || minishell->traces[word][letter] == '\t')
			letter++;

		// FALTA
	}
}

/*oid	ft_command_in_pipe(t_minishell *minishell)
{
	int	count;

	count = 0;
	while (minishell->traces[count])
	{
		if (ft_strstr(minishell->traces[count], "echo"))
			printf("echo\n");
		else if (ft_strstr(minishell->traces[count], "echo -n"))
			printf("echo -n\n");
		else if (ft_strstr(minishell->traces[count], "cd"))
			printf("cd\n");
		else if (ft_strstr(minishell->traces[count], "pwd"))
			printf("pwd\n");
		else if (ft_strstr(minishell->traces[count], "export"))
			printf("export\n");
		else if (ft_strstr(minishell->traces[count], "unset"))
			printf("unset\n");
		else if (ft_strstr(minishell->traces[count], "env"))
			printf("env\n");
		else if (ft_strstr(minishell->traces[count], "exit"))
			printf("exit\n");
		count++;
	}
}*/

