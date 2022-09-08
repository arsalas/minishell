/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:41:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/09/08 20:07:23 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	have_env_var(char *str)
{
	printf("1\n");
	if(str[0] == '$')
		return (true);
	return (false);
}	

char	*expand_env_vars(char *str)
{
	char	**split;
	char	*aux;
	int		i;
	
	printf("1\n");
	split = ft_split_words(str);
	i = 0;
	while (split[i])
	{
		if (have_env_var(split[i]))
		{
			aux = get_env_var(&split[i][1]);
			free(split[i]);
			split[i] = ft_strcpy(aux);
		}
		i++;
	}
	return (ft_join(split, ' '));
}