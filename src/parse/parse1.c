/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:16:06 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/11 16:33:51 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* Contamos la cantidad de comillas, siempre y cuando no esten despues del \
*/
void	ft_odd_quotes(char *traces)
{
	int	count;

	g_minishell->double_quo = 0;
	g_minishell->simple_quo = 0;
	count = 0;
	while (traces[count])
	{
		if (traces[count] == 92 &&
			(traces[count + 1] == 34 || traces[count + 1] == 39))
		{
			g_minishell->slash++;
			count += 2;
		}
		else if (traces[count] == 34)
			g_minishell->double_quo++;
		else if (traces[count] == 39)
			g_minishell->simple_quo++;
		count++;
	}
}

/*
* Miramos la cantidad de pipes
*/
void	ft_number_pipes(void)
{
	int	count;
	int	quote;

	count = 0;
	quote = 0;
	while (g_minishell->input[count])
	{
		if (g_minishell->input[count] == 34 || g_minishell->input[count] == 39)
			quote++;
		if (g_minishell->input[count] == 124 && (quote % 2 == 0 || quote == 0))
			g_minishell->pipe++;
		count++;
	}
	if (count > 0)
		g_minishell->traces = ft_split(g_minishell->input, '|');
}

/*
* Obtenemos el comando que hay entre pipes
*/
void	ft_search_command_in_pipe(void)
{
	int		i;
	t_pipe	*commands;

	i = 0;
	commands = get_memory(sizeof(t_pipe) * (g_minishell->pipe) + 1);
	while (i < g_minishell->pipe + 1)
	{
		commands[i].command = ft_command_in_pipe(g_minishell);
		commands[i].content = g_minishell->traces[i];
		i++;
	}
}

// TODO: funcion que inicie minishell malloc y inicie env
// TODO: funcion principal que espera un input
