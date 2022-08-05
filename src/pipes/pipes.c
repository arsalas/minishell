/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:24:05 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/05 17:51:34 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void first_pipe_child(int *fd)
{
	close(fd[READ_END]);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	execlp("/bin/ls", "ls", "-l", NULL);
	// exit(0);
}

void intermediate_pipe_child(int *fd1, int *fd2)
{
	close(fd2[READ_END]);
	dup2(fd1[READ_END], STDIN_FILENO);
	close(fd1[READ_END]);
	dup2(fd2[WRITE_END], STDOUT_FILENO);
	close(fd2[WRITE_END]);
	execlp("/bin/grep", "grep", "s", NULL);
	// exit(0);
}

void last_pipe_child(int *fd)
{
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	execlp("/usr/bin/wc", "wc", "-l", NULL);
	// exit(0);
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

void create_pipe(t_builtins cmd, bool is_last)
{
	int status;
	int fd1[2];
	int fd2[2];
	int pid1, pid2, pid3;
	
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
