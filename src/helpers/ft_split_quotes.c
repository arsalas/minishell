/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:26 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/09 15:13:28 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_quantity_fragments(char const *str, char delimiter)
{
	bool	is_open_quote;
	char	quote;
	int		fragments;
	int		i;

	is_open_quote = false;
	quote = '\0';
	fragments = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == delimiter && !is_open_quote)
			fragments++;
		if (is_quote(str[i]) && is_open_quote && str[i] == quote)
			is_open_quote = false;
		else if (is_quote(str[i]) && !is_open_quote)
		{
			is_open_quote = true;
			quote = str[i];
		}
		i++;
	}
	return (fragments + 1);
}

static int	get_last_position_fragment(char const *str, char delimiter)
{
	bool	is_open_quote;
	char	quote;
	int		i;

	is_open_quote = false;
	quote = '\0';
	i = 0;
	while (str[i])
	{
		if (str[i] == delimiter && !is_open_quote)
			return (i);
		if (is_quote(str[i]) && is_open_quote && str[i] == quote)
			is_open_quote = false;
		else if (is_quote(str[i]) && !is_open_quote)
		{
			is_open_quote = true;
			quote = str[i];
		}
		i++;
	}
	return (i);
}

static bool	is_in_quotes(char start, char end)
{
	if (start == end && is_quote(start))
		return (true);
	return (false);
}

static void
	complete_arr(char **arr, char const *s, int fragments, char delimiter)
{
	int		i;
	int		last_position;
	int		pos;
	char	*aux;

	last_position = 0;
	pos = 0;
	i = 0;
	while (i < fragments)
	{
		last_position = get_last_position_fragment(&s[pos], delimiter);
		aux = ft_substr(s, pos, last_position);
		if (is_in_quotes(aux[0], aux[ft_strlen(aux) - 1]))
		{
			arr[i] = ft_substr(aux, 1, ft_strlen(aux) - 2);
			free(aux);
		}
		else
			arr[i] = aux;
		pos += last_position + 1;
		i++;
	}
}

//TODO --> mirar cuando es un dolar para expandir el valor
char	**ft_split_quotes(char const *s, char delimiter)
{
	char	**arr;
	int		fragments;

	fragments = get_quantity_fragments(s, delimiter);
	arr = get_memory(sizeof(char *) * fragments + 1, true);
	arr[fragments] = NULL;
	complete_arr(arr, s, fragments, delimiter);
	return (arr);
}
