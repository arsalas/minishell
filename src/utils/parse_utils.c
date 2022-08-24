/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:00:55 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/24 09:12:15 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* Saltamos la primera palabra de un string
*/
int	ft_skip_one_word(char *str)
{
	int	count;

	count = 0;
	while (str[count] == ' ' || str[count] == '\t' || str[count] == '\n')
		count++;
	while (str[count]
		&& (str[count] != ' ' && str[count] != '\t' && str[count] != '\n'))
		count++;
	while (str[count] == ' ' || str[count] == '\t' || str[count] == '\n')
		count++;
	return (count);
}
