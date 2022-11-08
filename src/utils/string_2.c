/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:04:27 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/08 17:49:37 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expand_vars(int i, char *input, char *aux)
{
	i++;
	aux = parse_expand_var(&input[i]);
	if (!(ft_isalpha(input[i]) == 1 || input[i] == ' '))
		i++;
	while (input[i] && (ft_isalnum(input[i]) == 1 || input[i] == '_'))
		i++;
	return (i);
}

char	*parse_double_quotes(char *input)
{
	int		start;
	int		i;
	char	*str;
	char	*aux;

	str = ft_malloc(sizeof(char), false);
	start = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '$')
			i = expand_vars(i, input, aux);
		else
		{
			start = i;
			while (input[i] && input[i] != '$')
				i++;
			aux = ft_substr_mod(input, start, i - start);
		}
		str = ft_strjoin_mod(str, aux);
	}
	return (str);
}

int	parse_expand(char *input, int i, char *aux)
{
	i++;
	if (!input[i])
		aux = ft_strdup("$");
	else
		aux = parse_expand_var(&input[i]);
	if (!(ft_isalpha(input[i]) == 1 || input[i] == '_'))
		i++;
	while (input[i] && (ft_isalnum(input[i]) == 1 || input[i] == '_'))
		i++;
	return (i);
}

int	parse_quotes(char *input, int i, char *aux)
{
	i++;
	aux = parse_double_quote(&input[i]);
	aux = parse_double_quotes(aux);
	while (input[i] != '"')
		i++;
	i++;
	return (i);
}

int	get_substr_pos(char *input, int i)
{
	while (input[i]
		&& (input[i] != '"' && input[i] != '$' && input[i] != '\''))
	i++;
	return (i);
}
