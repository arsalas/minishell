/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:18:49 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/04 17:45:40 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_double_quote(char *input)
{
	int		i;
	int		end;
	char	*str;

	str = malloc(sizeof(char));
	i = 0;
	while (input[i] && input[i] != '"')
		i++;
	end = i;
	if (end > 0)
		str = ft_substr_mod(input, 0, end);
	return (str);
}

char	*parse_quotes_more(char *input, char aux, char *str, int start)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '$')
		{
			i++;
			aux = parse_expand_var(&input[i]);
			if (!(ft_isalpha(input[i]) == 1 || input[i] == ' '))
				i++;
			while (input[i] && (ft_isalnum(input[i]) == 1 || input[i] == '_'))
				i++;
		}
		else
		{
			start = i;
			while (input[i] && input[i] != '$')
				i++;
			aux = ft_substr_mod(input, start, i - start);
		}
		str = ft_strjoin(str, aux);
	}
}

char	*parse_double_quotes(char *input)
{
	int		start;
	char	*str;
	char	*aux;

	str = ft_malloc(sizeof(char), false);
	start = 0;
	str = parse_quotes_more(input, str, start);
	return (str);
}
