/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:11:54 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/10 22:11:11 by amurcia-         ###   ########.fr       */
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

	str = NULL;
	i = 0;
	while (input[i] != '\'')
		i++;
	end = i;
	if (end > 0)
		str = ft_substr_mod(input, 0, end);
	return (str);
}

char	*parse_expand_var(char *input)
{
	int		i;
	int		start;
	int		end;
	char	*str;
	char	*aux;

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
	aux = ft_substr_mod(input, start, end - start);
	str = ft_strdup(get_env_var(aux));
	free(aux);
	return (str);
}
