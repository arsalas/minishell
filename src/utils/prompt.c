/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/12 11:18:35 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// /**
//  * @brief Obtiene el nombre de usuario
//  * 
//  * @return user
//  */
// char	*get_user(void)
// {
// 		printf("TE USO 1\n");
// 	return (getenv("USER"));
// }

// char	*get_current_folder(void)
// {
// 	char	**paths;
// 	int		i;

// 	printf("TE USO 2\n");
// 	if (ft_strcmp(get_env_var("PWD"), "/", true))
// 		return ("/");
// 	paths = ft_split(get_env_var("PWD"), '/');
// 	i = 0;
// 	while (paths[i])
// 		i++;
// 	return (paths[i - 1]);
// }

/**
 * @brief Obtiene el prompt del minishell
 */
char	*get_prompt(void)
{
	return (BMAG"minishell: "RESET);
}
