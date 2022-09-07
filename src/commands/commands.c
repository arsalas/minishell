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
	char	**tokens;

	tokens = get_tokens2(builting.input);
	g_minishell->last_command = builting.command;
	if (builting.command == C_ENV)
		return (ft_env(tokens));
	if (builting.command == C_EXIT)
		return (ft_exit(tokens));
	if (builting.command == C_PWD)
		return (pwd());
	if (builting.command == C_EXPORT)
		return (ft_export(tokens));
	if (builting.command == C_UNSET)
		return (ft_unset(tokens));
	if (builting.command == C_ECHO)
		return (ft_echo(tokens));
	if (builting.command == C_CD)
		return (ft_cd(tokens[1]));
	return (ft_others(tokens));
}
