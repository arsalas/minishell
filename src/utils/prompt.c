/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/01 17:45:57 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Obtiene el nombre de usuario
 * 
 * @return user
 */
char	*get_user(void)
{
	return (getenv("USER"));
}

/**
 * @brief Pone en pantalla el encabeado del minishell
 * 
 */
void	print_prompt(void)
{
	printf(GRN"%s@minishell %% "RESET, get_user());
}
