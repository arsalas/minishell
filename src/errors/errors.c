/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:17:36 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/03 14:24:42 by aramirez         ###   ########.fr       */
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
	perror("Memory error\n");
	close_minishell();
}

/**
 * @brief Printa por pantalla comando no encontrado
 * 
 * @param cmd comando utilizado
 */
void	cmd_not_found(char *cmd)
{
	printf("minishell: %s: command not found\n", cmd);
}

/**
 * @brief Gestion de error al crear un fork
 */
void	fork_error(void)
{
	perror("Error in process fork\n");
	close_minishell();
}
