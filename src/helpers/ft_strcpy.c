/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:18:34 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/18 18:48:18 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcpy(const char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen((char *)s1) + 1;
	str = (get_memory(sizeof(char) * len, true));
	if (str == 0)
		return (NULL);
	str = ft_memcpy(str, s1, len);
	return (str);
}
