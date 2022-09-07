/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_aux1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:53:59 by aramirez          #+#    #+#             */
/*   Updated: 2022/09/07 19:56:03 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// bool	get_quotes_open(char *input, int i, bool is_slash, bool is_open_quote, char quote)
// {
// 	if (input[i] == '\\')
// 		is_slash = !is_slash;
// 	if (((input[i] == '"' || input[i] == '\'') && !is_slash
// 			&& is_open_quote && quote == input[i]))
// 		is_open_quote = false;
// 	return (is_open_quote);
// }

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
		if (input[i] == '\\')
			is_slash = !is_slash;
		if (((input[i] == '"' || input[i] == '\'') && !is_slash
				&& is_open_quote && quote == input[i]))
			is_open_quote = false;
		else if (!is_open_quote && !is_slash
			&& (input[i] == '"' || input[i] == '\''))
		{
			is_open_quote = true;
			quote = input[i];
		}
		else if (input[i] == '|' && !is_slash && !is_open_quote)
			pipes++;
		if (input[i] != '\\')
			is_slash = false;
	}
	return (pipes + 1);
}

/**
 * @brief Obtiene la posicion donde termina un proceso
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
		if (input[i] == '\\')
			is_slash = !is_slash;
		if (((input[i] == '"' || input[i] == '\'') && !is_slash
				&& is_open_quote && quote == input[i]))
			is_open_quote = false;
		else if (!is_open_quote && !is_slash
			&& (input[i] == '"' || input[i] == '\''))
		{
			is_open_quote = true;
			quote = input[i];
		}
		else if (input[i] == '|' && !is_slash && !is_open_quote)
			return (i);
		if (input[i] != '\\')
			is_slash = false;
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
	return (ft_substr(input, 0, len));
}

/**
 * @brief Obtiene cuantos caracteres se han de ignorar en el input del proceso
 * 
 * @param str 
 * @return int 
 */
int	get_ignore_chars_process(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '|' || str[i] == ' ')
		i++;
	return (i);
}

/**
 * @brief Extrae el input de los procesos
 * 
 * @param input 
 * @return char* 
 */
char	*extract_others_process_input(char *input)
{
	int		len;
	int		start;
	char	*str;

	start = get_finish_process_in_input(input);
	len = ft_strlen(input);
	str = ft_substr(input, start
			+ get_ignore_chars_process(&input[start]), len);
	free(g_minishell->input);
	return (str);
}
