/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:04:52 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/02 18:03:19 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_redirs(char *raw, int count, bool open_quote)
{
	if (raw[count] == '>' && raw[count + 1] == '>' && !open_quote)
	{
		if (raw[count + 2] == '>' || raw[count + 2] == '<'
			|| raw[count + 2] == '&')
		{
			printf("syntax error near unexpected token: `%c\'\n", raw[count + 2]);
			return (false); 
		}
	}
	else if (raw[count] == '<' && raw[count + 1] == '<' && !open_quote)
	{
		if (raw[count + 2] == '>' || raw[count + 2] == '<'
			|| raw[count + 2] == '&')
		{
			printf("syntax error near unexpected token: `%c\'\n", raw[count + 2]);
			return (false);
		}
	}
	return (true);
}

bool	is_correct_tokens(char *raw)
{
	int		count;
	bool	open_quote;
	char	quote;

	count = 0;
	open_quote = false;
	while (raw[count])
	{
		if (is_quote(raw[count]) && !open_quote)
		{
			open_quote = true;
			quote = raw[count];
		}
		else if (is_quote(raw[count]) && raw[count] == quote)
        {
			open_quote = !open_quote;
            quote = '\0';
        }
		if (!check_redirs(raw, count, open_quote))
			return (false);
		count++;
	}
	return (true);
}

// bool	is_correct_tokens(char *raw)
// {
// 	int		count;
// 	bool	open_quote;
// 	char	quote;

// 	count = 0;
// 	open_quote = false;
// 	while (raw[count])
// 	{
// 		if (is_quote(raw[count]) && !open_quote)
// 		{
// 			open_quote = true;
// 			quote = raw[count];
// 		}
// 		if (is_quote(raw[count]) && raw[count] == quote)
// 			open_quote = !open_quote;
// 		if (raw[count] == '>' && raw[count + 1] == '>' && !open_quote)
// 		{
// 			if (raw[count + 2] == '>' || raw[count + 2] == '<' || raw[count + 2] == '&')
// 			{
// 				printf("syntax error near unexpected token: `%c\'\n", raw[count + 2]);
// 				return (false);
// 			}
// 		}
// 		else if (raw[count] == '<' && raw[count + 1] == '<' && !open_quote)
// 		{
// 			if (raw[count + 2] == '>' || raw[count + 2] == '<' || raw[count + 2] == '&')
// 			{
// 				printf("syntax error near unexpected token: `%c\'\n", raw[count + 2]);
// 				return (false);
// 			}
// 		}
// 		count++;
// 	}
// 	return (true);
// }
