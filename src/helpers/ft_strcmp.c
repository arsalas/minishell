/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:51:56 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/03 19:44:36 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_strcmp(const char *s1, const char *s2, bool strict)
{
	size_t	cont;

	cont = 0;
	if (s1 == NULL && s2 == NULL)
		return (true);
	if (s1 == NULL || s2 == NULL)
		return (false);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	while (s1[cont] != '\0' || s2[cont] != '\0')
	{
		if (strict)
		{
			if (s1[cont] != s2[cont])
				return (false);
		}
		else
		{
			if (ft_tolower(s1[cont]) != ft_tolower(s2[cont]))
				return (false);
		}
		cont++;
	}
	return (true);
}
