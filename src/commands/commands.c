/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:01:57 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/12 15:22:42 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute(t_pipe builting)
{
	if (builting.command == C_ENV)
		return (ft_env());
	//? que hace el string de exit
	if (builting.command == C_EXIT)
		return (ft_exit(""));
}
