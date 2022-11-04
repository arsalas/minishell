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
