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

/**
 * @brief Ejecuta los procesos de un unico pipe
 * 
 */
void	execute_single_pipe(t_pipe *commands)
{
	int	fd[2];
	int	*pid;
	int	i;

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


void	execute_command_fork(t_process process)
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
	// int			i;
    int			saved_stdout;
    int			saved_stdin;

	// i = 0;
	// g_minishell->bloq = 1;
	fds.input = -1;
	fds.output = -1;
	// get_input_parsed(&process.content[0]);
	// if (process.content[0].redirs.quantity > 0)
	// {
	// 	while (i < process.content[0].redirs.quantity)
	// 	{
	// 		if (process.content[0].redirs.info[i].types == DOUBBLE_REIN)
	// 			g_minishell->bloq = 2;
	// 		i++;
	// 	}
	// }
	get_pipes_redir(&process.content[0]);
	if (process.content->command != C_CD && process.content->command != C_EXIT
		&& process.content->command != C_EXPORT
		&& process.content->command != C_UNSET)
		execute_command_fork(process);
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

bool	is_correct_input(t_process process)
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
		if (!is_correct_input(process))
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
