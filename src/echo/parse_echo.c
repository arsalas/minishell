/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:14:08 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/17 15:51:27 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//TODO --> escapar comillas

/**
 * @brief Obtiene la posicion inicial de el contenido de echo
 * 
 * @param input 
 * @return int 
 */
int	get_start_echo(char *input)
{
	int	i;

	i = 4;
	while (input[i] == ' ')
		i++;
	return (i);
}

char	*extract_next_echo_token(char *input)
{
	char	quote;
	int		i;
	int		start;

	i = 0;
	if (is_quote(input[0]))
	{
		quote = input[0];
		i = 1;
	}
	else
		quote = '\0';
	start = i;
	if (quote)
	{
		while ((input[i] && input[i] != quote) || (input[i] == quote && input[i - 1] == '\\'))
			i++;
	}
	else
	{
		while (input[i] && (!is_quote(input[i]) || (is_quote(input[i]) && input[i - 1] == '\\') ))
			i++;
	}
	return (ft_substr(input, start, i - start));
}

int	get_next_echo_token_start(char *input)
{
	char	quote;
	int		i;

	i = 0;
	if (is_quote(input[0]))
	{
		quote = input[0];
		i = 1;
	}
	else
		quote = '\0';
	if (quote)
	{
		while ((input[i] && input[i] != quote) || (input[i] == quote && input[i - 1] == '\\'))
			i++;
	}
	else
	{
		while (input[i] && (!is_quote(input[i]) || (is_quote(input[i]) && input[i - 1] == '\\') ))
			i++;
	}
	if (quote == '\'' || quote == '"')
		i += 1;
	return (i);
}

/**
 * @brief Parsea el comando echo
 * 
 * @param input 
 * @return char** 
 */
char	**parse_echo(char *input)
{
	char	**tokens;
	int		i;
	int		start;

	start = 0;
	tokens = get_memory(sizeof(char *), true);
	i = 0;
	tokens[i] = extract_next_echo_token(input);
	while (ft_strlen(tokens[i]) > 0)
	{
		start += get_next_echo_token_start(&input[start]);
		i++;
		tokens = ft_realloc(tokens, sizeof(char *) * (i + 1));
		tokens[i] = extract_next_echo_token(&input[start]);
	}
	tokens = ft_realloc(tokens, sizeof(char *) * (i + 1));
	tokens[i] = NULL;
	return (tokens);
}
