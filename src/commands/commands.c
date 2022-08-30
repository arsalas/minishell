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
	g_minishell->last_command = builting.command;
	if (builting.command == C_ENV)
		return (ft_env());
	if (builting.command == C_EXIT)
		return (ft_exit(builting.input));
	if (builting.command == C_PWD)
		return (pwd());
	if (builting.command == C_EXPORT)
		return (ft_export(builting.input));
	if (builting.command == C_ECHO)
		return (ft_echo(builting.input));
	if (builting.command == C_CD)
		return (ft_cd(builting.input));
	return (ft_others(builting.input));
}


