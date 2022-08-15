/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:27:34 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 16:46:57 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void	ft_start_command(t_minishell *minishell, char *word)
{
	minishell->start = 0;
	while (word[minishell->start] && (word[minishell->start] == '\n' || word[minishell->start] == 't' || word[minishell->start]	== ' '))
		minishell->start++;
	if (minishell->flag == 0)
		minishell->start += +4;
	if (minishell->flag == 1)
	{
		minishell->start += +4;
		while (word[minishell->start] && (word[minishell->start] == '\n' || word[minishell->start] == 't' || word[minishell->start]	== ' '))
			minishell->start++;
		minishell->start += +2;
		while (word[minishell->start] == 'N' || word[minishell->start] == 'n')
			minishell->start++;
	}
	while (word[minishell->start] && (word[minishell->start] == '\n' || word[minishell->start] == 't' || word[minishell->start]	== ' '))
		minishell->start++;
}

//PRINTAMOS LO QUE HAY EN ECHO
void	ft_print_the_echo(t_minishell *minishell, char *words)
{
	int		letter;

	ft_start_command(minishell, words);
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
				if (words[letter] == 92 && (words[letter + 1] == 34 || words[letter + 1] == 39))
				{
					printf("%c", words[letter + 1]);
					letter += 2;
				}
				if (words[letter] == 34 && words[letter -1] != 92)
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
				if (words[letter] == 92 && (words[letter + 1] == 34 || words[letter + 1] == 39))
				{
					printf("%c", words[letter + 1]);
					letter += 2;
				}
				if (words[letter] == 39 && words[letter -1] != 92)
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
		if (words[letter] == '\0' && minishell->flag != 1)
		{
			printf("\n");
			return ;
		}
	}
}

//MIRAMOS SI LAS COMILLAS ESTAN CERRADAS
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
				if (inside[count] == 34 && inside[count -1] != 92)
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
				if (inside[count] == 39 && inside[count -1] != 92)
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
void	ft_look_for_flag(t_minishell *minishell, char *inside_pipes)
{
	char	**words;
	int		cont;

	cont = 2;
	words = ft_split_words(inside_pipes);
	if (words[1][0] == '-' && words[1][1] == 'n')
	{
		while (words[1][cont] == 'n')
			cont++;
		if (words[1][cont] != '\0')
		{
			printf("ERROR\nEste flag no existe");
			close_minishell();
		}
		minishell->flag = 1;
		printf("TENEMOS FLAG\n");
	}
	else if (words[1][0] == '-' && words[1][1] == 'N')
	{
		while (words[1][cont] == 'N')
			cont++;
		if (words[1][cont] != '\0')
		{
			printf("ERROR\nEste flag no existe\n");
			close_minishell();
		}
		minishell->flag = 1;
		printf("TENEMOS FLAG\n");
	}
	ft_free_split(words);
}

// TODAS LAS FUNCIONES PARA HACER EL ECHO
void	ft_make_echo(t_minishell *minishell, char *inside_pipes)
{
	ft_look_for_flag(minishell, inside_pipes);
	ft_odd_quotes(minishell, inside_pipes);
	ft_quotes_error(minishell, inside_pipes);
	ft_print_the_echo(minishell, inside_pipes);
}
*/

//TODO --> detectar si hay flag
bool echo_have_flag(char *input)
{
    (void)input;
    return (false);
}

int get_start_echo_input(char *input)
{
    int i;

    i = 4;
    while (input[i] == ' ')
        i++;
    return(i);
}

char    *extract_echo_input(char *input)
{
    int start;
    int end;

    start = get_start_echo_input(input);
    end = ft_strlen(input);
    return (ft_substr(input, start, end - start));
}

void    ft_echo(char *input)
{
    char    *echo;

    echo = extract_echo_input(input);
    execute_echo(echo, echo_have_flag(input));
}