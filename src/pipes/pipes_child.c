/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:41:31 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 19:07:42 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Ejecuta el comando del primer pipe
 *
 * @param fd
 */
void    first_pipe_child(int *fd, t_pipe command)
{
    (void)command;
    close(fd[READ_END]);
    dup2(fd[WRITE_END], STDOUT_FILENO);
    close(fd[WRITE_END]);
    ft_execute(command);
    exit(0);
}

/**
 * @brief Ejecuta el comando intermedia de un pipe
 *
 * @param fd1
 * @param fd2
 */
void    intermediate_pipe_child(int *fd1, int *fd2, t_pipe command)
{
    (void)command;
    close(fd2[READ_END]);
    dup2(fd1[READ_END], STDIN_FILENO);
    close(fd1[READ_END]);
    dup2(fd2[WRITE_END], STDOUT_FILENO);
    close(fd2[WRITE_END]);
    ft_execute(command);
    exit(0);
}

/**
 * @brief Ejecuta el ultimo comando de un pipe
 *
 * @param fd
 */
void    last_pipe_child(int *fd, t_pipe command)
{
    dup2(fd[READ_END], STDIN_FILENO);
    close(fd[READ_END]);
    ft_execute(command);
    // char *str[] = {"programa", "'$USER ", " Mundo", NULL};
    // char *env[] = {"USER=aramirez", "USER=aramirez", "Mundo=fds", NULL};
    // execve("/bin/echo", str,env);
    //    printf("%i\n", access("../a.out", X_OK));
    //     execve("../a.out", str,env);
    // ft_others("../test.txt", str);
    // execlp("/usr/bin/wc", "wc", "-l", NULL);
    exit(0);
}
