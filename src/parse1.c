/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:16:06 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/01 18:09:36 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_odd_quotes(t_minishell *minishell)
{
	int	count;

	count = 0;
	while (minishell->input[count])
	{
		if (minishell->input[count] == 34)
			minishell->double_quo++;
		else if (minishell->input[count] == 39)
			minishell->simple_quo++;
		count++;
	}
	if ((info->double_quo > 0 && minishell->double_quo % 2 != 0)
		|| info->simple_quo > 0 && minishell->simple_quo % 2 != 0)
	{
		printf("Error\n Comillas no cerradas\n");
		exit (0);
	}
}

void	ft_number_pipes(t_minishell *minishell)
{
	int	count;

	count = 0;
	while (minishell->input[count])
	{
		if (minishell->input[count] == 124)
			minishell->pipe++;
		count++;
	}
}

void	ft_count_commands(t_minishell *minishell)
{
	int	count;

	count = 0;
	while (minishell->input[count])
	{
		if (minishell->input[count] == '-'
			&& ft_is_alpha(minishell->input[count + 1]) == 1)
			minishell->flag++;
		count++;
	}
}
