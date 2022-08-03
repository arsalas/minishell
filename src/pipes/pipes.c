/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:24:05 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/03 16:57:25 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipe(t_builtins cmd, bool is_last)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	(void)cmd;
	(void)is_last;
	pipe(fd);
	pid = create_process();
	if (pid == 0)
	{
		close(fd[READ_END]);
		// dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		execlp("/bin/ls", "ls", "-l", NULL);
		exit (0);
	}
	close(fd[WRITE_END]);
	// execlp("/usr/bin/wc", "wc", "-l", NULL);
	waitpid(pid, &status, 0);
}
