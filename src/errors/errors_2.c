/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:07:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/04 20:07:49 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
