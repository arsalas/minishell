/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_aux2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:37:27 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/05 16:37:44 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	str = ft_substr_mod(input, start
			+ get_ignore_chars_process(&input[start]), len);
	free(g_minishell->input);
	return (str);
}
