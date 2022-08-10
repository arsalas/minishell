/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:27:34 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/10 10:37:56 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_start_echo(t_minishell *minishell, char *word)
{
	minishell->start = 0;
	while (word[minishell->start] && (word[minishell->start] == '\n' || word[minishell->start] == 't' || word[minishell->start]	== ' '))
		minishell->start++;
	minishell->start += +4;
	while (word[minishell->start] && (word[minishell->start] == '\n' || word[minishell->start] == 't' || word[minishell->start]	== ' '))
		minishell->start++;
	printf("START ES %d\n", minishell->start);
}

void	ft_print_the_echo(t_minishell *minishell, char *words)
{
	int		letter;

	letter = 0;
	ft_start_echo(minishell, words);
	letter = minishell->start;
	while (words[letter])
	{
		while (words[letter] && (words[letter] == '\n' || words[letter] == 't' || words[letter]	== ' '))
			letter++;
		if (words[letter] == 92 && (words[letter + 1] == 34 || words[letter + 1] == 39))
		{
			printf("%c", words[letter + 1]);
			letter += 2;
		}
		else if (words[letter] == 34)
		{
			letter++;
			while (words[letter])
			{
				if (words[letter] == 34)
				{
					letter++;
					break ;
				}
				printf("%c", words[letter]);
				letter++;
			}
		}
		else if (words[letter] == 39)
		{
			letter++;
			while (words[letter])
			{
				if (words[letter] == 39)
				{
					letter++;
					break ;
				}
				printf("%c", words[letter]);
				letter++;
			}
		}
		else
		{
			printf("%c", words[letter]);
			letter++;
		}
		if (words[letter] == '\0')
		{
			printf("\n");
			return ;
		}
	}
}

void	ft_quotes_error(t_minishell *minishell, char *inside)
{
	int	count;

	count = 0;
	while (inside[count])
	{
		if (inside[count] == 92 && (inside[count + 1] == 34 || inside[count + 1] == 39))
			count += count + 2;
		if (inside[count] == 34)
		{
			minishell->previous_double++;
			count++;
			while (inside[count])
			{
				if (inside[count] == 34)
				{
					minishell->previous_double++;
					break ;
				}
				count++;
			}
		}
		if (inside[count] == 39)
		{
			minishell->previous_simple++;
			count++;
			while (inside[count])
			{
				if (inside[count] == 39)
				{
					minishell->previous_simple++;
					break ;
				}
				count++;
			}
		}
		if (minishell->previous_simple % 2 != 0 || minishell->previous_double % 2 != 0)
		{
			printf("ERROR\nComillas no cerradas\n");
			close_minishell();
		}
		count++;
	}
}

// MIRAMOS SI TENEMOS FLAG
void	ft_look_for_flag(char *inside_pipes)
{
	char	**words;

	words = ft_split_words(inside_pipes);
	if (words[1] != NULL &&
		(ft_strcmp("-n", words[1]) || ft_strcmp("-N", words[2])))
	{
		printf("ECHO -N\n");
		return ;
	}
	ft_free_split(words);
}

// TODAS LAS FUNCIONES PARA HACER EL ECHO
void	ft_make_echo(t_minishell *minishell, char *inside_pipes)
{
	ft_look_for_flag(inside_pipes);
	ft_odd_quotes(minishell, inside_pipes);
	ft_quotes_error(minishell, inside_pipes);
	ft_print_the_echo(minishell, inside_pipes);
}
