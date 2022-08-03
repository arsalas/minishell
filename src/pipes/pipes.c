/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:24:05 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/03 00:09:38 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void create_pipe(int *fd, t_builtins cmd)
{
    pid_t pidC;
    char buf[10];
    int num;

    (void)cmd;

    pipe(fd);      // TODO si devuelve -1 ha ido mal
    pidC = fork(); // pidC -1 error, 0 hijo
    switch (pidC)
    {
    case 0: // HIJO
        close(fd[0]);
        write(fd[1], "abcde", 5);
        close(fd[1]);
        exit(0);
        break;

    default: // PADRE
        close(fd[1]);
        num = read(fd[0], buf, sizeof(buf));
        printf("Padre lee %d bytes: %s\n", num, buf);
        close(fd[0]);
        break;
    }
}