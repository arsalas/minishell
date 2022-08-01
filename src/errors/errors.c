/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:17:36 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/01 16:38:02 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_minishell(void)
{
	//TODO liberar memoria
	exit(0);
}

void	memory_error(void)
{
	perror("Error al reservar memoria\n");
	close_minishell();
}

