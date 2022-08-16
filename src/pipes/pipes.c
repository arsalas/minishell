/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:24:05 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/12 13:52:09 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Ejecuta los procesos para n pipes
 * 
 * @param process cantidad de procesos a ejecutar por los pipes
 */
void	execute_multiple_pipe(int process, t_pipe *commands)
{
	int	status;
	int	**fd;
	int	*pid;
	int	i;

	(void)commands;
	i = 1;
	fd = create_fd(process - 1);
	pid = create_pid(process);
	pid[0] = first_pipe_father(fd[0]);
	if (pid[0] == 0)
		first_pipe_child(fd[0], commands[0]);
	while (i < process - 1)
	{
		pid[i] = intermediate_pipe_father(fd[i - 1], fd[i]);
		if (pid[i] == 0)
			intermediate_pipe_child(fd[i - 1], fd[i], commands[i]);
		i++;
	}
	pid[process - 1] = last_pipe_father(fd[process - 3], fd[process - 2]);
	if (pid[process - 1] == 0)
		last_pipe_child(fd[process - 2], commands[process - 1]);
	close(fd[process - 2][READ_END]);
	i = 0;
	while (i < process)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
}

/**
 * @brief Ejecuta los procesos de un unico pipe
 * 
 */
void	execute_single_pipe(t_pipe *commands)
{
	int	status;
	int	fd[2];
	int	*pid;

	pid = create_pid(2);
	// TODO --> comprobar que los pipes salgan bien
	pipe(fd);
	pid[0] = create_process();
	if (pid[0] == 0)
		first_pipe_child(fd, commands[0]);
	close(fd[WRITE_END]);
	pid[1] = create_process();
	if (pid[1] == 0)
		last_pipe_child(fd, commands[1]);
	wait(&status);
}

/**
 * @brief Ejecuta los pipes
 * 
 * @param process cantidad de procesos a ejecutar por los pipes
 */
void	execute_pipe(t_process process)
{
	if (process.quantity == 0)
		return ;
	if (process.quantity == 1)
	{
		ft_execute(process.content[0]);
		return ;
	}
	if (process.quantity == 2)
		return (execute_single_pipe(process.content));
	execute_multiple_pipe(process.quantity, process.content);
}
