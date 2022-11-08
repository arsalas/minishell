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
 * @brief Ejecuta los procesos de un unico pipe
 * 
 */
void	execute_single_pipe(t_pipe *commands)
{
	int	fd[2];
	int	*pid;

	get_pipes_redir(commands);
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

void	execute_command_fork(t_process process, t_fd_redirs	fds, int status)
{
	pid_t		pid;

	pid = create_process();
	if (pid == 0)
	{
		fds = ft_get_redir(process.content[0]);
		if (fds.input != -1)
			dup2(fds.input, STDIN_FILENO);
		if (fds.output != -1)
			dup2(fds.output, STDOUT_FILENO);
		ft_execute(process.content[0]);
		exit(g_minishell->status);
	}
	waitpid(pid, &status, 0);
	g_minishell->bloq = 0;
	if (WIFEXITED(status))
		g_minishell->status = WEXITSTATUS(status);
	close(fds.input);
	close(fds.output);
	return ;
}

void	execute_single_process(t_process process)
{
	int			status;
	t_fd_redirs	fds;
	int			saved_stdout;
	int			saved_stdin;

	fds.input = -1;
	fds.output = -1;
	status = 0;
	get_pipes_redir(&process.content[0]);
	if (process.content->command != C_CD && process.content->command != C_EXIT
		&& process.content->command != C_EXPORT
		&& process.content->command != C_UNSET)
		execute_command_fork(process, fds, status);
	g_minishell->bloq = 0;
	saved_stdout = dup(STDOUT_FILENO);
	saved_stdin = dup(STDIN_FILENO);
	fds = ft_get_redir(process.content[0]);
	if (fds.input != -1)
		dup2(fds.input, STDIN_FILENO);
	if (fds.output != -1)
		dup2(fds.output, STDOUT_FILENO);
	ft_execute(process.content[0]);
	dup2(saved_stdout, STDOUT_FILENO);
	dup2(saved_stdin, STDIN_FILENO);
}

bool	is_correct_input(t_process process, int i)
{
	if (ft_strlen(process.content[i].raw) == 0
		|| ft_strcmp(process.content[i].raw, "|", false)
		|| ft_strcmp(process.content[i].raw, "| ", false))
	{
		printf("syntax error near unexpected token: `|\'\n");
		return (false);
	}
	if (is_odd_quotes(process.content[i].raw))
		return (false);
	if (!is_correct_tokens(process.content[i].raw))
		return (false);
	return (true);
}

/**
 * @brief Ejecuta los pipes
 * 
 * @param process cantidad de procesos a ejecutar por los pipes
 */
void	execute_pipe(t_process process)
{
	int	i;

	i = 0;
	while (i < process.quantity)
	{
		if (!is_correct_input(process, i))
			return ;
		i++;
	}
	if (process.quantity == 0)
		return ;
	if (process.quantity == 1)
		return (execute_single_process(process));
	if (process.quantity == 2)
		return (execute_single_pipe(process.content));
	g_minishell->bloq = 1;
	execute_multiple_pipe(process.quantity, process.content);
	g_minishell->bloq = 0;
}
