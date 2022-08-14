/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:48:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 16:48:32 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool have_correct_format(char *input)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (input[i] == '=' && input[i - 1] != ' ')
            return (true);
        i++;
    }
    return (false);
}

static int get_finish_position(char *input)
{
    int i;

    i = 0;
    while (input[i] != '=')
        i++;
    return (i);
}

static int get_start_export(char *input)
{
    int i;

    i = 6;
    while (input[i] == ' ')
        i++;
    return (i);
}

static char    *get_export_name(char *input)
{
    int len;
    int start;

    start = get_start_export(input);
    len = get_finish_position(input);
    return (ft_substr(input, start, len - start));
}

static char    *get_export_content(char *input)
{
    int len;
    int start;

    start = get_finish_position(input) + 1;
    len = ft_strlen(input);
    return (ft_substr(input, start, len));
}

/**
 * @brief Crea una nueva variable de entorno
 * 
 * @param name 
 * @param content 
 */
void	ft_export(char *input)
{
    char    *name;
    char    *content;

    if (!have_correct_format(input))
        return ;
    name = get_export_name(input);
    content = get_export_content(input);
	push_env(name, content);
    free(name);
    free(content);
}

/*
int	ft_end_export(int start, char *word)
{
	int	count;

	count = 0;
	while (word[start] != '\0' && word[start] != ' ' && word[start] != '\t' && word[start] != '\n')
	{
		start++;
		count++;
	}
	return (count);
}

int	ft_start_export(char *word)
{
	int	count;

	count = 0;
	printf("WORD IS %s\n", word);
	while (word[count] != '\0' && (word[count] == ' ' || word[count] == '\t' || word[count] == '\n'))
		count++;
	count += +6;
	while (word[count] != '\0' && (word[count] == ' ' || word[count] == '\t' || word[count] == '\n'))
		count++;
	return (count);
}

void	ft_equal_error(char *words)
{
	int	count;
	int	equal;

	count = 0;
	equal = 0;
	while (words[count])
	{
		if (words[count] == '=')
			equal++;
		count++;
	}
	if (equal != 1)
	{
		printf("ERROR\nVARIABLE NO ASIGNADA\n");
		close_minishell();
	}
}

void	ft_save_the_export(t_minishell *minishell, char *words, int start, int len)
{
	int		count;

	count = 0;
	minishell->prev = (char *)malloc((sizeof(char) * len + 1));
	minishell->post = (char *)malloc((sizeof(char) * len + 1));
	while (words[start] && words[start] != '=')
	{
		minishell->prev[count] = words[start];
		start++;
		count++;
	}
	minishell->prev[count] = '\0';
	if (words[start] == '=')
		start++;

	count = 0;
	while (words[start] && (words[start] != ' ' && words[start] != '\n' && words[start] != '\t'))
	{
		minishell->post[count] = words[start];
		start++;
		count++;
	}
	minishell->post[count] = '\0';
	printf("VAR IS %s\n", minishell->prev);
	printf("THE NAME OF THE VAR IS %s\n", minishell->post);
}

void	ft_make_export(t_minishell *minishell, char *inside_pipes)
{
	int	start;
	int	len;

	ft_odd_quotes(minishell, inside_pipes);
	ft_quotes_error(minishell, inside_pipes);
	ft_equal_error(inside_pipes);
	start = ft_start_export(inside_pipes);
	len = ft_end_export(start, inside_pipes);
	ft_save_the_export(minishell, inside_pipes, start, len);
}
*/