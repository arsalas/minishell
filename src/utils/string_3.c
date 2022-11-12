/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:07:10 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/11 17:34:48 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_double_quote(char *input)
{
	int		i;
	int		end;
	char	*str;

	str = NULL;
	i = 0;
	while (input[i] && input[i] != '"')
		i++;
	end = i;
	if (end > 0)
		str = ft_substr_mod(input, 0, end);
	return (str);
}

/**
 * @brief Obtiene el siguiente token
 * 
 * @param input input aprartir del primer token 
 * @return token sin parsear
 */
int	get_next_token_len2(char *input)
{
	int		i;
	char	quote;

	i = 0;
	if (!input)
		return (0);
	while (input[i] && input[i] != ' ')
	{
		if (is_quote(input[i]))
		{
			quote = input[i];
			i++;
			while (input[i] != quote)
				i++;
		}
		i++;
	}
	return (i);
}

char	*get_next_token2(char *input)
{
	int		i;
	char	quote;

	i = 0;
	if (!input || ft_strlen(input) == 0)
		return (NULL);
	while (input[i] && input[i] != ' ')
	{
		if (is_quote(input[i]))
		{
			quote = input[i];
			i++;
			while (input[i] != quote)
				i++;
		}
		i++;
	}
	return (ft_substr_mod(input, 0, i));
}

char	**get_tokens(char *input)
{
	char	**arr;
	char	*token;
	int		i;
	int		len;

	(void) token;
	arr = malloc(sizeof(char *));
	arr[0] = NULL;
	i = 0;
	len = 0;
	while (true)
	{
		token = get_next_token2(&input[len]);
		if (!token)
			break ;
		arr = push_string(arr, parse_token(token));
		free(token);
		len += get_next_token_len2(&input[len]);
		while (input[len] == ' ' || input[len] == '\t')
			len++;
		i++;
	}
	return (arr);
}
