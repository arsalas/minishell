/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:27:34 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 16:46:57 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	echo_have_flag(char *input)
{
	int	count;

	if (!input)
		return (false);
	count = 1;
	if (input[0] == '-')
	{
		while (input[count] == 'N' || input[count] == 'n')
			count++;
		if (!input[count])
			return (true);
	}
	return (false);
}

// int	get_start_echo_input(char *input)
// {
// 	int	i;

// 	i = 4;
// 	while (input[i] == ' ')
// 		i++;
// 	return (i);
// }

// char	*extract_echo_input(char *input)
// {
// 	int	start;
// 	int	end;

// 	start = get_start_echo_input(input);
// 	end = ft_strlen(input);
// 	return (ft_substr(input, start, end - start));
// }

void	ft_echo(char **input)
{
	int		i;
	bool	have_flag;

	i = 1;
	have_flag = echo_have_flag(input[1]);
	if (have_flag)
		i++;
	while (input[i])
	{
		printf("%s", input[i]);
		if (input[i + 1])
			printf(" ");
		i++;
	}
	if (!have_flag)
		printf("\n");
	g_minishell->status = DEFAULT;
	ft_free_split(input);
}
