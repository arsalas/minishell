/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:04:27 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/10 22:38:13 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_double_quote2(char *input, int start, int i, char *str)
{
	char	*aux;

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
		str = ft_strjoin_mod(str, aux);
	}
	return (str);
}

char	*parse_double_quotes(char *input)
{
	int		start;
	int		i;
	char	*str;

	str = ft_malloc(sizeof(char), false);
	i = 0;
	start = 0;
	str = parse_double_quote2(input, start, i, str);
	return (str);
}

/**
 * @brief Parseamos por tokens
 * Al declarar el int i[1] estamos diciendo que es una array de 1 int,
 * que es lo mismo que un puntero
 * 
 * @param input 
 * @return char* 
 */
char	*parse_token(char *input)
{
	int		i[1];
	char	*str;
	char	*aux;
	char	*aux2;

	str = ft_malloc(sizeof(char), false);
	i[0] = 0;
	while (input[i[0]])
	{
		if (input[i[0]] == '\'')
			aux = parse_token2(input, i);
		else if (input[i[0]] == '$')
			aux = parse_token3(input, i);
		else if (input[i[0]] == '"')
			aux = parse_token4(input, i);
		else
			aux = parse_token5(input, i);
		aux2 = ft_strdup(str);
		free(str);
		str = ft_strjoin_mod(aux2, aux);
	}
	return (str);
}
