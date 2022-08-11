/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:16:06 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/10 13:31:47 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Comprobamos comillas
void	ft_odd_quotes(t_minishell *minishell, char *traces)
{
	int	count;

	minishell->double_quo = 0;
	minishell->simple_quo = 0;
	count = 0;
	while (traces[count])
	{
		if (traces[count] == 92 &&
			(traces[count + 1] == 34 || traces[count + 1] == 39))
		{
			minishell->slash++;
			count += 2;
		}
		else if (traces[count] == 34)
			minishell->double_quo++;
		else if (traces[count] == 39)
			minishell->simple_quo++;
		count++;
	}
}

/*
* Miramos la cantidad de pipes
* 39 == '
* 34 == "
* 124 == |
*/
void	ft_number_pipes(t_minishell *minishell)
{
	int	count;
	int	quote;

	count = 0;
	quote = 0;
	while (minishell->input[count])
	{
		if (minishell->input[count] == 34 || minishell->input[count] == 39)
			quote++;
		if (minishell->input[count] == 124 && (quote % 2 == 0 || quote == 0))
			minishell->pipe++;
		count++;
	}
	if (count > 0)
		minishell->traces = ft_split(minishell->input, '|');
}

void	ft_get_pid(t_minishell *minishell)
{
	pid_t	pid;

	pid = fork();
	if (!pid || pid < 0)
		exit (0);
	waitpid(pid, NULL, 0);
	minishell->pid = pid;
}

//INICIALIZAMOS LAS VARIABLES DE NUESTRA ESTRUCTURA MINISHELL
void	ft_init_minishell(t_minishell *minishell)
{
	minishell->pid = 0;
	minishell->pid = 0;
	minishell->input = 0;
	minishell->double_quo = 0;
	minishell->simple_quo = 0;
	minishell->pipe = 0;
}

void	ft_parse(t_minishell *minishell)
{
	// int		cont;
	t_pipe	*commands;

	// cont = 0;
	ft_init_minishell(minishell);
	ft_get_pid(minishell);
	while (1)
	{
		minishell->input = readline("minishell: ");
		add_history(minishell->input);
		ft_number_pipes(minishell);
		if (minishell->pipe == 0)
			ft_odd_quotes(minishell, minishell->input);
		commands = get_memory(sizeof(t_pipe) * (minishell->pipe) + 1);
		int i = 0;
		while (i < minishell->pipe + 1)
		{
			commands[i].command = ft_command_in_pipe(minishell);
			commands[i].content = minishell->traces[i];
			printf("%i | %s", commands[i].command, commands[i].content);
			i++;
		}
		ft_command_in_pipe(minishell);
		clear_history();
	}
}
