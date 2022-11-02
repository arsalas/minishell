/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:31:29 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/02 18:48:17 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Elimina una variable de entorno
 * 
 * @param name 
 */
void	ft_unset(char **tokens)
{
	int	count;

	count = 1;
	g_minishell->status = DEFAULT;
	while (tokens[count])
	{
		delete_env(tokens[count]);
		count++;
	}
	ft_free_split(tokens);
}
