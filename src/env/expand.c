/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:41:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/09/12 12:23:12 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief 
 * 
 * @param str 
 * @return true 
 */
//VALIDATE
// static bool	have_env_var(char *str)
// {
// 	if (str[0] == '$')
// 		return (true);
// 	return (false);
// }	

// YA NO LA USAMOS
// char	*expand_env_vars(char *str)
// {
// 	char	**split;
// 	char	*aux;
// 	int		i;

// 	split = ft_split_words(str);
// 	i = 0;
// 	while (split[i])
// 	{
// 		if (have_env_var(split[i]))
// 		{
// 			aux = get_env_var(&split[i][1]);
// 			free(split[i]);
// 			split[i] = ft_strcpy(aux);
// 		}
// 		i++;
// 	}
// 	return (ft_join(split, ' '));
// }