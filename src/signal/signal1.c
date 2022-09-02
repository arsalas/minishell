/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:58:09 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/02 18:20:32 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* SIGINT para CONTROL C - termina el proceso
* SIGQUIT para CONTROL \ - nada. Si estamos en comando bloqueante, salimos y escribe Quit
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
* 0 para comando no bloqueante
* 1 para comando bloqueante
* 2 para comando bloqueante dentro de redireccion
*/
static void	ft_handle_c(int signal)
{
	(void) signal;
	if (g_minishell->bloq == 2)
	{
		ft_putstr_fd("1b\n", 2);
		ft_exit(0);
	}
	else if (g_minishell->bloq == 1)
	{
		ft_putstr_fd("2\n", 2);
		ft_putstr_fd("^C\n", 2);
		rl_on_new_line();
		g_minishell->status = CNT_C;
	}
	else if (g_minishell->bloq == 0)
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
		exit (1);
	term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
		exit (1);	
	if (signal(SIGINT, ft_handle_c) == SIG_ERR)
		exit (1);
	if (signal(SIGQUIT, ft_handle_slash) == SIG_ERR)
		exit (1);
	if (signal(SIGTERM, ft_handle_d) == SIG_ERR)
		exit (1);
	return (0);
}
