/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:29:35 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/15 11:59:19 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* El comando cd - nos lleva al directorio de trabajo anterior
*/
char	*ft_old_cd(void)
{
	char	*old_path;
	char	*path;

	old_path = get_env_var("OLDPWD");
	if (old_path == NULL)
	{
		printf("cd: OLDPWD not set\n");
		return (0);
	}
	path = get_env_var("PWD");
	ft_putstr_fd(path, 1);
	ft_putchar_fd('\n', 1);
	return (path);
}

/*
* Comprobamos si nos dan un solo guion, porque implica que nos vamos al
* puesto de trabajo anterior (no es lo mismo que cd ..)
*/
int	ft_look_for_old(char **words)
{
	char	*path;

	if (words[1][0] == '-' && words[1][1] == '\0')
	{
		path = ft_old_cd();
		return (1);
	}
	return (0);
}

/*
* Vamos a HOME
*/
void	ft_go_home(void)
{
    update_env_var("OLDPWD", getenv("PWD"));
    update_env_var("PWD", getenv("HOME"));
    chdir(getenv("HOME"));
}

/*
* Comprobamos si vamos a HOME
*/
int ft_get_home_dir(char *words)
{
    if ((words[0] == '~' && words[1] == '\0')
        || (words[0] == '~' && words[1] == '/' && words[2] == '\0')
        || (words[0] == '-' && words[1] == '-' && words[2] == '\0'))
	{
        ft_go_home();
        return (1);
    }
    return (0);
}

/*
* Input es aquello que hay entre pipes en el momento en que me dan CD como comando
* Words es el input separado por espacio, \t o \n
* Parseamos para comprobar si lo que nos pasan es ir a home
*/
void	ft_parse_cd(char *input)
{
	char	**words;

	words = ft_split_words(input);
    if (words[1] == NULL)
     {
        ft_go_home();
        return ;
    }
	if (ft_get_home_dir(words[1]) == 1)
		return ;
	if (ft_look_for_old(words) == 1)
		return ;
	ft_set_directory(input);
}