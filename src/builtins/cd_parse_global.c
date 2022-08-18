/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_parse_global.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:06:46 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/17 19:43:48 by amurcia-         ###   ########.fr       */
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
	char	**paths;
	int		count;

	count = 0;
	words = ft_split_words(input);
    if (words[1] == NULL)
	{
        ft_go_home();
        return ;
	}
	paths = ft_split(words[1], '/');
	while (paths[count] != NULL)
	{
		ft_get_home_dir(paths[count]);
		ft_look_for_old(paths[count]);
		ft_look_for_root(paths[count]);
		ft_set_directory(paths[count]);
		count++;
	}
}


// TODO
// TENGO QUE HACER QUE ENTRE EN UNO Y NO EN LOS DEMAS
// PORQUE SINO TENDRE QUE ENTRAR EN EL ULTIMO Y PONDRA ~ EN LA RUTA
// PONER LOS DOS PUNTOS