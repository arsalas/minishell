/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:58:09 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/05 21:21:25 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* SIGINT para CONTROL C - termina el proceso
* SIGQUIT para CONTROL \ - ni idea
* SIGTERM para CONTROL D - salimos
* Tenemos que utilizar la variable global, y status va a ser el resultado del ultimo pipe
*/
static void	ft_handle(int signal)
{
	if (signal == SIGINT)
	{
		g_minishell->status = 1;
		rl_on_new_line();
		return ;
	}
	if (signal == SIGQUIT)
	{
		g_minishell->status = 0;
		return ;
	}
	if (signal == SIGTERM)
	{
		g_minishell->status = 0;
		printf("exit\n");
		close_minishell();
	}
}

/*
* SOLAMENTE si estamos en un comando bloqueante
* g_status = 130 == Cntrol C
*
*/
/*
static void	ft_handle_bloq(int signal)
{
	if (signal == SIGINT)
	{
		g_minishell->status = 130;
	//	rl_replace_line("", 0);
		rl_on_new_line();
		return ;
	}
	if (signal == SIGQUIT)
	{
		g_minishell->status = 0;
		return ;
	}
	if (signal == SIGTERM)
	{
		g_minishell->status = 0;
	//	rl_replace_line("", 0);
		rl_on_new_line();
		return ;
	}
}*/

void	ft_get_signal(t_minishell *minishell)
{
	(void) minishell;
	signal(SIGINT, &ft_handle);
	signal(SIGQUIT, &ft_handle);
	signal(SIGTERM, &ft_handle);
}
