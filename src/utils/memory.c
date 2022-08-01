/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:57:45 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/01 16:57:59 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*get_memory(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		memory_error();
	return (mem);
}
