/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:33:23 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/01 23:47:13 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
* STDIN - standard input fd = 0 - keyboard
* STDOUT - standard output fd = 1 - terminal
* STDERR - error output fd = 2 - terminal
*/
void	ft_redir_errors(t_redir_type type, char *file)
{
	if ((type == REIN)
		&& (access(file, R_OK) == -1 || access(file, F_OK) == -1))
	{
		ft_error_fd(file);
		exit(1);
	}
	if ((type == REOUT) && access(file, W_OK) == -1)
	{
		ft_error_fd(file);
		exit(1);
	}
}

/*
* Funcion global que decide donde vamos en funcion del parse
* Token 1 para > append
* Token 2 para >> trunc
* Token 3 para <
*/
int	read_doublerein(char *delimiter)
{
	char	*readed;
	char	*delim;
	int		fd;

	fd = open("delimiter", O_CREAT | O_RDWR | O_TRUNC, 0666);
	delim = ft_strjoin(delimiter, "\n");
	readed = ft_strcpy("");
	while (!ft_strcmp(readed, delim, true))
	{
		free(readed);
		readed = get_next_line(1);
		printf("fd1 is %d\n", fd);
		ft_putstr_fd(readed, fd);
	}
	// close (fd);
	// fd = open(".redirs.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
	free(readed);
	free(delim);
	return (fd);
}

t_fd_redirs	ft_get_redir(t_pipe command)
{
	int			i;
	t_fd_redirs	fds;

	i = 0;
	fds.input = 0;
	fds.output = 0;
	if (command.redirs.quantity == 0)
		return (fds);
	while (i < command.redirs.quantity)
	{
		if (command.redirs.info[i].types == REIN)
			fds.input = open(command.redirs.info[i].files, O_RDONLY);
		else if (command.redirs.info[i].types == REOUT)
			fds.output = open(command.redirs.info[i].files,
					O_CREAT | O_RDWR | O_TRUNC, 0666);
		else if (command.redirs.info[i].types == DOUBBLE_REOUT)
			fds.output = open(command.redirs.info[i].files,
					O_CREAT | O_RDWR | O_APPEND, 0666);
		else
			fds.input = read_doublerein(command.redirs.info[i].files);
		ft_redir_errors(command.redirs.info[i].types,
			command.redirs.info[i].files);
		i++;
	}
	return (fds);
}
