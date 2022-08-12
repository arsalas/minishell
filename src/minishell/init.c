/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:30:13 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/12 11:15:54 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* Obtenemos el mensaje que pasamos por la shell
*/
char	*ft_get_input(void)
{
	print_prompt();
	return (readline(" "));
}

/*
* Para que no de segmentation fault cuando no se escriba nada en el input
* Te gusta mi recursividad?
*/
void	ft_is_empty(void)
{
	int	cont;

	cont = 0;
	while (g_minishell->input[cont] == '\0' || g_minishell->input[cont] == ' '
		|| g_minishell->input[cont] == '\n' || g_minishell->input[0] == '\t')
	{
		ft_read();
		cont++;
	}
}

/*
* Leemos en bucle
*/
void	ft_read(void)
{
	while (1)
	{
		g_minishell->input = ft_get_input();
		ft_is_empty();
		ft_read_history();
		ft_number_pipes();
		if (g_minishell->parse.pipe == 0)
			ft_odd_quotes(g_minishell->input);
		ft_search_command_in_pipe();
		ft_command_in_pipe();
	}
	ft_clear_history();
}

/*
* Esta estructura es necesaria para que funcione Control D
* porque es una senal falsa, necesita una estructura termios
*/
void	ft_init_controld(void)
{
	tcgetattr(STDIN_FILENO, &g_minishell->term);
	g_minishell->term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &g_minishell->term);
}

/*
* Cuando comenzamos el programa, status = 0
* Iniciamos las senales antes de leer
*/
void	ft_signal(void)
{
	g_minishell->status = 0;
	ft_get_signal();
}

/*
* Iniciamos g_minishell
* Iniciamos environment
*/
void	ft_init_minishell(char **env)
{
	g_minishell = get_memory(sizeof(t_minishell));
	init_env(env);
	update_env_var("OLDPWD", "minishell");
	update_env_var("PWD", "minishell");
	ft_signal();
	ft_read();
}
