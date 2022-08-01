/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/01 16:28:01 by aramirez         ###   ########.fr       */
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
void	print_headline(void)
{
	print_string(GRN);
	print_string(get_user());
	print_string("@minishell % "RESET);
}
