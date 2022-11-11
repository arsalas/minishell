/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:19:15 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/11 16:48:26 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_input_parsed(t_pipe *command)
{
	int		count;
	char	*aux;

	command->redirs.quantity = 0;
	aux = get_input_redirect(command->raw);
	command->input = ft_trim(aux);
	free(aux);
	if (have_redirect(command->raw))
	{
		command->redirs.quantity = get_redirect_quantity(command->raw);
		command->redirs.info = ft_malloc(sizeof(t_redir_info)
				* command->redirs.quantity, false);
		count = 0;
		while (count < command->redirs.quantity)
		{
			command->redirs.info[count].types
				= get_redirect_type(command->raw, count + 1);
			command->redirs.info[count].files
				= get_filename_redirect(command->raw, count + 1);
			count++;
		}
	}
}

void	is_odd_quotes1(char *raw, char *quote, int *quotes, int count)
{
	*quote = raw[count];
	if (raw[count] == '"' && *quote == '"')
		quotes[1]++;
	else if (raw[count] == '\'' && *quote == '\'')
		quotes[0]++;
}

void	is_odd_quotes2(char *raw, char *quote, int *quotes, int count)
{
	if (raw[count] == '"' && *quote == '"')
		quotes[1]++;
	else if (raw[count] == '\'' && *quote == '\'')
		quotes[0]++;
}

bool	is_odd_quotes3(int *quotes)
{
	if (quotes[1] % 2 == 0 && quotes[0] % 2 == 0)
		return (false);
	printf("Quotes not closed\n");
	return (true);
}

/**
 * @brief Contamos la cantidad de comillas, 
 * siempre y cuando no esten despues del \
 * 
 * @param raw 
 * @return true 
 * @return false 
 */
bool	is_odd_quotes(char *raw)
{
	int		count;
	int		quotes[2];
	bool	open_quote;
	char	quote;

	count = 0;
	open_quote = false;
	quotes[0] = 0;
	quotes[1] = 0;
	while (raw[count])
	{
		if (is_quote(raw[count]) && !open_quote)
		{
			open_quote = true;
			is_odd_quotes1(raw, &quote, quotes, count);
		}
		else if (is_quote(raw[count]) && raw[count] == quote)
		{
			is_odd_quotes2(raw, &quote, quotes, count);
			open_quote = !open_quote;
		}
		count++;
	}
	return (is_odd_quotes3(quotes));
}
