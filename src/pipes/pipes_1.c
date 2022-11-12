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

void	execute_multiple_pipe_1(t_pipe *commands)
{
	int	j;

	j = 0;
	if (commands->redirs.quantity > 0)
	{
		while (j < commands->redirs.quantity)
		{
			if (commands->redirs.info[0].types == DOUBBLE_REIN)
				g_minishell->bloq = 2;
			j++;
		}
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
	execute_multiple_pipe_1(commands);
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
	wait_pipes_process(process, pid);
}

void	execute_single_pipe_1(t_pipe *commands)
{
	int	i;

	i = 0;
	while (i < commands->redirs.quantity)
	{
		if (commands->redirs.info[i].types == DOUBBLE_REIN)
			g_minishell->bloq = 2;
		i++;
	}
}

/**
 * @brief Ejecuta los procesos de un unico pipe
 * 
 */
void	execute_single_pipe(t_pipe *commands)
{
	int	fd[2];
	int	*pid;

	g_minishell->bloq = 1;
	get_input_parsed(commands);
	if (commands->redirs.quantity > 0)
		execute_single_pipe_1(commands);
	pid = create_pid(2);
	if (pipe(fd) == -1)
	{
		printf("Error in pipe\n");
		return ;
	}
	pid[0] = create_process();
	if (pid[0] == 0)
		first_pipe_child(fd, commands[0]);
	close(fd[WRITE_END]);
	pid[1] = create_process();
	if (pid[1] == 0)
		last_pipe_child(fd, commands[1]);
	wait_pipes_process(2, pid);
	g_minishell->bloq = 0;
}
