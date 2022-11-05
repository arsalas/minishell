/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_aux1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:53:59 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/05 17:14:27 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_open_quote(bool is_open_quote, bool is_slash, char *input, int i)
{
	if (!is_open_quote && !is_slash && (input[i] == '"' || input[i] == '\''))
		return (true);
	return (false);
}

bool	check_slash(char *input, int i, bool is_slash)
{
	if (input[i] == '\\')
	{
		is_slash = !is_slash;
		return (false);
	}
	return (is_slash);
}

/**
 * @brief Obtiene la cantidad de procesos que tiene el input
 * 
 * @param input 
 * @return int 
 */
int	get_quantity_process_in_input(char *input)
{
	bool	is_open_quote;
	bool	is_slash;
	char	quote;
	int		pipes;
	int		i;

	is_open_quote = false;
	is_slash = false;
	pipes = 0;
	quote = '\0';
	i = 0;
	while (input[i++])
	{
		is_slash = check_slash(input, i, is_slash);
		if (((input[i] == '"' || input[i] == '\'') && !is_slash && is_open_quote && quote == input[i]))
			is_open_quote = false;
		else if (check_open_quote(is_open_quote, is_slash, input, i))
		{
			is_open_quote = true;
			quote = input[i];
		}
		else if (input[i] == '|' && !is_slash && !is_open_quote)
			pipes++;
		is_slash = check_slash(input, i, is_slash);
	}
	return (pipes + 1);
}

/**
 * @brief Obtiene la posición donde termina un proceso
 * 
 * @param input 
 * @return int 
 */
int	get_finish_process_in_input(char *input)
{
	bool	is_open_quote;
	bool	is_slash;
	char	quote;
	int		i;

	is_open_quote = false;
	is_slash = false;
	quote = '\0';
	i = 0;
	while (input[i++])
	{
		is_slash = check_slash(input, i, is_slash);
		if (((input[i] == '"' || input[i] == '\'')
				&& !is_slash && is_open_quote && quote == input[i]))
			is_open_quote = false;
		else if (check_open_quote(is_open_quote, is_slash, input, i))
		{
			is_open_quote = true;
			quote = input[i];
		}
		else if (input[i] == '|' && !is_slash && !is_open_quote)
			return (i);
		is_slash = check_slash(input, i, is_slash);
	}
	return (i);
}

/**
 * @brief Obtiene el contenido de un proceso a partir del input
 * 
 * @param input 
 * @return char* 
 */
char	*extract_content_process_input(char *input)
{
	int	len;

	len = get_finish_process_in_input(input);
	return (ft_substr_mod(input, 0, len));
}
