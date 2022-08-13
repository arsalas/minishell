/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:31:29 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 20:46:44 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* Nos saltamos los espacios, \t o \n que haya en el string
*/
int	ft_empty_piece(char *str, int count)
{
	while (str[count] && (str[count] == '\n'
			|| str[count] == '\t' || str[count] == ' '))
		count++;
	return (count);
}

/*
* Nos posicionamos despues de la palabra exit y los espacios
*/
int	ft_after_exit(char *str, int count)
{
	count = ft_empty_piece(str, count);
	count += 4;
	count = ft_empty_piece(str, count);
	return (count);
}

/*
* Damos error en caso de que nos den un no digit despues de exit
*/
int	ft_its_not_digit(char *str, int len)
{
	int		count;
	char	*str_error;

	count = ft_strlen(str);
	str_error = (char *)malloc((sizeof(char) * count + 1));
	count = 0;
	while (str[len] && !(ft_isdigit(str[len])))
	{
		str_error[count] = str[len];
		len++;
		count++;
	}
	printf("exit: %s: numeric argument required\n", str_error);
	return (-1);
}

/*
* Realizamos la funcion exit
*/
void	ft_make_exit(char *str)
{
	int		count;

	count = 0;
	while (str[count])
	{
		count = ft_after_exit(str, count);
		while (str[count])
		{
			if (!(ft_isdigit(str[count])))
			{
				if (ft_its_not_digit(str, count) == -1)
					return ;
			}
			count++;
		}
	}
	free (str);
	printf("exit\n");
	close_minishell();
}

void	ft_exit(char *str)
{
	ft_make_exit(str);
}
