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
	if (c == '\'' || c == '"' || c == '\\' || c == '$' || c == '>'|| c == '<')
		return (true);
	return (false);
}
