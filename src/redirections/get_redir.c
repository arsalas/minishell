/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:33:23 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/30 19:19:59 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
* STDIN - standard input fd = 0 - keyboard
* STDOUT - standard output fd = 1 - terminal
* STDERR - error output fd = 2 - terminal
*/

// OUTPUT ES PARA ESCRIBIR
// INPUT ES PARA LEER
// SE QUE ESTO LO QUIERES EN ERRORS.C, PERO PRIMERO VERIFICAR QUE ESTE BIEN
void	ft_redir_errors(t_redir_type type, char *file)
{
	// Que tenga permiso de lectura
	if ((type == REIN || type == DOUBBLE_REIN)
		&& (access(file, R_OK) == -1 || access(file, F_OK) == -1))
	{
		//TODO error
		exit(1);
	}
	// Que tenga permiso de escritura
	if ((type == REOUT || type == DOUBBLE_REOUT)
		&& access(file, W_OK) == -1)
	{
		exit(1);
	}
}

/*
* Funcion global que decide donde vamos en funcion del parse
* Token 1 para > append
* Token 2 para >> trunc
* Token 3 para <
*/

//TODO -> crear funcion que retorne el fds y gestione errores
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
		else if (command.redirs.info[i].types == DOUBBLE_REIN)
			fds.input = open(command.redirs.info[i].files, O_RDONLY);
		else if (command.redirs.info[i].types == REOUT)
			fds.output = open(command.redirs.info[i].files, O_CREAT | O_RDWR | O_TRUNC, 0666);
		else
			fds.output = open(command.redirs.info[i].files, O_CREAT | O_RDWR | O_APPEND, 0666);
		ft_redir_errors(command.redirs.info[i].types, command.redirs.info[i].files);
		i++;
	}
	return (fds);
}
