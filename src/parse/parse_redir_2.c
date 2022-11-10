/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:28:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/10 15:31:29 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_redirect_type1(bool	*open_quote, char *raw, int *count, char *quote)
{
	if (is_quote(raw[*count]) && !*open_quote)
	{
		*open_quote = true;
		*quote = raw[*count];
	}
	if (is_quote(raw[*count]) && raw[*count] == *quote)
		*open_quote = !*open_quote;
}

bool	get_redirect_type2(char *raw, int number, int *q_redir, int *count)
{
	if (*q_redir == number)
		return (true);
	else
		*q_redir = *q_redir + 1;
	if (raw[*count] == '>' && raw[*count + 1] == '>')
		*count = *count + 1;
	return (false);
}

bool	get_redirect_type3(char *raw, int number, int *q_redir, int *count)
{
	if (*q_redir == number)
		return (true);
	else
		*q_redir = *q_redir + 1;
	if (raw[*count] == '<' && raw[*count + 1] == '<')
		*count = *count + 1;
	return (false);
}

int	get_redirect_type4(char *raw, int number, int *q_redir, int *count)
{
	bool	open_quote;
	char	quote;

	get_redirect_type1(&open_quote, raw, count, &quote);
	if (raw[*count] == '>' && raw[*count + 1] == '>' && !open_quote)
	{
		if (get_redirect_type2(raw, number, q_redir, count))
			return (1);
	}
	else if (raw[*count] == '<' && raw[*count + 1] == '<' && !open_quote)
	{
		if (get_redirect_type3(raw, number, q_redir, count))
			return (2);
	}
	else if (raw[*count] == '<' && !open_quote && *q_redir == number)
		return (3);
	else if (raw[*count] == '<' && !open_quote)
			q_redir++;
	else if (raw[*count] == '>' && !open_quote && *q_redir == number)
		return (4);
	else if (raw[*count] == '>' && !open_quote)
		*q_redir = *q_redir + 1;
	*count = *count + 1;
	return (5);
}

/**
 * @brief Comprueba el tipo de redireccion
 * 
 * @param raw is all the input between pipes
 * @param number of redirections
 * @return the redirection type
 */
t_redir_type	get_redirect_type(char *raw, int number)
{
	int		count;
	int		q_redir;
	int		redir;

	count = 0;
	q_redir = 1;
	while (raw[count])
	{
		redir = get_redirect_type4(raw, number, &q_redir, &count);
		if (redir == 1)
			return (DOUBBLE_REOUT);
		else if (redir == 2)
			return (DOUBBLE_REIN);
		else if (redir == 3)
			return (REIN);
		else if (redir == 4)
			return (REOUT);
	}
	return (REOUT);
}
