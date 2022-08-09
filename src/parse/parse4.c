/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:49:21 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/08 17:09:32 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_env(char **words)
{
	if (words[0][0] != 'E' && words[0][0] != 'e')
		return (-1);
	if (words[0][1] != 'N' && words[0][1] != 'n')
		return (-1);
	if (words[0][2] != 'V' && words[0][2] != 'v')
		return (-1);
	if (words[0][3] != '\0')
		return (-1);
	return (0);
}

int	ft_is_pwd(char **words)
{
	if (words[0][0] != 'P' && words[0][0] != 'p')
		return (-1);
	if (words[0][1] != 'W' && words[0][1] != 'w')
		return (-1);
	if (words[0][2] != 'D' && words[0][2] != 'd')
		return (-1);
	if (words[0][3] != '\0')
		return (-1);
	return (0);
}
