/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:33:23 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/27 18:19:08 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
* STDIN - standard input fd = 0 - keyboard
* STDOUT - standard output fd = 1 - terminal
* STDERR - error output fd = 2 - terminal
*/

// /*
// * Le damos un valor a fd y miramos si es -1
// */
// int	ft_fd(void)
// {
// 	int	fd;

// 	if (g_minishell->command.redirs.info[count].types == REOUT)
// 		fd = open(g_minishell->command->redirs.info[count].files, O_CREAT | O_RDWR | O_APPEND, 0666);
// 	if (g_minishell->command.redirs.info[count].types == DOUBBLE_REOUT)
// 		fd = open(g_minishell->command->redirs.info[count].files, O_CREAT | O_RDWR | O_TRUNC, 0666);
// 	if (g_minishell->command.redirs.info[count].types == REIN)
// 		fd = open(g_minishell->command->redirs.info[count].files, O_RDONLY);
// 	if (ft_error_fd(fd))
// 		fd = -1;
// 	return (fd);
// }

// // SE QUE ESTO LO QUIERES EN ERRORS.C, PERO PRIMERO VERIFICAR QUE ESTE BIEN
// int ft_redir_errors(int count)
// {
// 	if (!g_minishell->command->redirs.info[count].files || !g_minishell->tokens.content)
// 	{
// 		ft_putstr_fd("Error 1\n", 2);
// 		return (-1);
// 	}
// 	if (g_minishell->command.redirs.info[count].types == REIN && access(g_minishell->command->redirs.info[count].files, R_OK) == -1)
// 	{
// 		ft_putstr_fd("Error 2\n", 2);
// 		return (-1);
// 	}
// 	if ((g_minishell->command.redirs.info[count].types == REOUT || g_minishell->command.redirs.info[count].types == DOUBBLE_REOUT)
// 		&& access(g_minishell->command->redirs.info[count].files, W_OK) == -1 && access(g_minishell->command->redirs.info[count].files, F_OK) == 0)
// 	{
// 		ft_putstr_fd("Error 3\n", 2);
// 		return (-1);
// 	}
// 	return (0);
// }

// /*
// * g_minishell->tokens.content Va a tener el contenido de lo que tendra el nuevo fichero
// * APPEND es > 
// * Crea el file y escribe en output
// */
// int ft_append(int fd)
// {
// 	g_minishell->status = 2;
// 	ft_putstr_fd(g_minishell->tokens.content, fd);
// 	close (fd);
// 	return (fd);
// }

// /*
// * TRUNC es >>
// * Escribe al final del file en vez de sobreescribir
// */
// int ft_trunc(int fd)
// {
// 	if (!g_minishell->command->redirs.info[count].files)
// 	{
// 		ft_no_file_dir(g_minishell->command->redirs.info[count].files);
// 		return (-1);
// 	}
// 	if (ft_error_fd(fd))
// 		return (-1);
// 	g_minishell->status = 2;
// 	ft_putstr_fd(g_minishell->tokens.content, fd);
// 	close (fd);
// 	return (fd);
// }

// /*
// * < Lee de dentro, similar a 'cat'
// */
// int	ft_redir_in(int fd, int count)
// {
// 	if (!g_minishell->command->redirs.info[count].files)
// 	{
// 		ft_no_file_dir(g_minishell->command->redirs.info[count].files);
// 		return (-1);
// 	}
// 	g_minishell->status = 2;
// 	return (fd);
// }

// /*
// * Funcion global que decide donde vamos en funcion del parse
// * REOUT para > append
// * DOUBBLE_REOUT para >> trunc
// * REIN para <
// */
// void    ft_get_redir(char *input, int count)
// {
// 	int fd;
// 	//num = g_minishell->command.redirs.quantity;
// 	//fichero = g_minishell->command->redirs.info[count].files
// 	//contenido = 
// 	(void) input;
// 	if (ft_redir_errors(count) == -1)
// 		return;
// 	fd = ft_fd();
// 	if (fd == -1)
// 		return ;
// 	if (g_minishell->command.redirs.info[count].types == REOUT)
// 		ft_append(fd, count);
// 	if (g_minishell->command.redirs.info[count].types == DOUBBLE_REOUT)
// 		ft_trunc(fd, count);
// 	if (g_minishell->command.redirs.info[count].types == REIN)
// 		ft_redir_in(fd, count);
// }

// // HOLA ALBERTO (: Me falta que se escriba dentro del fichero

/*
* Le damos un valor a fd y miramos si es -1
*/
int ft_fd(void)
{
	int fd;

	if (g_minishell->tokens.token == 1)
		fd = open(g_minishell->tokens.path, O_CREAT | O_RDWR | O_APPEND, 0666);
	if (g_minishell->tokens.token == 2)
		fd = open(g_minishell->tokens.path, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (g_minishell->tokens.token == 3)
		fd = open(g_minishell->tokens.path, O_RDONLY);
	if (ft_error_fd(fd))
		fd = -1;
	return (fd);
}

// SE QUE ESTO LO QUIERES EN ERRORS.C, PERO PRIMERO VERIFICAR QUE ESTE BIEN
int ft_redir_errors(void)
{
	if (!g_minishell->tokens.path || !g_minishell->tokens.content)
	{
		ft_putstr_fd("Error 1\n", 2);
		return (-1);
	}
	if (g_minishell->tokens.token == 3 && access(g_minishell->tokens.path, R_OK) == -1)
	{
		ft_putstr_fd("Error 2\n", 2);
		g_minishell->status = 1;
		return (-1);
	}
	if ((g_minishell->tokens.token == 1 || g_minishell->tokens.token == 2)
		&& access(g_minishell->tokens.path, W_OK) == -1 && access(g_minishell->tokens.path, F_OK) == 0)
	{
		ft_putstr_fd("Error 3\n", 2);
		g_minishell->status = 1;
		return (-1);
	}
	return (0);
}

/*
* g_minishell->tokens.content Va a tener el contenido de lo que tendra el nuevo fichero
* APPEND es > 
* Crea el file y escribe en output
*/
int ft_append(int fd)
{
	g_minishell->status = 2;
	ft_putstr_fd(g_minishell->tokens.content, fd);
	close (fd);
	return (fd);
}

/*
* TRUNC es >>
* Escribe al final del file en vez de sobreescribir
*/
int ft_trunc(int fd)
{
	if (!g_minishell->tokens.path)
	{
		ft_no_file_dir(g_minishell->tokens.path);
		return (-1);
	}
	if (ft_error_fd(fd))
	{
		g_minishell->status = 1;
		return (-1);
	}
	g_minishell->status = 2;
	ft_putstr_fd(g_minishell->tokens.content, fd);
	close (fd);
	return (fd);
}

/*
* < Lee de dentro, similar a 'cat'
*/
int ft_redir_in(int fd)
{
	if (!g_minishell->tokens.path)
	{
		ft_no_file_dir(g_minishell->tokens.path);
		return (-1);
	}
	g_minishell->status = 2;
	return (fd);
}

/*
* Funcion global que decide donde vamos en funcion del parse
* Token 1 para > append
* Token 2 para >> trunc
* Token 3 para <
*/
void    ft_get_redir(char *input)
{
	int fd;

	(void) input;
	g_minishell->tokens.content = "hola";
	// char *fichero = redirs.info[count].files
	g_minishell->tokens.path = "/System/Volumes/Data/sgoinfre/Perso/amurcia-/minishell/prueba.txt";
	if (ft_redir_errors() == -1)
		return;
	fd = ft_fd();
	if (fd == -1)
		return ;
	if (g_minishell->tokens.token == 1)
		ft_append(fd);
	if (g_minishell->tokens.token == 2)
		ft_trunc(fd);
	if (g_minishell->tokens.token == 3)
		ft_redir_in(fd);
}