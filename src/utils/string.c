/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:11:54 by aramirez          #+#    #+#             */
/*   Updated: 2022/09/06 11:48:42 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_array_len(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}

// char    **push_string(char **arr, char *string)
// {
//     int     len;
//     char    **new_arr;

//     len = get_array_len(arr);
//     new_arr = ft_realloc(arr, len + 1);
//     return (new_arr);
// }

bool    is_delim(char c)
{
    if (c == '\'' || c == '"' || c == '$')
        return (true);
    return (false);
}

char    *parse_token(char *input)
{
    char    delim;
    int     start;
    int     i;
    int     end;
    char    *str;

    str = malloc(sizeof(char));
    start = 0;
    delim = 0;
    i = 0;
    
    if (is_delim(input[i]))
    {
        start = i + 1;
        delim = input[i];
        while (input[i] != delim)
            i++;
        end = i - 1;
        str = ft_strjoin(str, ft_substr(input, start, end - start));
        i++;                
    }
    
}

// TODO: cambiar el parseo hasta el espacio despues de cerrar quotes
char    *get_next_token2(char *input)
{
    int     i;
    char    quote;

    i = 0;
    if (!input)
        return (NULL);
    while (input[i] && input[i] != ' ')
    {
        if (is_quote(input[i]))
        {
            quote = input[i];
            i++;
            while (input[i] != quote)
                i++;
        }
        i++;
    }
    return (ft_substr(input, 0, i));
}

