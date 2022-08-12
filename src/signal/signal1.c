/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:58:09 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/11 23:10:53 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//FT_PROCESS va a ser en caso de que estemos en un comando bloqueante
//FALTA modificar el PID

static void	ft_bloq(int signal)
{
// 	(void) signal;
// 	if (!kill(AQUI TENEMOS QUE PONER EL PID, DEL TIPO PID_T, signal))
// 	{
		if (signal == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_minishell->status = 131;
		}
		if (signal == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			g_minishell->status = 131;
		}
//	}
}

/*
* SIGINT para CONTROL C - termina el proceso
* SIGQUIT para CONTROL \ - ni idea
* SIGTERM para CONTROL D - salimos
* Tenemos que utilizar la variable global, y status va a ser el resultado del ultimo pipe
*/
static void	ft_handle_control_d(int signal)
{
	(void) signal;
	g_minishell->status = 0;
	printf("Exit\n");
	exit (0);
}

static void	ft_handle(int signal)
{
	if ((signal == SIGINT || signal == SIGQUIT) && g_minishell != 0)
		ft_bloq(signal);
	else
	{
		if (signal == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_minishell->status = 1;
			print_prompt();
		//	rl_on_new_line();

		}
		else if (signal == SIGQUIT)
		{
			ft_putstr_fd("\b\b  \b\b", 1);
			g_minishell->status = 0;
		}
	}
}

void	ft_get_signal(void)
{
	signal(SIGINT, &ft_handle);
	signal(SIGQUIT, &ft_handle);
	signal(SIGTERM, &ft_handle_control_d);
}
