/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:34:17 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/08 17:52:26 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_quotes_bucle(char *input, int i, char *aux)
{
	i++;
	aux = parse_simple_quote(&input[i]);
	while (input[i] != '\'')
		i++;
	i++;
	return (i);
}

char	*get_str_parse(char *input, int start, char *str)
{
	char	*aux;
	char	*aux2;
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			i = parse_quotes_bucle(input, i, aux);
		else if (input[i] == '$')
			i = parse_expand(input, i, aux);
		else if (input[i] == '"')
			i = parse_quotes(input, i, aux);
		else
		{
			start = i;
			i = get_substr_pos(input, i);
			aux = ft_substr_mod(input, start, i - start);
		}
		aux2 = ft_strdup(str);
		free(str);
		str = ft_strjoin_mod(aux2, aux);
	}
	return (str);
}

char	*parse_token2(char *input)
{
	int		start;
	char	*str;

	str = ft_malloc(sizeof(char), false);
	start = 0;
	return (get_str_parse(input, start, str));
}
