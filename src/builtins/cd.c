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

// PRIMERO vamos a mirar si despues de CD nos dan ~/
// En caso de que NO, vamos a coger el environment de HOME y lo vamos a poner desde
// la primera posicion hasta la longitud de lo que hay despues de CD

// /*
// * Si nos dan "cd ~/" nos tenemos que ir a home"
// */
// char	*ft_add_home_path(char *word)
// {
// 	char	*path;
// 	char	*paths;

// 	if (!ft_strncmp(word, "~/", 2))
// 	{
// 		path = get_env_var("HOME");
// 		paths = ft_substr(path, 1, ft_strlen(word));
// 		free(word);
// 		word = ft_strjoin(path, paths);
// 		free (path);
// 		free (paths);
// 		return (word);
// 	}
// 	return (word);
// }


/*
* Si podemos ir a ese directorio, iremos
*/
int	ft_can_go(char *path)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!chdir(path))
	{
		if (pwd)
		{
			setenv("OLDPWD", pwd, 1);
			free(pwd);
		}
		if (pwd == getcwd(NULL, 0))
		{
			setenv("PWD", pwd, 1);
			free(pwd);
		}
		return (1);
	}
	chdir(path);
	update_env_var("PWD", path);
	free (pwd);
	return (0);
}

/*
* No podemos acceder a este directorio, por diversos motivos
* 1 - No es un directorio
* 2 - Permiso denegado
* 3 - No existe el directorio
*/
void	ft_cant_go(char *path)
{
	(void) path;
}

int	ft_change_pos(char *path)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!chdir(path))
	{
		if (pwd)
		{
	//		set_env("OLDPWD", pwd);
			free(pwd);
		}
		if (pwd == getcwd(NULL, 0))
		{
	//		set_env("PWD", pwd);
			free(pwd);
		}
		return (1);
	}
	free (pwd);
	return (0);
}

//ANADIMOS EL DIRECTORIO
int	ft_set_directory(char *path)
{
	if (ft_can_go(path))
		return (1);
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	g_minishell->status = 1;
	ft_cant_go(path);
	return (0);
}

/*
TODO
PARA PODER OBTENER OLDPWD DEBEMOS CREARLO
ASIGNAMOS PWDOLD EL VALOR DE PWD
Y CAMBIAMOS EL PWD

ANTES DE HACER EL CD GUARDAMOS EL PWD EN PWDOLD
set_env_element(int count, char *env)
posicion del array
*/

/*
* Realizamos la funcion CD
*/
void	ft_cd(char *input)
{
	ft_parse_cd(input);
}
