/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:08:39 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/09 15:12:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_special_char(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

static int	get_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_special_char(str[i]))
		i++;
	return (i);
}

static int	get_end(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && is_special_char(str[i]))
		i--;
	return (i + 1);
}

char	*ft_trim(char *str)
{
	char	*new_str;
	int		start;
	int		finish;
	int		len;

	start = get_start(str);
	finish = get_end(str);
	len = finish - start;
	new_str = ft_substr_mod(str, start, len);
	return (new_str);
}

/**
 * @brief Eliminamos los espacios vacíos
 * 
 * @param str 
 * @return int 
 */
int	ft_is_empty(char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] && (str[cont] == '\n'
			|| str[cont] == '\t' || str[cont] == ' '))
	{
		cont++;
	}
	return (cont);
}
