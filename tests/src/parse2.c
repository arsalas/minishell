/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:10:01 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/02 21:02:23 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//En caso de que solo nos hayan pasado un comando
//Miramos que comando nos han pasado. De momento solo hacemos un triste printf
void	ft_which_command(t_minishell *minishell)
{
	if (ft_strstr(minishell->input, "echo"))
		printf("echo\n");
	else if (ft_strstr(minishell->input, "cd"))
		printf("cd\n");
	else if (ft_strstr(minishell->input, "pwd"))
		printf("pwd\n");
	else if (ft_strstr(minishell->input, "export"))
		printf("export\n");
	else if (ft_strstr(minishell->input, "unset"))
		printf("unset\n");
	else if (ft_strstr(minishell->input, "env"))
		printf("env\n");
	else if (ft_strstr(minishell->input, "exit"))
		printf("exit\n");
}

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
	int	count;

	count = 0;
	while (minishell->traces[count])
	{
		if (ft_strncmp_mod(minishell->traces[count], "echo", 4) && (minishell->traces[count][5] == ' ' || minishell->traces[count][5] == '\t'));
            printf("ECHO\n");
        else if (ft_strncmp_mod(minishell->traces[count], "echo -n", 7) && (minishell->traces[count][8] == ' ' || minishell->traces[count][8] == '\t'));;
            printf("ECHO\n");
        count++;
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

