/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:04:27 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/05 19:07:36 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_double_quotes(char *input)
{
	int		start;
	int		i;
	char	*str;
	char	*aux;

	str = malloc(sizeof(char));
	start = 0;
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
	return (str);
}

char	*parse_token2(char *input)
{
	int		start;
	int		i;
	char	*str;
	char	*aux;
	char	*aux2;

	str = malloc(sizeof(char));
	start = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
		{
			i++;
			aux = parse_simple_quote(&input[i]);
			while (input[i] != '\'')
				i++;
			i++;
		}
		else if (input[i] == '$')
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
		}
		else if (input[i] == '"')
		{
			i++;
			aux = parse_double_quote(&input[i]);
			aux = parse_double_quotes(aux);
			while (input[i] != '"')
				i++;
			i++;
		}
		else
		{
			start = i;
			while (input[i]
				&& (input[i] != '"' && input[i] != '$' && input[i] != '\''))
				i++;
			aux = ft_substr_mod(input, start, i - start);
		}
		aux2 = ft_strdup(str);
		free(str);
		str = ft_strjoin_mod(aux2, aux);
	}
	return (str);
}
