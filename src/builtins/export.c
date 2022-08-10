/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:48:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/10 12:02:20 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Crea una nueva variable de entorno
 * 
 * @param name 
 * @param content 
 */
void	export(char *name, char *content)
{
	push_env(name, content);
}

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

void	ft_save_the_export(char *words, int start, int len)
{
	int		count;
	char	*var;

	count = 0;
	var = (char *)malloc((sizeof(char) * len + 1));
	if (!var)
		return ;
	printf("START ES %d\n", start);
	printf("END ES %d\n", len);
	var[len] = '\0';
	printf("VAR LEN SHOULD BE NULL: %c\n", var[len]);
	while (words[start])
	{
		var[count] = words[start];
		start++;
		count++;
	}
	printf("VAR IS %s\n", var);
}

void	ft_make_export(t_minishell *minishell, char *inside_pipes)
{
	int	start;
	int	len;

	ft_odd_quotes(minishell, inside_pipes);
	ft_quotes_error(minishell, inside_pipes);
	start = ft_start_export(inside_pipes);
	len = ft_end_export(start, inside_pipes);
	ft_save_the_export(inside_pipes, start, len);
}
