/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:30:13 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/13 19:43:19 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Obtenemos el mensaje que pasamos por la shell
 * 
 */
char	*ft_get_input(void)
{
	char	*prompt;

	prompt = get_prompt();
	return (readline(prompt));
}

/**
 * @brief Al comenzar el programa el status es 0
 * Iniciamos las señales antes de leer
 */
void	ft_signal(void)
{
	g_minishell->status = 0;
	ft_get_signal();
}

/**
 * @brief Ejecucion del programa minishell
 * 
 */
void	ft_execute_minishell(void)
{
	while (true)
	{
		req_new_input();
	}
}

/**
 * @brief Iniciamos el programa minishell
 * Iniciamos g_minishell
 * Iniciamos environment
 * @param env 
 */
void	ft_init_minishell(char **env)
{
	g_minishell = ft_malloc(sizeof(t_minishell), true);
	g_minishell->last_command = C_OTHERS;
	g_minishell->process.quantity = 0;
	g_minishell->memory.quantity = 0;
	init_env(env);
	path_init();
	ft_signal();
	ft_execute_minishell();
}
