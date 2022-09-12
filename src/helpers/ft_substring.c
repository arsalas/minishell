/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:38:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/09/12 12:20:51 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*ft_substring(char const *s, unsigned int start, size_t len)
// {
// 	char	*str;
// 	size_t	str_l;
// 	size_t	l;

// 	str_l = ft_strlen(s);
// 	if (str_l - start >= len)
// 		l = len + 1;
// 	else
// 		l = str_l - start + 1;
// 	if (len == 0 || str_l == 0 || start > str_l)
// 	{
// 		str = ft_malloc(sizeof(char), true);
// 		if (str == NULL)
// 			return (NULL);
// 		str[0] = '\0';
// 		return (str);
// 	}
// 	str = ft_malloc(sizeof(char) * l, true);
// 	if (str == NULL)
// 		return (NULL);
// 	ft_strlcpy(str, (s + start), l);
// 	return (str);
// }
