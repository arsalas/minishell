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

/*
* Obtenemos el mensaje que pasamos por la shell
*/
// VALIDATE
char	*ft_get_input(void)
{
	char	*prompt;

	prompt = get_prompt();
	return (readline(prompt));
}


/*
* Cuando comenzamos el programa, status = 0
* Iniciamos las senales antes de leer
*/
//VALIDATE
void	ft_signal(void)
{
	g_minishell->status = 0;
	ft_get_signal();
}

/**
 * @brief Ejecucion del programa minishell
 * 
 */
// VALIDATE
void	ft_execute_minishell(void)
{
	while (true)
	{
		req_new_input();
		// free_memory();
		// empty_trash();
	}
}

/**
 * @brief Iniciamos el programa minishell
 * Iniciamos g_minishell
 * Iniciamos environment
 * @param env 
 */
// VALIDATE
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
