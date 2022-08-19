/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_parse_global.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:06:46 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/19 17:19:50 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
