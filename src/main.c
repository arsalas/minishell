/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:24:05 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/02 18:09:19 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*g_minishell;

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	ft_init_minishell(envp);
	return (0);
}
