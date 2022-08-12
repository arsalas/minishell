/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:58:09 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/12 11:41:51 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//FT_PROCESS va a ser en caso de que estemos en un comando bloqueante
//FALTA modificar el PID

/*
* En caso de estar en un comando bloqueante, como es el cat, status varia
*/
static void	ft_bloq(int signal)
{
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

/*
* Control + D
*/
static void	ft_handle_d(int signal)
{
	(void) signal;
	g_minishell->status = 0;
	printf("Exit\n");
	exit (0);
}

/*
* Control + \ 
*/
static void	ft_handle_slash(int signal)
{
	if (signal == SIGQUIT && g_minishell != 0)
		ft_bloq(signal);
	else if (signal == SIGQUIT)
	{
		ft_putstr_fd("\b\b  \b\b", 1);
		g_minishell->status = 0;
	}
}

/*
* Control + C
*/
static void	ft_handle_c(int signal)
{
	if (signal == SIGINT && g_minishell->status != 0)
		ft_bloq(signal);
	else if (signal == SIGINT)
	{
	//	ft_putchar_fd('\n', 1);
	//	printf(UMAG"\n %s@minishell %% "RESET, get_user());
		g_minishell->status = 1;
		print_prompt();
	//	rl_on_new_line();
	}
}

/*
* Enviamos una senal
*/
void	ft_get_signal(void)
{
	signal(SIGINT, &ft_handle_c);
	signal(SIGQUIT, &ft_handle_slash);
	signal(SIGTERM, &ft_handle_d);
}
