/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:33:23 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/08 16:12:09 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Errores de lectura, escritura y existencia
* STDIN - standard input fd = 0 - keyboard
* STDOUT - standard output fd = 1 - terminal
* STDERR - error output fd = 2 - terminal
 * @param type 
 * @param file 
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
	int		fd;

	fd = open(REDIR_FILE, O_CREAT | O_RDWR | O_TRUNC, 0666);
	readed = ft_strcpy("");
	while (!ft_strcmp(readed, delimiter, true))
	{
		free(readed);
		readed = readline("> ");
		if (!ft_strcmp(readed, delimiter, true))
		{
			ft_putstr_fd(readed, fd);
			ft_putstr_fd("\n", fd);
		}
	}
	free(readed);
	close(fd);
	fd = open(REDIR_FILE, O_RDWR);
	return (fd);
}

void	create_files_redirs(t_pipe command, int i, t_fd_redirs *fds)
{
	if (command.redirs.info[i].types == REIN)
		fds->input = open(command.redirs.info[i].files, O_RDONLY);
	else if (command.redirs.info[i].types == REOUT)
		fds->output = open(command.redirs.info[i].files,
				O_CREAT | O_RDWR | O_TRUNC, 0666);
	else if (command.redirs.info[i].types == DOUBBLE_REOUT)
		fds->output = open(command.redirs.info[i].files,
				O_CREAT | O_RDWR | O_APPEND, 0666);
	else
	{
		g_minishell->bloq = 2;
		g_minishell->finish = true;
		fds->input = read_doublerein(command.redirs.info[i].files);
	}
	ft_redir_errors(command.redirs.info[i].types,
		command.redirs.info[i].files);
}

/**
 * @brief Obtenemos el fd input u output en función del tipo de redirección
 * 
 * @param command 
 * @return t_fd_redirs 
 */

t_fd_redirs	ft_get_redir(t_pipe command)
{
	int			i;
	t_fd_redirs	fds;

	i = 0;
	fds.input = -1;
	fds.output = -1;
	if (command.redirs.quantity == 0)
		return (fds);
	while (i < command.redirs.quantity)
	{
		create_files_redirs(command, i, &fds);
		i++;
	}
	return (fds);
}
