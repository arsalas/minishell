/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:34:14 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/02 18:34:00 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Gestion de los metodos no implementados
 */
void	not_implemented(void)
{
	printf("Not implemented yet\n");
}

/**
 * @brief Indica si el caracter pasado es una comilla
 * 
 * @param c character
 * @return bool 
 */
bool	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (true);
	return (false);
}

/**
 * @brief Indica si el caracter pasado es un caracter escapado
 * 
 * @param c character
 * @return bool 
 */
bool	is_scaped_char(char c)
{
	if (c == '\'' || c == '"' || c == '\\'
		|| c == '$' || c == '>' || c == '<')
		return (true);
	return (false);
}

/**
 * @brief Indica si el caracter pasado es una redireccion
 * 
 * @param c 
 * @return bool 
 */
bool	is_redirect(char c)
{
	if (c == '>' || c == '<')
		return (true);
	return (false);
}

/**
 * @brief Indica si el caracter pasado es una redireccion
 * 
 * @param c 
 * @return bool 
 */
bool	is_doubble_redirect(char *raw, int count)
{
	if ((raw[count] == '>' && raw[count + 1] == '>')
		|| (raw[count] == '<' && raw[count + 1] == '<'))
		return (true);
	return (false);
}

bool	is_strdigit(char *str)
{
	int		count;

	count = 0;
	while (str[count])
	{
		if (ft_isdigit(str[count]) != 1)
			return (false);
		count++;
	}
	return (true);
}

bool	is_correct_tokens(char *raw)
{
	int		count;
	bool	open_quote;
	char	quote;

	count = 0;
	open_quote = false;
	while (raw[count])
	{
		if (is_quote(raw[count]) && !open_quote)
		{
			open_quote = true;
			quote = raw[count];
		}
		if (is_quote(raw[count]) && raw[count] == quote)
			open_quote = !open_quote;
		if (raw[count] == '>' && raw[count + 1] == '>' && !open_quote)
		{
			if (raw[count + 2] == '>' || raw[count + 2] == '<' || raw[count + 2] == '&')
			{
				printf("syntax error near unexpected token: `%c\'\n", raw[count + 2]);
				return (false);
			}
		}
		else if (raw[count] == '<' && raw[count + 1] == '<' && !open_quote)
		{
			if (raw[count + 2] == '>' || raw[count + 2] == '<' || raw[count + 2] == '&')
			{
				printf("syntax error near unexpected token: `%c\'\n", raw[count + 2]);
				return (false);
			}
		}
		count++;
	}
	return (true);
}
