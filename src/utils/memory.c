/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:57:45 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/02 18:34:58 by aramirez         ###   ########.fr       */
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

/**
 * @brief Reasigna un espacio de memoria
 * 
 * @param ptr puntero con la memoria reservada
 * @param size nuevo size a reservar
 * @return void* nuevo puntero con la memoria reasignada
 */
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (get_memory(size));
	if (!size)
		return (ptr);
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}

/**
 * @brief Libera toda la memoria reservada
 */
void	free_memory(void)
{
	not_implemented();
}
