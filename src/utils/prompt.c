/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 18:54:41 by amurcia-         ###   ########.fr       */
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
 * @brief Pone en pantalla el prompt del minishell
 */
void	print_prompt(void)
{
	printf(UMAG"%s@minishell %% "RESET, get_user());
}
