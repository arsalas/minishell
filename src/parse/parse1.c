/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:16:06 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/11 16:43:17 by aramirez         ###   ########.fr       */
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

char	*ft_get_input(void)
{
	return (readline("minishell: "));
}

void	ft_parse(t_minishell *minishell)
{
	t_pipe	*commands;

	while (1)
	{
		g_minishell->input = ft_get_input();
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


// TODO: funcion que inicie minishell malloc y inicie env
// TODO: funcion principal que espera un input