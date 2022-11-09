/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:50:13 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/09 18:33:51 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_single_process_1(t_process process)
{
	int	i;

	i = 0;
	if (process.content[0].redirs.quantity > 0)
	{
		while (i < process.content[0].redirs.quantity)
		{
			if (process.content[0].redirs.info[i].types == DOUBBLE_REIN)
				g_minishell->bloq = 2;
			i++;
		}
	}
}

void	execute_single_process_2(t_process process)
{
	pid_t		pid;
	int			status;
	t_fd_redirs	fds;

	g_minishell->bloq = 1;
	fds.input = -1;
	fds.output = -1;
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
}

void	execute_single_process_3(t_process process)
{
	t_fd_redirs	fds;
	int			saved_stdout;
	int			saved_stdin;

	g_minishell->bloq = 1;
	fds.input = -1;
	fds.output = -1;
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

void	execute_single_process(t_process process)
{
	t_fd_redirs	fds;

	g_minishell->bloq = 1;
	fds.input = -1;
	fds.output = -1;
	get_input_parsed(&process.content[0]);
	execute_single_process_1(process);
	if (process.content->command != C_CD && process.content->command != C_EXIT
		&& process.content->command != C_EXPORT
		&& process.content->command != C_UNSET)
	{
		execute_single_process_2(process);
		return ;
	}
	execute_single_process_3(process);
}
