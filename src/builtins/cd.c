/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:31:29 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 22:01:36 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// PRIMERO vamos a mirar si despues de CD nos dan ~/
// En caso de que NO, vamos a coger el environment de HOME y lo vamos a poner desde
// la primera posicion hasta la longitud de lo que hay despues de CD
char	*ft_add_home_path(char *word)
{
	char	*path;
	char	*paths;

	if (!ft_strncmp(word, "~/", 2))
	{
		path = get_env_var("HOME");
		paths = ft_substr(path, 1, ft_strlen(word));
		free(word);
		word = ft_strjoin(path, paths);
		free (path);
		free (paths);
		return (word);
	}
	return (word);
}

/*
* El comando cd - nos lleva al directorio de trabajo anterior
*/
char	*ft_old_cd(void)
{
	// char	*old_path;
	char	*path;

	// old_path = get_env_var("OLDPWD");
	path = get_env_var("PWD");
	if (old_path == path)
	{
		printf("cd: OLDPWD not set\n");
		return (0);
	}
	ft_putstr_fd(path, 1);
	ft_putchar_fd('\n', 1);
	return (path);
}

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

/*
* No podemos acceder a este directorio, por diversos motivos
* 1 - No es un directorio
* 2 - Permiso denegado
* 3 - No existe el directorio
*/
void	ft_cant_go(char *path)
{
	(void) path;
	printf("De eso nada, aqui quieto\n");
}

//ANADIMOS EL DIRECTORIO
int	ft_set_directory(char *path)
{
	int	home;

	home = 0;
	if (ft_can_go(path))
		return (1);
	ft_cant_go(path);
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	g_minishell->status = 1;
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
* Input es aquello que hay entre pipes en el momento en que me dan CD como comando
* Words es el input separado por espacio, \t o \n
*/
void	ft_parse_cd(char *input)
{
	char	**words;
	// char	*path;

	words = ft_split_words(input);
	if (!words[1])
		return ;
	if (words[1][0] == '~' || (words[1][0] == '-' && words[1][1] == '-'))
	{
		ft_putstr_fd("minishell: cd: HOME\n", 1);
		return ;
	}
	if (words[1][0] == '-')
	{
		// path = ft_old_cd();
		return ;
	}
	words[1] = ft_add_home_path(words[1]);
	ft_set_directory(input);
	// printf("words is %s\n", words[1]);
}

/*
* Realizamos la funcion CD
*/
void	ft_cd(char *input)
{
	ft_parse_cd(input);
}
//SI NOS DAN ~ O -- HAY QUE BUSCAR HOME EN EL ENVIRONMENT
