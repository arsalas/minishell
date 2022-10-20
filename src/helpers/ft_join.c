/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:58:52 by aramirez          #+#    #+#             */
/*   Updated: 2022/10/20 16:50:36 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	get_strlen(char **str)
// {
// 	int	len;
// 	int	i;

// 	len = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		len += ft_strlen(str[i]);
// 		i++;
// 	}
// 	return (len);
// }

// static int	get_elements(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// static void	cpy_content(char **elements, char *str, char c)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = 0;
// 	while (elements[i])
// 	{
// 		ft_memcpy(&str[len], elements[i], ft_strlen(elements[i]));
// 		len += ft_strlen(elements[i]);
// 		if (elements[i + 1])
// 		{
// 			str[len] = c;
// 			len++;
// 		}
// 		i++;
// 	}
// }

/**
 * @brief Une una cadena de strings usando un caracter entre cada string
 * 
 * @param elements array de strings
 * @param c caracter a unir
 * @return char* 
 */
// char	*ft_join(char **elements, char c)
// {
// 	int		len;
// 	char	*str;

// 	len = get_strlen(elements) + get_elements(elements);
// 	str = ft_malloc(sizeof(char) * len, true);
// 	cpy_content(elements, str, c);
// 	// ft_free_split(elements);
// 	return (str);
// }

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
	str = malloc(sizeof(char) * (l_s1 + l_s2 + l_s3 + 1));
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

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ ft_strlen(s3) + ft_strlen(s4)) + 1);
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
