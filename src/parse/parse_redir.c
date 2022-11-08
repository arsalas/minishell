/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:12:22 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/08 20:46:33 by amurcia-         ###   ########.fr       */
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
bool	have_redirect(char *raw)
{
	int		i;
	bool	open_quote;
	char	quote;

	open_quote = false;
	i = 0;
	while (raw[i])
	{
		if (is_quote(raw[i]) && !open_quote)
		{
			open_quote = true;
			quote = raw[i];
		}
		else if (is_quote(raw[i]) && raw[i] == quote)
		{
			open_quote = !open_quote;
			quote = '\0';
		}
		if (is_redirect(raw[i]) && !open_quote)
			return (true);
		i++;
	}
	return (false);
}

/**
 * @brief Comprueba el tipo de redireccion
 * 
 * @param raw is all the input between pipes
 * @param number of redirections
 * @return the redirection type
 */
// t_redir_type	get_redirect_type(char *raw, int number)
// {
// 	int		count;
// 	int		q_redir;
// 	bool	open_quote;
// 	char	quote;

// 	count = 0;
// 	q_redir = 1;
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
// 			if (q_redir == number)
// 				return (DOUBBLE_REOUT);
// 			else
// 				q_redir++;
// 			if (raw[count] == '>' && raw[count + 1] == '>')
// 				count++;
// 		}
// 		else if (raw[count] == '<' && raw[count + 1] == '<' && !open_quote)
// 		{
// 			if (q_redir == number)
// 				return (DOUBBLE_REIN);
// 			else
// 				q_redir++;
// 			if (raw[count] == '<' && raw[count + 1] == '<')
// 				count++;
// 		}
// 		else if (raw[count] == '<' && !open_quote)
// 		{
// 			if (q_redir == number)
// 				return (REIN);
// 			else
// 				q_redir++;
// 		}
// 		else if (raw[count] == '>' && !open_quote)
// 		{
// 			if (q_redir == number)
// 				return (REOUT);
// 			else
// 				q_redir++;
// 		}
// 		count++;
// 	}
// 	return (REOUT);
// }

// LA VERSIÓN ORIGINAL ESTÁ ARRIBA
t_redir_type	get_redirect_type(char *raw, int number)
{
	int		count;
	int		q_redir;
	bool	open_quote;
	char	quote;

	count = 0;
	q_redir = 1;
	open_quote = false;
	while (raw[count])
	{
		if (is_quote(raw[count]) && !open_quote)
		{
			open_quote = true;
			quote = raw[count];
		}
		if (is_quote(raw[count]) && raw[count] == quote)
			open_quote = !open_quote;
		if (raw[count] == '>' && raw[count + 1] == '>' && !open_quote)
		{
			if (q_redir == number)
				return (DOUBBLE_REOUT);
			else
				q_redir++;
			if (raw[count] == '>' && raw[count + 1] == '>')
				count++;
		}
		else if (raw[count] == '<' && raw[count + 1] == '<' && !open_quote)
		{
			if (q_redir == number)
				return (DOUBBLE_REIN);
			else
				q_redir++;
			if (raw[count] == '<' && raw[count + 1] == '<')
				count++;
		}
		else if (raw[count] == '<' && !open_quote && q_redir == number)
			return (REIN);
		else if (raw[count] == '<' && !open_quote)
				q_redir++;
		else if (raw[count] == '>' && !open_quote && q_redir == number)
			return (REOUT);
		else if (raw[count] == '>' && !open_quote)
			q_redir++;
		count++;
	}
	return (REOUT);
}

/**
 * @brief Comprueba el numero de redicciones
 * 
 * @param raw is all the input between pipes
 * @return quantity (int)
 */
int	get_redirect_quantity(char *raw)
{
	int		count;
	int		quantity;
	bool	open_quote;
	char	quote;

	count = 0;
	quantity = 0;
	open_quote = false;
	while (raw[count++])
	{
		if (is_quote(raw[count]) && !open_quote)
		{
			open_quote = true;
			quote = raw[count];
		}
		else if (is_quote(raw[count]) && raw[count] == quote)
			open_quote = !open_quote;
		else if (is_redirect(raw[count]) && !open_quote)
		{
			if (raw[count] == raw[count + 1])
				count++;
			quantity++;
		}
	}
	return (quantity);
}
