/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:24:05 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/09 13:27:08 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void first_pipe_child(int *fd)
{
	close(fd[READ_END]);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	execlp("/bin/ls", "ls", "-l", NULL);
	exit(0);
}

void intermediate_pipe_child(int *fd1, int *fd2)
{
	close(fd2[READ_END]);
	dup2(fd1[READ_END], STDIN_FILENO);
	close(fd1[READ_END]);
	dup2(fd2[WRITE_END], STDOUT_FILENO);
	close(fd2[WRITE_END]);
	execlp("/bin/grep", "grep", "s", NULL);
	exit(0);
}

void last_pipe_child(int *fd)
{
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	execlp("/usr/bin/wc", "wc", "-l", NULL);
	exit(0);
}

int first_pipe_father(int *fd)
{
	pipe(fd);
	return (create_process());
}

int intermediate_pipe_father(int *fd1, int *fd2)
{
	close(fd1[WRITE_END]);
	pipe(fd2);
	return (create_process());
}

int last_pipe_father(int *fd1, int *fd2)
{
	close(fd1[READ_END]);
	close(fd2[WRITE_END]);
	return (create_process());
}

int **create_fd(int pipes)
{
	int i;
	int **fd;

	i = 0;
	fd = get_memory(sizeof(int *) * pipes);
	while (i < pipes)
	{
		fd[i] = get_memory(sizeof(int) * 2);
		i++;
	}
	return (fd);
}

int	*create_pid(int process)
{
	return (get_memory(sizeof(int) * process));
}

void	create_pipe(int process)
{
	int	status;
	int	**fd;
	int	*pid;
	int	i;

	i = 1;
	fd = create_fd(process - 1);
	pid = create_pid(process);
	pid[0] = first_pipe_father(fd[0]);
	if (pid[0] == 0)
		first_pipe_child(fd[0]);
	else
	{
		pid[1] = intermediate_pipe_father(fd[0], fd[1]);
		if (pid[1] == 0)
			intermediate_pipe_child(fd[0], fd[1]);
		else
		{
			pid[2] = last_pipe_father(fd[0], fd[1]);
			if (pid[2] == 0)
				last_pipe_child(fd[1]);
		}

	}
	close(fd[1][READ_END]);
	i = 0;
	while (i < process)
	{
		wait(&status);
		i++;
	}
}

// TODO --> Borrar
void create_pipe2(t_builtins cmd, bool is_last)
{
	int	status;
	int	fd1[2];
	int	fd2[2];
	int	pid1, pid2, pid3;

	(void)cmd;
	(void)is_last;
	pid1 = first_pipe_father(fd1);
	if (pid1 == 0)
		first_pipe_child(fd1);
	else
	{
		pid2 = intermediate_pipe_father(fd1, fd2);
		if (pid2 == 0)
			intermediate_pipe_child(fd1, fd2);
		else
		{
			pid3 = last_pipe_father(fd1, fd2);
			if (pid3 == 0)
				last_pipe_child(fd2);
		}
	}
	close(fd2[READ_END]);
	wait(&status);
	wait(&status);
	wait(&status);
}
