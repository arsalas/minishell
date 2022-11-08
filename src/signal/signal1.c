/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:58:09 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/08 20:07:53 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Control + D
 * 
 * Exit
 */
static void	ft_handle_d(int signal)
{
	(void) signal;
	g_minishell->status = 0;
	printf("Exit\n");
	exit (0);
}

/**
 * @brief Control + \
 * Si estamos en comando bloqueante, salimos y escribe Quit
 * 
 */
static void	ft_handle_slash(int signal)
{
	if (signal == SIGQUIT && g_minishell->bloq)
	{
		ft_putstr_fd("^\\Quit: 3\n", 1);
		rl_on_new_line();
		g_minishell->status = 131;
	}
	else if (signal == SIGQUIT && !g_minishell->bloq)
	{
		printf("%s", get_prompt());
		g_minishell->status = 0;
	}
}

/**
 * @brief Control + C
 * 0 para comando no bloqueante - Termina el proceso
 * 1 para comando bloqueante - Pone ^C y termina el proceso
 * 2 para comando bloqueante dentro de redireccion - Pone ^C y termina el proceso
 *
 */
static void	ft_handle_c(int signal)
{
	(void) signal;
	if (g_minishell->bloq == 2 && g_minishell->finish)
	{
		ft_putstr_fd(">\n", 2);
		ft_exit(0);
	}
	else if (g_minishell->bloq == 1 && !g_minishell->finish)
	{
		ft_putstr_fd("^C\n", 2);
		rl_on_new_line();
		g_minishell->status = CNT_C;
	}
	else if (g_minishell->bloq == 0 && !g_minishell->finish)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		g_minishell->status = GENERAL;
	}
}

/**
 * @brief Enviamos una señal
 * Tenemos que utilizar la variable global, 
 * y status va a ser el resultado del ultimo pipe
 * 
 * @return int 
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
