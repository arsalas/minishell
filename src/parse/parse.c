/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:39:43 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/09 21:19:43 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Extrae el contenido del input (el texto)
 * 
 * @param raw is all the input between pipes
 * @return text (char *)
 */
char	*extract_content_input(char *raw)
{
	int		count;
	int		i;
	char	*text;

	count = 0;
	i = 0;
	text = ft_malloc(sizeof(char) * ft_strlen(raw) + 1, false);
	if (raw[count] == '>' || raw[count] == '<')
		return (NULL);
	while (raw[count] && (raw[count] != '>' && raw[count] != '<'))
	{
		if (is_quote(raw[count]))
			count++;
		text[i] = raw[count];
		i++;
		count++;
	}
	return (text);
}

int	one_redir(char *raw, int count)
{
	while (raw[count] == '>' || raw[count] == '<'
		|| raw[count] == ' ' || raw[count] == '\t' || raw[count] == '\n')
		count++;
	return (count);
}

int	position_redir(char *raw, int number, int count, bool open_quote)
{
	char	quote;
	int		q_files;

	q_files = 1;
	while (raw[count++])
	{
		if (is_quote(raw[count]) && !open_quote)
		{
			open_quote = true;
			quote = raw[count];
		}
		else if (is_quote(raw[count]) && raw[count] == quote)
			open_quote = !open_quote;
		else if ((raw[count] == '>' || raw[count] == '<') && !open_quote)
		{
			if (is_doubble_redirect(raw, count))
				count++;
			if (q_files == number)
				break ;
			else
				q_files++;
		}
	}
	return (count);
}

/**
 * @brief Extrae el nombre del archivo (files)
 * 
 * @param raw is all the input between pipes
 * @param number
 * @return files (char *)
 */
char	*get_filename_redirect(char *raw, int number)
{
	int		count;
	int		i;
	char	*files;
	bool	open_quote;

	i = 0;
	count = 0;
	open_quote = false;
	files = ft_malloc(sizeof(char) * ft_strlen(raw) + 1, false);
	count = position_redir(raw, number, count, open_quote);
	count = one_redir(raw, count);
	while (raw[count] && (raw[count] != ' '
			&& raw[count] != '\t' && raw[count] != '\n'))
		files[i++] = raw[count++];
	files[i] = '\0';
	return (files);
}

char	*get_input_redirect(char *raw)
{
	int		count;
	bool	open_quote;
	char	quote;

	count = 0;
	open_quote = false;
	quote = '\0';
	while (raw[count])
	{
		if (is_quote(raw[count]) && !open_quote)
		{
			quote = raw[count];
			open_quote = true;
		}
		else if (is_quote(raw[count]) && raw[count] == quote)
		{
			open_quote = !open_quote;
			quote = '\0';
		}
		if ((raw[count] == '>' || raw[count] == '<') && !open_quote)
			break ;
		count++;
	}
	return (ft_substr_mod(raw, 0, count));
}
