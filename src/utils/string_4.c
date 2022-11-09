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

char	*parse_token2(char *input, int i)
{
	char	*aux;

	*i = *i + 1;
	aux = parse_simple_quote(&input[i]);
	while (input[i] != '\'')
		*i = *i + 1;
	*i = *i + 1;
	return (aux);
}

char	*parse_token3(char *input, int i)
{
	char	*aux;

	*i = *i + 1;
	if (!input[i])
		aux = ft_strdup("$");
	else
		aux = parse_expand_var(&input[i]);
	if (!(ft_isalpha(input[i]) == 1 || input[i] == '_'))
		*i = *i + 1;
	while (input[i] && (ft_isalnum(input[i]) == 1 || input[i] == '_'))
		*i = *i + 1;
	return (aux);
}

char	*parse_token4(char *input, int i)
{
	char	*aux;

	*i = *i + 1;
	aux = parse_double_quote(&input[i]);
	aux = parse_double_quotes(aux);
	while (input[i] != '"')
		*i = *i + 1;
	*i = *i + 1;
	return (aux);
}

char	*parse_token5(char *input, int i)
{
	char	*aux;
	int		start;

	start = i;
	while (input[i]
		&& (input[i] != '"' && input[i] != '$' && input[i] != '\''))
		*i = *i + 1;
	aux = ft_substr_mod(input, start, i - start);
	return (aux);
}
