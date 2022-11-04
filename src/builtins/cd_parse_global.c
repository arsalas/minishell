/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_parse_global.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:06:46 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/04 18:03:29 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_is_absolute(char *words)
{
	char	*aux;

	aux = getcwd(NULL, 0);
	if (words[0] == '/' && words[1] != '\0')
	{
		update_env_var("OLDPWD", get_env_var("PWD"));
		chdir(words);
		update_env_var("PWD", aux);
		free(aux);
		return (true);
	}
	free(aux);
	return (false);
}

/**
 * @brief Input es aquello que hay entre pipes en el momento 
 * en que me dan CD como comando
 * Words es el input separado por espacio, \t o \n
 * Parseamos para comprobar si lo que nos pasan es ir a home
 * 
 * @param input 
 */
void	ft_parse_cd(char *input)
{
	g_minishell->status = DEFAULT;
	if (ft_look_for_home(input))
		return ;
	if (ft_look_for_root(input))
		return ;
	if (ft_is_absolute(input))
		return ;
	if (ft_get_home_dir(input))
		return ;
	if (ft_look_for_old(input))
		return ;
	if (ft_set_directory(input))
		return ;
}
