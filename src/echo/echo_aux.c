/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:14:01 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 15:24:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_var(char *var)
{
	return (get_env_var(var));
}

/**
 * @brief Comprueba si hay una variable de entorno en la string
 * 
 * @param str 
 * @return bool 
 */
bool	is_var(char *str)
{
	int		i;
	char	last_char;

	i = 0;
	last_char = '\0';
	while (str[i])
	{
		if (last_char == '$' && str[i] == '$')
			return (false);
		if (last_char == '$' && str[i] != '$')
			return (true);
		last_char = str[i];
		i++;
	}
	return (false);
}

/**
 * @brief Printa la variable de entorno 
 * y devuelve el numero de caracteres de el literal de la variablde con $ 
 * 
 * @param input nombre variable de entorno
 * @return numero de caracteres de la variable de entorno
 */
int print_env_var(char *input)
{
    int     end;
    char    *name;
    
    end = 0;
    while (input[end] && (input[end] != ' ' && input[end] != ','))
        end++;
    name = ft_substr(input, 1, end - 1);
    printf("%s", get_env_var(name));
    free(name);
    return (end);
}


void    print_echo_token(char *token)
{
    int i;

    i = 0;
    while (token[i])
    {
        if (token[i] == '$' && token[i + 1] != ' ')
        {
            i += print_env_var(&token[i]);
        }
        if (token[i] != '\\' || (token[i] == '\\' && i > 0 && token[i - 1] == '\\'))
            printf("%c", token[i]);
        i++;
    }
}

void    print_echo(char **tokens, bool have_flag)
{
    int i;

    i = 0;
    while (tokens[i])
    {
        print_echo_token(tokens[i]);
        i++;
    }
    if (!have_flag)
        printf("\n");
}

void    execute_echo(char *input, bool have_flag)
{
    char    **tokens;
    
    tokens = parse_echo(input);
    free(input);
    print_echo(tokens, have_flag);
}
