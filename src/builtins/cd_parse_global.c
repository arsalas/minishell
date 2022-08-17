/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_parse_global.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:06:46 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/17 19:07:03 by amurcia-         ###   ########.fr       */
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
	if (ft_look_for_root(words) == 1)
		return ;
	ft_set_directory(words);
}
