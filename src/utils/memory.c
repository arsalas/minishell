/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:57:45 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/01 17:47:45 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Reserva memoria
 * 
 * @param size Memoria a reservar
 * @return void* puntero a la memoria reservada
 */
void	*get_memory(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		memory_error();
	return (mem);
}
