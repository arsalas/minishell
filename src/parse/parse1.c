/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:16:06 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/07 18:37:55 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* Miramos si solamente nos dan un pipe, sin nada mas
*/
void	ft_pipe_errors(int count)
{
	if (g_minishell->input[0] == 124 && g_minishell->input[1] == '\0')
	{
		printf("syntax error near unexpected token `|'\n");
		close_minishell(0);
	}
	else if (g_minishell->input[count] == 124
		&& g_minishell->input[count + 1] == '\0')
	{
		printf("Error\nDame un comando\n");
		close_minishell(0);
	}
}

/*
* 1 - Si nos encontramos un pipe seguido de otro, no es un pipe
* Seria un separador
* 2 - Si el pipe esta entre comillas, forma parte de un string, no es un pipe
*/
int	ft_no_pipe(int count)
{
	if ((g_minishell->input[count] == 124
			&& g_minishell->input[count + 1] == 124)
		&& (g_minishell->input[count + 2] != '\0'))
	{
		count += 2;
	}
	else if (g_minishell->input[count] == 34 || g_minishell->input[count] == 39)
		g_minishell->parse.quo++;
	return (count);
}

/*
* Miramos la cantidad de pipes
* Aqui creamos traces, un array bidimensional con la info de cada pipe
*/
void	ft_number_pipes(void)
{
	int	count;

	count = 0;
	while (g_minishell->input[count])
	{
		ft_pipe_errors(count);
		count = ft_no_pipe(count);
		if (g_minishell->input[count] == 124
			&& (g_minishell->parse.quo % 2 == 0 || g_minishell->parse.quo == 0))
		{
			g_minishell->parse.pipe++;
		}
		count++;
	}
	if (count > 0)
		g_minishell->traces = ft_split(g_minishell->input, '|');
}

/*
* Contamos la cantidad de comillas, siempre y cuando no esten despues del \
* Si hay un \, se guarda dentro de la estructura g_minishell->slash
*/
void	ft_odd_quotes(char *traces)
{
	int	count;

	count = 0;
	while (traces[count])
	{
		if (traces[count] == 92
			&& (traces[count + 1] == 34 || traces[count + 1] == 39))
		{
			g_minishell->parse.slash++;
			count += 2;
		}
		else if (traces[count] == 34)
			g_minishell->parse.double_quo++;
		else if (traces[count] == 39)
			g_minishell->parse.simple_quo++;
		count++;
	}
}
