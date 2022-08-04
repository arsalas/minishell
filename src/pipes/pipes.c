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

void first_pipe_child(int *fd)
{
    close(fd[READ_END]);
    dup2(fd[WRITE_END], STDOUT_FILENO);
    close(fd[WRITE_END]);
}

void intermediate_pipe_child(int *fd1, int *fd2)
{
    close(fd2[READ_END]);
    dup2(fd1[READ_END], STDIN_FILENO);
    close(fd1[READ_END]);
    dup2(fd2[WRITE_END], STDOUT_FILENO);
    close(fd2[WRITE_END]);
}

void last_pipe_child(int *fd)
{
    dup2(fd[READ_END], STDIN_FILENO);
    close(fd[READ_END]);
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

// TODO --> cerrar ultimo fd al terminar
// TODO --> wait por cada proceso

void create_pipe(t_builtins cmd, bool is_last)
{
    pid_t pid;
    int fd[2];
    int status;

    (void)cmd;
    (void)is_last;
    pipe(fd);
    pid = create_process();
    if (pid == 0)
    {
        dup2(fd[READ_END], STDIN_FILENO);
        // Cerramos el fd de lectura del segundo pipe
        close(fd[READ_END]);
        execlp("/bin/ls", "ls", "-l", NULL);
        exit(0);
    }
    close(fd[READ_END]);
    // execlp("/usr/bin/wc", "wc", "-l", NULL);
    waitpid(pid, &status, 0);
}
