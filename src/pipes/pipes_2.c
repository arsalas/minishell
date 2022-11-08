/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:58:05 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/08 15:58:35 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Espera a que terminen los procesos de los pipes
 * 
 * @param process 
 * @param pid 
 */
static void	wait_pipes_process(int process, int *pid)
{
	int	status;
	int	i;

	i = 0;
	while (i < process)
	{
		waitpid(pid[i], &status, 0);
		if (WIFEXITED(status))
			g_minishell->status = WEXITSTATUS(status);
		i++;
	}
}

void	calc_redirs(t_pipe *commands)
{
	int	j;

	j = 0;
	while (j < commands->redirs.quantity)
	{
		if (commands->redirs.info[0].types == DOUBBLE_REIN)
			g_minishell->bloq = 2;
		j++;
	}
}

void	iterate_process(int process, t_pipe *commands, int	**fd)
{
	int	i;

	i = 1;
	while (i < process - 1)
	{
		pid[i] = intermediate_pipe_father(fd[i - 1], fd[i]);
		if (pid[i] == 0)
			intermediate_pipe_child(fd[i - 1], fd[i], commands[i]);
		i++;
	}
}

/**
 * @brief Ejecuta los procesos para n pipes
 * 
 * @param process cantidad de procesos a ejecutar por los pipes
 */
void	execute_multiple_pipe(int process, t_pipe *commands)
{
	int	**fd;
	int	*pid;
	int	i;

	g_minishell->bloq = 1;
	get_input_parsed(commands);
	if (commands->redirs.quantity > 0)
		calc_redirs(commands);
	fd = create_fd(process - 1);
	pid = create_pid(process);
	pid[0] = first_pipe_father(fd[0]);
	if (pid[0] == 0)
		first_pipe_child(fd[0], commands[0]);
	iterate_process(process, commands, fd);
	pid[process - 1] = last_pipe_father(fd[process - 3], fd[process - 2]);
	if (pid[process - 1] == 0)
		last_pipe_child(fd[process - 2], commands[process - 1]);
	close(fd[process - 2][READ_END]);
	wait_pipes_process(process, pid);
}

void	get_pipes_redir(t_pipe *commands)
{
	int	i;

	i = 0;
	g_minishell->bloq = 1;
	get_input_parsed(commands);
	if (commands->redirs.quantity > 0)
	{
		while (i < commands->redirs.quantity)
		{
			if (commands->redirs.info[i].types == DOUBBLE_REIN)
				g_minishell->bloq = 2;
			i++;
		}
	}
}
