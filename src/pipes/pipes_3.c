/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:50:51 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/11 11:48:50 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	execute_pipe2(t_process process)
{
	int	i;

	i = 0;
	while (i < process.quantity)
	{
		if (ft_strlen(process.content[i].raw) == 0
			|| ft_strcmp(process.content[i].raw, "|", false))
		{
			printf("syntax error near unexpected token: `|\'\n");
			return (false);
		}
		if (is_odd_quotes(process.content[i].raw))
			return (false);
		if (!is_correct_tokens(process.content[i].raw))
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Ejecuta los pipes
 * 
 * @param process cantidad de procesos a ejecutar por los pipes
 */
void	execute_pipe(t_process process)
{
	if (!execute_pipe2(process))
		return ;
	if (process.quantity == 0)
		return ;
	if (process.quantity == 1)
		return (execute_single_process(process));
	if (process.quantity == 2)
		return (execute_single_pipe(process.content));
	g_minishell->bloq = 1;
	execute_multiple_pipe(process.quantity, process.content);
	g_minishell->bloq = 0;
}
