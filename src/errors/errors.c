/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:17:36 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/02 18:35:17 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Cierra el minishell y libera toda la memoria reservada
 */
void	close_minishell(void)
{
	free_memory();
	exit(0);
}

/**
 * @brief Gestion de error al reservar memoria
 */
void	memory_error(void)
{
	perror("Error al reservar memoria\n");
	close_minishell();
}
