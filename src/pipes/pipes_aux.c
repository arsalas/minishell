/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:42:46 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/10 00:43:04 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Genera los file descriptors que se van a utilizar
 * para los pipes
 * 
 * @param pipes cantidad de pipes
 * @return array con los fd[2]
 */
int	**create_fd(int pipes)
{
	int	i;
	int	**fd;

	i = 0;
	fd = ft_malloc(sizeof(int *) * pipes, false);
	while (i < pipes)
	{
		fd[i] = ft_malloc(sizeof(int) * 2, false);
		i++;
	}
	return (fd);
}

/**
 * @brief Genera un pid para cada proceso que se va a ejecutar
 * 
 * @param process cantidad de procesos a ejecutar
 * @return array de pids
 */
int	*create_pid(int process)
{
	return (ft_malloc(sizeof(int) * process, false));
}
