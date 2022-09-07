/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:58:52 by aramirez          #+#    #+#             */
/*   Updated: 2022/09/07 16:36:58 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_strlen(char **str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		len += ft_strlen(str[i]);
		i++;
	}
	return (len);
}

static int	get_elements(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	cpy_content(char **elements, char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (elements[i])
	{
		ft_memcpy(&str[len], elements[i], ft_strlen(elements[i]));
		len += ft_strlen(elements[i]);
		if (elements[i + 1])
		{
			str[len] = c;
			len++;
		}
		i++;
	}
}

/**
 * @brief Une una cadena de strings usando un caracter entre cada string
 * 
 * @param elements array de strings
 * @param c caracter a unir
 * @return char* 
 */
char	*ft_join(char **elements, char c)
{
	int		len;
	char	*str;

	len = get_strlen(elements) + get_elements(elements);
	str = ft_malloc(sizeof(char) * len, true);
	cpy_content(elements, str, c);
	// ft_free_split(elements);
	return (str);
}
