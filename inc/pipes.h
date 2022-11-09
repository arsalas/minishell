/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:44:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/10 13:29:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# include "minishell.h"

int		first_pipe_father(int *fd);
int		intermediate_pipe_father(int *fd1, int *fd2);
int		last_pipe_father(int *fd1, int *fd2);
int		*create_pid(int process);
int		**create_fd(int pipes);
void	first_pipe_child(int *fd, t_pipe command);
void	intermediate_pipe_child(int *fd1, int *fd2, t_pipe command);
void	last_pipe_child(int *fd, t_pipe command);
void	execute_pipe(t_process process);
void	execute_single_pipe(t_pipe *commands);
void	execute_single_pipe_1(t_pipe *commands);
void	execute_multiple_pipe(int process, t_pipe *commands);
void	execute_multiple_pipe_1(t_pipe *commands);
bool	execute_pipe2(t_process process);
void	execute_pipe(t_process process);
void	execute_single_process_1(t_process process);
void	execute_single_process_2(t_process process);
void	execute_single_process_3(t_process process);
void	execute_single_process(t_process process);

#endif