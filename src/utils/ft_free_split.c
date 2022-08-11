/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:41:43 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/11 16:42:20 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* Free de un array bidimensional
*/
void	ft_free_split(char **words)
{
	int	count;

	count = 0;
	while (words[count])
	{
		free(words[count]);
		count++;
	}
	free(words);
}