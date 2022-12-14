/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:26:10 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/03 14:23:32 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

void	close_minishell(int code);
void	memory_error(void);
void	cmd_not_found(char *cmd);
void	fork_error(void);
void	ft_no_file_dir(char *path);
void	ft_no_permission(char *path);
void	ft_not_directory(char *path);
void	ft_error_fd(char *file);

#endif