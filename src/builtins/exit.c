/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:31:29 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 11:01:11 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char *str)
{
	int		count;
	int		len;
	char	*str_error;

	count = ft_strlen(str);
	len = 0;
	str_error = (char *)malloc((sizeof(char) * count + 1));
	count = 0;
	while (str[count])
	{
		while (str[count] && (str[count] == '\n' || str[count] == '\t' || str[count] == ' '))
			count++;
		count += 4;
		while (str[count] && (str[count] == '\n' || str[count] == '\t' || str[count] == ' '))
			count++;
		while (str[count])
		{
			if (!(ft_isdigit(str[count])))
			{
				while (str[count] && !(ft_isdigit(str[count])))
				{
					str_error[len] = str[count];
					len++;
					count++;
				}
				printf("exit: %s: numeric argument required\n", str_error);
				return ;
			}
			count++;
		}
	}
	free (str);
	printf("exit\n");
	close_minishell();
}
