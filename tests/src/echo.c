/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:34:17 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 13:40:52 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_echo(void)
{
	printf(YEL"is_var: \n"RESET);
	(is_var("$$USER")) ? printf(RED"KO ") : printf(GRN"OK ");
	(is_var("$USER")) ? printf(GRN"OK ") : printf(RED"KO ");
	(is_var("USER")) ? printf(RED"KO ") : printf(GRN"OK ");
	printf(RESET"\n");
}