/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:31:29 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/12 15:20:19 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Ejecuta el builtin env
 * 
 * @param env 
 */
void	ft_env(char **tokens)
{
	if (tokens[1])
	{
		printf("env: %s: No such file or directory\n", tokens[1]);
		g_minishell->status = CN_FOUND;
		return ;
	}
	print_env();
	ft_free_split(tokens);
}
