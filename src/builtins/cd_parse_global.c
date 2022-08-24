/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_parse_global.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:06:46 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/23 20:21:29 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_is_absolute(char **words)
{
	if (words[1][0] == '/' && words[1][1] != '\0')
	{
		update_env_var("OLDPWD", get_env_var("PWD"));
		chdir(words[1]);
		update_env_var("PWD", getcwd(NULL, 0));
		return (true);
	}
	return (false);
}

/*
* Input es aquello que hay entre pipes en el momento en que me dan CD como comando
* Words es el input separado por espacio, \t o \n
* Parseamos para comprobar si lo que nos pasan es ir a home
*/
void	ft_parse_cd(char *input)
{
	char	**words;
	char	**given_path;
	int		count;

	count = 0;
	words = ft_split_words(input);
	if (ft_look_for_home(words))
		return ;
	if (ft_look_for_root(words))
		return ;
	if (ft_is_absolute(words))
		return ;
	given_path = ft_split(words[1], '/');
	while (given_path[count] != NULL)
	{
		if (ft_get_home_dir(given_path[count]))
			count++;
		else if (ft_look_for_old(given_path[count]))
			count++;
		else
		{
			ft_set_directory(given_path[count]);
			count++;
		}
	}
}
