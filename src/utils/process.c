/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:15:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/03 14:18:20 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Crea un proceso nuevo
 * 
 * @return pimd nuevo proceso 
 */
int	create_process(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		fork_error();
	return (pid);
}
