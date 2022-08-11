/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:14:01 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 13:41:41 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_var(char *var)
{
	return (get_env_var(var));
}

/**
 * @brief Comprueba si hay una variable de entorno en la string
 * 
 * @param str 
 * @return bool 
 */
bool	is_var(char *str)
{
	int		i;
	char	last_char;

	i = 0;
	last_char = '\0';
	while (str[i])
	{
		if (last_char == '$' && str[i] == '$')
			return (false);
		if (last_char == '$' && str[i] != '$')
			return (true);
		last_char = str[i];
		i++;
	}
	return (false);
}

char	*get_var_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
	}
}