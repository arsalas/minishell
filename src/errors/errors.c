/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:17:36 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/03 14:24:42 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Cierra el minishell y libera toda la memoria reservada
 */
//VALIDATE
void	close_minishell(int code)
{
	free_memory();
	exit(code);
}

/**
 * @brief Gestion de error al reservar memoria
 */
void	memory_error(void)
{
	perror("Cannot allocate memory\n");
	close_minishell(12);
}

/**
 * @brief Printa por pantalla comando no encontrado
 * 
 * @param cmd comando utilizado
 */
void	cmd_not_found(char *cmd)
{
	g_minishell->status = 127;
	printf("minishell: %s: command not found\n", cmd);
}

/**
 * @brief Gestion de error al crear un fork
 */
void	fork_error(void)
{
	perror("Error in process fork\n");
	g_minishell->status = GENERAL;
	close_minishell(g_minishell->status);
}

/**
 * @brief Printa por pantalla que no es un directorio
 * 
 * @param path sitio al que hemos intentado ir
 */
void	ft_not_directory(char *path)
{
	g_minishell->status = GENERAL;
	printf("cd: not a directory: %s\n", path);
}

/**
 * @brief Printa por pantalla que no tenemos permiso de acceso
 * 
 * @param path sitio al que hemos intentado ir
 */
void	ft_no_permission(char *path)
{
	g_minishell->status = GENERAL;
	printf("cd: permission denied: %s\n", path);
}

/**
 * @brief Printa por pantalla que no se ha encontrado el archivo o directorio
 * 
 * @param path sitio al que hemos intentado ir
 */
void	ft_no_file_dir(char *path)
{
	g_minishell->status = GENERAL;
	printf("cd: no such file or directory: %s\n", path);
}

void	ft_error_fd(char *file)
{
	g_minishell->status = GENERAL;
	printf("%s: Permission denied\n", file);
}
