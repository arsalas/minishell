/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:23:15 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/09 19:32:35 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_token2(char *input, int *i)
{
	char	*aux;

	i[0]++;
	aux = parse_simple_quote(&input[i[0]]);
	while (input[i[0]] != '\'')
		i[0]++;
	i[0]++;
	return (aux);
}

char	*parse_token3(char *input, int *i)
{
	char	*aux;

	i[0]++;
	if (!input[i[0]])
		aux = ft_strdup("$");
	else
		aux = parse_expand_var(&input[i[0]]);
	if (!(ft_isalpha(input[i[0]]) == 1 || input[i[0]] == '_'))
		i++;
	while (input[i[0]] && (ft_isalnum(input[i[0]]) == 1 || input[i[0]] == '_'))
		i[0]++;
	return (aux);
}

char	*parse_token4(char *input, int *i)
{
	char	*aux;

	i[0]++;
	aux = parse_double_quote(&input[i[0]]);
	aux = parse_double_quotes(aux);
	while (input[i[0]] != '"')
		i[0]++;
	i[0]++;
	return (aux);
}

char	*parse_token5(char *input, int *i)
{
	char	*aux;
	int		start;

	start = i[0];
	while (input[i[0]]
		&& (input[i[0]] != '"' && input[i[0]] != '$' && input[i[0]] != '\''))
		i[0]++;
	aux = ft_substr_mod(input, start, i[0] - start);
	return (aux);
}
