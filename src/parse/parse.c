/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:39:43 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/22 19:40:12 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Comprueba si hay redirecciones
 * 
 * @param raw 
 * @return true 
 * @return false 
 */
bool    have_redirect(char *raw)
{
	int     i;
	bool    open_quote;
	char    quote;

	open_quote = false;
	i = 0;
	while (raw[i])
	{
		if (is_quote(raw[i]) && !open_quote)
		{
			open_quote = true;
			quote  = raw[i];
		}
		else if (is_quote(raw[i]) && raw[i] == quote)
			open_quote = !open_quote;
		if (is_redirect(raw[i]) && !open_quote)
		{
			if (i > 0 &&  raw[i - 1] != '\\')
				return (true);
		}
		i++;
	}
	return (false);
}

t_redir_type get_redirect_type(char *raw, int number)
{
	(void) raw;
	(void) number;
	return (REIN);
}

int	get_redirect_quantity(char *raw)
{
	int		count;
	int		redir;
	bool	open_quote;
	char	quote;

	count = 0;
	redir = 0;
	open_quote = false;
	while (raw[count])
	{
		if (is_quote(raw[count]) && !open_quote)
		{
			open_quote = true;
			quote = raw[count];
		}
		else if (is_quote(raw[count]) && raw[count] == quote)
			open_quote = !open_quote;
		else if ((raw[count] == '>' && raw[count + 1] == '>' && !open_quote)
			|| (raw[count] == '<' && raw[count + 1] == '<' && !open_quote))
		{
			if (count > 0 &&  raw[count - 1] != '\\')
			{
				redir++;
				count++;
			}
		}
		else if ((raw[count] == '>' || raw[count] == '<') && !open_quote)
		{
			if (count > 0 &&  raw[count - 1] != '\\')
			{
				redir++;
			}
		}
		count++;
	}
	return (redir);
}

// INPUT es el texto
char *extract_content_input(char *raw)
{

	return (raw);
}

char    *get_filename_redirect(char *raw, int number);

char    *get_input_parsed(char *raw) // 
{
	(void)raw;
	return (NULL);
}