/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:59:03 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/01 16:57:55 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Printa por pantalla una string
 * 
 * @param str strint a printar 
 */
void	print_string(char *str)
{
	write(1, str, ft_strlen(str));
}


