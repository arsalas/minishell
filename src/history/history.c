/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:27:51 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/11 16:29:30 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Creamos un historial
 * 
 */
void	ft_read_history(void)
{
	add_history(g_minishell->input);
}

/**
 * @brief Limpiamos el historial
 * 
 */
void	ft_clear_history(void)
{
	clear_history();
}
