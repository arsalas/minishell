/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:56:21 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/08 17:02:17 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_echo(char **words)
{
	if (words[0][0] != 'E' && words[0][0] != 'e')
		return (-1);
	if (words[0][1] != 'C' && words[0][1] != 'c')
		return (-1);
	if (words[0][2] != 'H' && words[0][2] != 'h')
		return (-1);
	if (words[0][3] != 'O' && words[0][3] != 'o')
		return (-1);
	if (words[0][4] != '\0')
		return (-1);
	return (0);
}

int	ft_is_cd(char **words)
{
	if (words[0][0] != 'C' && words[0][0] != 'c')
		return (-1);
	if (words[0][1] != 'D' && words[0][1] != 'd')
		return (-1);
	if (words[0][2] != '\0')
		return (1);
	return (0);
}

int	ft_is_export(char **words)
{
	if (words[0][0] != 'E' && words[0][0] != 'e')
		return (-1);
	if (words[0][1] != 'X' && words[0][1] != 'x')
		return (-1);
	if (words[0][2] != 'P' && words[0][2] != 'p')
		return (-1);
	if (words[0][3] != 'O' && words[0][3] != 'o')
		return (-1);
	if (words[0][4] != 'R' && words[0][4] != 'r')
		return (-1);
	if (words[0][5] != 'T' && words[0][5] != 't')
		return (-1);
	if (words[0][6] != '\0')
		return (1);
	return (0);
}

int	ft_is_exit(char **words)
{
	if (words[0][0] != 'E' && words[0][0] != 'e')
		return (-1);
	if (words[0][1] != 'X' && words[0][1] != 'x')
		return (-1);
	if (words[0][2] != 'I' && words[0][2] != 'i')
		return (-1);
	if (words[0][3] != 'T' && words[0][3] != 't')
		return (-1);
	if (words[0][4] != '\0')
		return (1);
	return (0);
}

int	ft_is_unset(char **words)
{
	if (words[0][0] != 'U' && words[0][0] != 'u')
		return (-1);
	if (words[0][1] != 'N' && words[0][1] != 'n')
		return (-1);
	if (words[0][2] != 'S' && words[0][2] != 's')
		return (-1);
	if (words[0][3] != 'E' && words[0][3] != 'e')
		return (-1);
	if (words[0][4] != 'T' && words[0][4] != 't')
		return (-1);
	if (words[0][5] != '\0')
		return (1);
	return (0);
}
