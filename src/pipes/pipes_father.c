/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_father.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:37:31 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/10 00:40:45 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Ejecuta el primer proceso de un pipe
 * 
 * @param fd 
 * @return pid del proceso generado
 */
int	first_pipe_father(int *fd)
{
	pipe(fd);
	return (create_process());
}

/**
 * @brief Ejecuta los procesos intermedios en un pipe
 * 
 * @param fd1 
 * @param fd2 
 * @return pid del proceso generado 
 */
int	intermediate_pipe_father(int *fd1, int *fd2)
{
	close(fd1[WRITE_END]);
	pipe(fd2);
	return (create_process());
}

/**
 * @brief Ejecuta el ultimo proceso del padre
 * 
 * @param fd1 
 * @param fd2 
 * @return pid del proceso generado
 */
int	last_pipe_father(int *fd1, int *fd2)
{
	close(fd1[READ_END]);
	close(fd2[WRITE_END]);
	return (create_process());
}
