/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:39:43 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/08 17:38:19 by aramirez         ###   ########.fr       */
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
		else if (raw[count] == '<' && !open_quote)
		{
			if (q_redir == number)
				return (REIN);
			else
				q_redir++;
		}
		else if (raw[count] == '>' && !open_quote)
		{
			if (q_redir == number)
				return (REOUT);
			else
				q_redir++;
		}
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
	while (raw[count])
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
		count++;
	}
	return (quantity);
}

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
	bool	open_quote;
	char	quote;
	char	*files;
	int		q_files;

	count = 0;
	i = 0;
	q_files = 1;
	open_quote = false;
	files = ft_malloc(sizeof(char) * ft_strlen(raw) + 1, false);
	while (raw[count])
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
		count++;
	}
	while (raw[count] == '>' || raw[count] == '<'
		|| raw[count] == ' ' || raw[count] == '\t' || raw[count] == '\n')
		count++;
	while (raw[count] && (raw[count] != ' ' && raw[count] != '\t' && raw[count] != '\n'))
	{
		files[i] = raw[count];
		i++;
		count++;
	}
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

/**
 * @brief Contamos la cantidad de comillas, siempre y cuando no esten despues del \
 * 
 **/
bool	is_odd_quotes(char *raw)
{
	int		count;
	int		q_simple;
	int		q_doubble;
	bool	open_quote;
	char	quote;

	count = 0;
	open_quote = false;
	q_simple = 0;
	q_doubble = 0;
	while (raw[count])
	{
		if (is_quote(raw[count]) && !open_quote)
		{
			open_quote = true;
			quote = raw[count];
			if (raw[count] == '"' && quote == '"')
				q_doubble++;
			else if (raw[count] == '\'' && quote == '\'')
				q_simple++;
		}
		else if (is_quote(raw[count]) && raw[count] == quote)
		{
			if (raw[count] == '"' && quote == '"')
				q_doubble++;
			else if (raw[count] == '\'' && quote == '\'')
				q_simple++;
			open_quote = !open_quote;
		}
		count++;
	}
	if (q_doubble % 2 == 0 && q_simple % 2 == 0)
	{
		return (false);
	}
	printf("Quotes not closed\n");
	return (true);
}
