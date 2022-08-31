/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:58:09 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/31 21:10:35 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//FALTA modificar el PID
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
* Control + slash
*/
static void	ft_handle_slash(int signal)
{
	if (signal == SIGQUIT && g_minishell->bloq)
	{
		ft_putstr_fd("^\\Quit: 3\n", 1);
		rl_on_new_line();
		g_minishell->status = 130;
	}
	else if (signal == SIGQUIT && !g_minishell->bloq)
	{
		printf("%s", get_prompt());
		g_minishell->status = 0;
	}
}

/*
* Control + C
* TODO
* Tenemos que encontrar la manera de que si hay dos Control C seguidos no se vaya al comando bloqueante
*/
static void	ft_handle_c(int signal)
{
	if (signal == SIGINT && g_minishell->bloq)
	{
		ft_putstr_fd("^C\n", 2);
		rl_on_new_line();
		g_minishell->status = CNT_C;
	}
	else if (signal == SIGINT && !g_minishell->bloq)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		g_minishell->status = GENERAL;
	}
}

/*
* Enviamos una señal
*/
int	ft_get_signal(void)
{
	struct termios	term;

	if (tcgetattr(STDIN_FILENO, &term) == -1)
		return (1);
	term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
		return (1);
	if (signal(SIGINT, ft_handle_c) == SIG_ERR)
		return (1);
	if (signal(SIGQUIT, ft_handle_slash) == SIG_ERR)
		return (1);
	if (signal(SIGTERM, ft_handle_d) == SIG_ERR)
		return (1);
	return (0);
}
