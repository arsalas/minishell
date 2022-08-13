/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:48:34 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/13 20:09:18 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* Funciones de parseo:
* 1 - Miramos el numero de pipes
* 2 - Chequeamos que las comillas en cada pipe esten cerradas
* 3 - Miramos que comando tenemos en el pipe
*/
void	ft_parse(void)
{
	ft_number_pipes();
	if (g_minishell->parse.pipe == 0)
		ft_odd_quotes(g_minishell->input);
	ft_search_command_in_pipe();
	ft_command_in_pipe();
}
