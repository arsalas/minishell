/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:51:06 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/01 20:51:33 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_searchstr(char *str1, const char *str2, size_t i)
{
	size_t	j;
	int		find;

	j = 0;
	find = 1;
	while (str2[j] != '\0')
	{
		if (str1[i + j] != str2[j])
			find = 0;
		j++;
	}
	return (find);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	size_t	i;
	int		f;

	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	str = (char *)haystack;
	i = 0;
	f = 0;
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			f = ft_searchstr(str, needle, i);
			if (f == 1)
				break ;
		}
		i++;
	}
	if (f == 1)
		return (str + i);
	else
		return (NULL);
}
