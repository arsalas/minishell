/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:11:54 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/02 20:07:18 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**push_string(char **arr, char *string)
{
	int		len;
	char	**new_arr;

	len = get_array_len(arr);
	new_arr = ft_realloc(arr, sizeof(char *) * (len + 2));
	new_arr[len] = string;
	new_arr[len + 1] = NULL;
	return (new_arr);
}

bool	is_delim(char c)
{
	if (c == '\'' || c == '"' || c == '$')
		return (true);
	return (false);
}

char	*parse_simple_quote(char *input)
{
	int		i;
	int		end;
	char	*str;

	// str = malloc(sizeof(char));
	str = NULL;
	i = 0;
	while (input[i] != '\'')
		i++;
	end = i;
	if (end > 0)
		str = ft_substr(input, 0, end);
	return (str);
}

char	*parse_expand_var(char *input)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	i = 0;
	start = 0;
	if (!(ft_isalpha(input[i]) == 1 || input[i] == '_'))
	{
		if (input[i] == '?')
			return (ft_itoa(g_minishell->status));
		return (ft_strdup(&input[1]));
	}
	start = i;
	while (input[i] && (ft_isalnum(input[i]) == 1 || input[i] == '_'))
		i++;
	end = i;
	str = ft_substr(input, start, end - start);
	str = ft_strdup(get_env_var(str));
	return (str);
}

char	*parse_double_quote(char *input)
{
	int		i;
	int		end;
	char	*str;

	// str = malloc(sizeof(char));
	str = NULL;
	i = 0;
	while (input[i] && input[i] != '"')
		i++;
	end = i;
	if (end > 0)
		str = ft_substr(input, 0, end);
	return (str);
}

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
			aux = ft_substr(input, start, i - start);
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
			aux = ft_substr(input, start, i - start);
		}
		str = ft_strjoin(str, aux);
	}
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
	return (ft_substr(input, 0, i));
}

char	**get_tokens2(char *input)
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
		arr = push_string(arr, parse_token2(token));
		len += get_next_token_len2(&input[len]);
		while (input[len] == ' ' || input[len] == '\t')
			len++;
		i++;
	}
	return (arr);
}
