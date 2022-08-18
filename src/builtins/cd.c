/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:31:29 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/15 11:30:38 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* Si podemos ir a ese directorio, iremos
*/
void	ft_can_go(char *path)
{
	char	*pwd;
	char	*long_path;

	long_path = ft_strjoin((get_env_var("PWD")), "/");
	if (is_path(long_path))
	{
		update_env_var("OLDPWD", get_env_var("PWD"));
		pwd = getcwd(NULL, 0);
		chdir(path);
		update_env_var("PWD", (ft_strjoin(long_path, path)));
		free (pwd);
	}
}

/*
* No podemos acceder a este directorio, por diversos motivos
* 1 - No es un directorio
* 2 - No existe el directorio
* 3 - Permiso denegado
*/
int	ft_cant_go(char *path)
{
//	struct stat	st;
	char		*long_path;

	long_path = ft_strjoin((get_env_var("PWD")), "/");
	long_path = ft_strjoin(long_path, path);
	if (chdir(path) != 0)
	{
		printf("cd: no such file or directory: %s\n", long_path);
		return (1);
	}
	if (access(long_path, X_OK) == -1)
	{
		if (is_path(long_path))
		{
			printf("cd: not a directory: %s\n", long_path);
			return (2);
		}
	}
	//CREO QUE ESTO DE AQUI ABAJO DEBERIA ESTAR NEGADO
//	if (!(st.st_mode & S_IXUSR))
	if (access(long_path, R_OK) == -1)
	{
		printf("cd: permission denied: %s\n", path);
		return (3);
	}
	return (0);
}

/*
* Mandamos a una funcion u otra segun pueda o no ir
*/
int	ft_set_directory(char *words)
{
	char	*path;

	path = words;
	if (ft_cant_go(path) != 0)
	{
		g_minishell->status = 1;
		return (0);
	}
	ft_can_go(path);
	return (0);
}

/*
* Realizamos la funcion CD
*/
void	ft_cd(char *input)
{
	ft_parse_cd(input);
}
