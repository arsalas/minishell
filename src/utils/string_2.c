/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:04:27 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/09 20:41:31 by amurcia-         ###   ########.fr       */
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

char	*parse_token(char *input)
{
	int		i;
	char	*str;
	char	*aux;
	char	*aux2;

	str = ft_malloc(sizeof(char), false);
	i = 0;
	while (input[i])
	{
		printf("INSIDE BUCLE\n");
		if (input[i] == '\'')
			aux = parse_token2(input, &i);
		else if (input[i] == '$')
			aux = parse_token3(input, &i);
		if (input[i] == '"')
			aux = parse_token4(input, &i);
		else
			aux = parse_token5(input, &i);
		aux2 = ft_strdup(str);
		free(str);
		str = ft_strjoin_mod(aux2, aux);
	}
	printf("OUTSIDE BUCLE\n");
	printf("STR IS %s\n", str);
	return (str);
}

// char	*parse_token2(char *input)
// {
// 	int		start;
// 	int		i;
// 	char	*str;
// 	char	*aux;
// 	char	*aux2;

// 	str = malloc(sizeof(char));
// 	start = 0;
// 	i = 0;
// 	while (input[i])
// 	{
// 		if (input[i] == '\'')
// 		{
// 			i++;
// 			aux = parse_simple_quote(&input[i]);
// 			while (input[i] != '\'')
// 				i++;
// 			i++;
// 		}
// 		else if (input[i] == '$')
// 		{
// 			i++;
// 			if (!input[i])
// 				aux = ft_strdup("$");
// 			else
// 				aux = parse_expand_var(&input[i]);
// 			if (!(ft_isalpha(input[i]) == 1 || input[i] == '_'))
// 				i++;
// 			while (input[i] && (ft_isalnum(input[i]) == 1 || input[i] == '_'))
// 				i++;
// 		}
// 		else if (input[i] == '"')
// 		{
// 			i++;
// 			aux = parse_double_quote(&input[i]);
// 			aux = parse_double_quotes(aux);
// 			while (input[i] != '"')
// 				i++;
// 			i++;
// 		}
// 		else
// 		{
// 			start = i;
// 			while (input[i]
// 				&& (input[i] != '"' && input[i] != '$' && input[i] != '\''))
// 				i++;
// 			aux = ft_substr_mod(input, start, i - start);
// 		}
// 		aux2 = ft_strdup(str);
// 		free(str);
// 		str = ft_strjoin_mod(aux2, aux);
// 	}
// 	return (str);
// }