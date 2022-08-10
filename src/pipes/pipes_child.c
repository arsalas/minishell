/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:41:31 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/10 00:42:05 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Ejecuta el comando del primer pipe
 * 
 * @param fd 
 */
void first_pipe_child(int *fd)
{
    close(fd[READ_END]);
    dup2(fd[WRITE_END], STDOUT_FILENO);
    close(fd[WRITE_END]);
    execlp("/bin/ls", "ls", "-l", NULL);
    exit(0);
}

/**
 * @brief Ejecuta el comando intermedia de un pipe
 * 
 * @param fd1 
 * @param fd2 
 */
void intermediate_pipe_child(int *fd1, int *fd2)
{
    close(fd2[READ_END]);
    dup2(fd1[READ_END], STDIN_FILENO);
    close(fd1[READ_END]);
    dup2(fd2[WRITE_END], STDOUT_FILENO);
    close(fd2[WRITE_END]);
    // execlp("/bin/grep", "grep", "a", NULL);
    execlp("/usr/bin/wc", "wc", "-l", NULL);
    exit(0);
}

/**
 * @brief Ejecuta el ultimo comando de un pipe
 * 
 * @param fd 
 */
void last_pipe_child(int *fd)
{
    dup2(fd[READ_END], STDIN_FILENO);
    close(fd[READ_END]);
    execlp("/usr/bin/wc", "wc", "-l", NULL);
    exit(0);
}
