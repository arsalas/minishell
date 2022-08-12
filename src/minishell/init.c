/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:30:13 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/11 18:53:38 by amurcia-         ###   ########.fr       */
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
* Leemos en bucle
*/
void	ft_read(void)
{
	while (1)
	{
		g_minishell->input = ft_get_input();
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
* Iniciamos g_minishell
*/
void	ft_init_minishell(void)
{
	g_minishell = get_memory(sizeof(t_minishell));
	ft_read();
}
