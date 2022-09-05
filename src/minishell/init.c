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
char	*ft_get_input(void)
{
	char	*prompt;

	prompt = get_prompt();
	// prompt = BMAG"minishell: "RESET;
	return (readline(prompt));
}

/*
* Leemos en bucle
*/
void	ft_read(void)
{
	while (1)
	{
		g_minishell->input = ft_get_input();
		if (!g_minishell->input)
		{
			printf("exit\n");
			close_minishell(0);
		}
		else if (*g_minishell->input != '\0')
		{
			ft_read_history();
			ft_parse();
		}
		free(g_minishell->input);
	}
	ft_clear_history();
	ft_free_usual();
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

/**
 * @brief Ejecucion del programa minishell
 * 
 */
void	ft_execute_minishell(void)
{
	// while (g_minishell->last_command != C_EXIT)
	while (true)
	{
		req_new_input();
		// free_memory();
		// empty_trash();
	}
}

/*
* Iniciamos g_minishell
* Iniciamos environment
*/
void	ft_init_minishell(char **env)
{
	g_minishell = get_memory(sizeof(t_minishell), true);
	g_minishell->last_command = C_OTHERS;
	g_minishell->process.quantity = 0;
	g_minishell->memory.quantity = 0;
	init_env(env);
	path_init();
	// update_env_var("PWD", "minishell");
	ft_signal();
	// ft_read();
	ft_execute_minishell();
}
