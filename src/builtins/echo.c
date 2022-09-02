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
	(void)input;
	return (false);
}

int	get_start_echo_input(char *input)
{
	int	i;

	i = 4;
	while (input[i] == ' ')
		i++;
	return (i);
}

char	*extract_echo_input(char *input)
{
	int	start;
	int	end;

	start = get_start_echo_input(input);
	end = ft_strlen(input);
	return (ft_substr(input, start, end - start));
}

void	ft_echo(char *input)
{
	char	*echo;
	char	**tokens;
	int		i;
	bool	have_flag;

	have_flag = false;
	echo = extract_echo_input(input);
	tokens = parse_echo(echo);
	i = 0;
	while (tokens[i])
	{
		if (i == 0 && ft_strcmp(tokens[i], "-n", true))
			have_flag = true;
		else
			printf("%s ", tokens[i]);
		i++;
	}
	if (!have_flag)
		printf("\n");
	g_minishell->status = DEFAULT;
	// execute_echo(echo, echo_have_flag(input));
}
