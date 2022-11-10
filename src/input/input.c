/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:20:59 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/08 19:59:02 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Libera la memoria de los procesos ejecutados
 * 
 */
void	free_process_memory(void)
{
	int	i;

	if (g_minishell->process.quantity == 0)
		return ;
	i = 0;
	while (i < g_minishell->process.quantity)
	{
		free(g_minishell->process.content[i].raw);
		i++;
	}
	free(g_minishell->process.content);
}

/**
 * @brief Obtiene la informacion de ejecucion de cada proceso
 * 
 */
void	get_process_content(void)
{
	int			i;

	i = 0;
	g_minishell->process.content = ft_malloc(sizeof(t_pipe)
			* g_minishell->process.quantity, true);
	while (i < g_minishell->process.quantity)
	{
		g_minishell->process.content[i].command
			= ft_get_command(g_minishell->input);
		g_minishell->process.content[i].raw
			= extract_content_process_input(g_minishell->input);
		g_minishell->input = extract_others_process_input(g_minishell->input);
		i++;
	}
}

/**
 * @brief Crea la informacion de los procesos a ejecutar
 * 
 */
void	create_proces_data(void)
{
	g_minishell->process.quantity
		= get_quantity_process_in_input(g_minishell->input);
	get_process_content();
	execute_pipe(g_minishell->process);
}

void	free_process_content(void)
{
	free(g_minishell->process.content);
}

/**
 * @brief Peticion de un nuevo input al usuario
 *
 */
void	req_new_input(void)
{
	static int	n = 0;
	char		*input;
	int			i;

	i = 0;
	i = g_minishell->process.quantity -1;
	input = ft_get_input();
	if (!input)
	{
		printf("exit\n");
		ft_clear_history();
		close_minishell(0);
	}
	g_minishell->input = ft_trim(input);
	free(input);
	if (ft_strlen(g_minishell->input) == 0)
	{
		free(g_minishell->input);
		return ;
	}
	ft_read_history();
	create_proces_data();
	free_process_content();
	n++;
	free(g_minishell->input);
}
