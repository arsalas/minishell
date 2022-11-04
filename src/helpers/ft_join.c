/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:58:52 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/04 17:07:47 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*str;
	int		l_s1;
	int		l_s2;
	int		c;

	l_s1 = ft_strlen((char *)s1);
	l_s2 = ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (str == NULL)
		return (NULL);
	c = 0;
	while (c < l_s2 || c < l_s1)
	{
		if (c < l_s1)
			str[c] = s1[c];
		if (c < l_s2)
			str[l_s1 + c] = s2[c];
		c++;
	}
	str[l_s1 + l_s2] = '\0';
	free(s1);
	free(s2);
	return (str);
}

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*str;
	int		l_s1;
	int		l_s2;
	int		l_s3;
	int		c;

	l_s1 = ft_strlen((char *)s1);
	l_s2 = ft_strlen((char *)s2);
	l_s3 = ft_strlen((char *)s3);
	str = ft_malloc(sizeof(char) * (l_s1 + l_s2 + l_s3 + 1), false);
	if (str == NULL)
		return (NULL);
	c = 0;
	while (c < l_s2 || c < l_s1 || c < l_s3)
	{
		if (c < l_s1)
			str[c] = s1[c];
		if (c < l_s2)
			str[l_s1 + c] = s2[c];
		if (c < l_s3)
			str[l_s1 + l_s2 + c] = s3[c];
		c++;
	}
	str[l_s1 + l_s2 + l_s3] = '\0';
	return (str);
}

char	*ft_strjoin_four(char *s1, char *s2, char *s3, char *s4)
{
	char	*str;
	size_t	c;

	str = ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ ft_strlen(s3) + ft_strlen(s4)) + 1, false);
	if (str == NULL)
		return (NULL);
	c = 0;
	while (c < ft_strlen(s1) || c < ft_strlen(s2)
		|| c < ft_strlen(s3) || c < ft_strlen(s4))
	{
		if (c < ft_strlen(s1))
			str[c] = s1[c];
		if (c < ft_strlen(s2))
			str[ft_strlen(s1) + c] = s2[c];
		if (c < ft_strlen(s3))
			str[ft_strlen(s1) + ft_strlen(s2) + c] = s3[c];
		if (c < ft_strlen(s4))
			str[ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + c] = s4[c];
		c++;
	}
	str[ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + ft_strlen(s4)] = '\0';
	return (str);
}
