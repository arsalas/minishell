/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:27:34 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/08 19:06:08 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_the_echo(char **words)
{
	int		count;
	int		letter;

	count = 1;
	while (words[count])
	{
		letter = 0;
		while (words[count][letter])
		{
			if (words[count][letter] != 34 && words[count][letter] != 39)
			{
				while (words[count][letter] && (words[count][letter] != 34 && words[count][letter] != 39))
				{
					printf("%c", words[count][letter]);
					letter++;
				}
			}
			else
				letter++;
		}
		if (words[count + 1] == NULL)
		{
			printf("\n");
			return ;
		}
		printf(" ");
		count++;
	}
}

void	ft_look_for_flag(char *inside_pipes)
{
	char	**words;
	int		count;
	int cont = 0;
	while (inside_pipes[cont])
	{
		printf("EN MI INSIDE PIPES HE OBTENIDO:%c\n", inside_pipes[cont]);
		cont++;
	}
//	printf("ANTES DEL SPLIT TENGO:%c\n", inside_pipes[6]);
	count = 0;
	words = ft_split_words(inside_pipes);
//	printf("DESPUES DEL SPLIT\n");
	printf("DEBERIA SER HOLA:%s\n", words[1]);
//	if (ft_strcmp("-n", words[1]) || ft_strcmp("-N", words[2]))
//	if (words[1][0] == '-' && (words[1][1] == 'N' || words[1][1] == 'n'))
	while (words[cont])
	{
		printf("EN MI SPLIT HE OBTENIDO:%s\n", words[cont]);
		cont++;
	}
	if (words[1] != NULL &&
		(ft_strcmp("-n", words[1]) || ft_strcmp("-N", words[2])))
	{
		printf("ECHO -N\n");
		return ;
	}
	ft_print_the_echo(words);
	ft_free_split(words);
}
