/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:29:35 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/20 17:47:04 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* El comando cd - nos lleva al directorio de trabajo anterior
*/

// char	*ft_old_cd(void)
// {
// 	char	*old_path;
// 	char	*new_path;
// 	new_path = get_env_var("OLDPWD");
// 	old_path = get_env_var("PWD");
// 	if (new_path == NULL)
// 	{
// 		printf("cd: OLDPWD not set\n");
// 		return (0);
// 	}
// 	chdir(new_path);
// 	update_env_var("OLDPWD", old_path);
// 	update_env_var("PWD", getcwd(NULL, 0));
// 	return (new_path);
// }

/*
* Comprobamos si nos dan un solo guion, porque implica que nos vamos al
* puesto de trabajo anterior (no es lo mismo que cd ..)
*/
//TODO --> no se si el ft_old se hace
bool	ft_look_for_old(char *words)
{
	if (!(words[0] == '-' && words[1] == '\0'))
		return (false);
	// ft_old_cd();
	return (true);
}

/*
* Vamos a HOME
*/
void	ft_go_home(void)
{
	update_env_var("OLDPWD", get_env_var("PWD"));
	update_env_var("PWD", get_env_var("HOME"));
	chdir(get_env_var("HOME"));
}

/*
* Comprobamos si vamos a HOME
*/
bool	ft_get_home_dir(char *words)
{
	if ((words[0] == '~' && words[1] == '\0')
		|| (words[0] == '~' && words[1] == '/' && words[2] == '\0')
		|| (words[0] == '-' && words[1] == '-' && words[2] == '\0'))
	{
		ft_go_home();
		return (true);
	}
	return (false);
}

bool	ft_look_for_root(char *words)
{
	if (words[0] == '/' && words[1] == '\0')
	{
		update_env_var("OLDPWD", get_env_var("PWD"));
		chdir("/");
		update_env_var("PWD", getcwd(NULL, 0));
		return (true);
	}
	return (false);
}

/*
* Nos dan solamente : cd
* Y nada mas, implica que nos vamos a home
*/
bool	ft_look_for_home(char *words)
{
	if (words == NULL)
	{
		ft_go_home();
		return (true);
	}
	return (false);
}