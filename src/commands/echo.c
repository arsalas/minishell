/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:27:34 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/01 18:32:28 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Comprueba si hay alguna variable
 * 
 * @param str string
 * @return bool 
 */
bool	have_var(char *str)
{
	int		i;
	bool	is_found;

	i = 0;
	is_found = false;
	while (str[i])
	{
		if (is_found && ft_isalpha(str[i]) == 1)
			return (true);
	}
	return (false);
}

/**
 * @brief Ejecuta el comando echo
 * 
 * @param str string a printar
 * @param have_flag indica si incluye la flag de salto de linea
 */
void	cmd_echo(char *str, bool have_flag)
{
	printf("%s", str);
	if (have_flag)
		printf("\n");
}
