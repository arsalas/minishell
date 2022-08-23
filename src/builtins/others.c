/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:34:47 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/12 15:24:34 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Comprueba si el string es un path valido
 * 
 * @param str path
 * @return true 
 * @return false 
 */
bool	is_path(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (true);
		i++;
	}
	return (false);
}

/**
 * @brief Ejecuta un programa
 * 
 * @param path 
 * @param argv 
 */
void	ft_others(char *path, char**argv)
{
	pid_t	pid;
	int		status;

	if (access(path, X_OK) == -1)
	{
		if (is_path(path))
			printf("%s: No such file or directory\n", path);
		else
			printf("%s: command not found\n", path);
		return ;
	}
	// TODO --> generar la array de str del env
	pid = fork();
	if (pid == 0)
	{
		execve(path, argv, argv);
		exit(1);
	}
	waitpid(pid, &status, 0);
}
