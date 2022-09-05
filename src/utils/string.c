/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:11:54 by aramirez          #+#    #+#             */
/*   Updated: 2022/09/06 00:41:37 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// int get_array_len(char **arr)
// {
//     int i;

//     i = 0;
//     while (arr[i])
//         i++;
//     return (i);
// }

// char    **push_string(char **arr, char *string)
// {
//     int     len;
//     char    **new_arr;

//     len = get_array_len(arr);
//     new_arr = ft_realloc(arr, len + 1);
//     return (new_arr);
// }

// bool    is_token_delim(char c)
// {
//     if (c == '\'' || c == '"' || c == '$' || c == ' ')
//         return (true);
//     return (false);
// }

// int get_finish_token(char *input, char del)
// {
//     bool    can_expand;
//     int     len;

//     can_expand = false;
//     if (del != '\'')
//         can_expand = true;
//     while (input[len] != del)
//         len++;
//     return (len);
    
// }


// char	*expand(char * token)
// {
	
// }

// char    *get_next_token(char *input, char del)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	while (!is_token_delim(input[i]))
// 		i++;
// 	str = ft_substr(input, 0, i);
// 	if (del == '$')
// 		str = expand(str);
// 	return (str);
// }

// void    ft_parse(char *input)
// {
//     int     i;
//     bool    can_expand;
// 	char	**tokens;
// 	char	*token;
// 	char	delim;

// 	tokens = get_memory(sizeof(char *), true);
//     i = 0;
// 	delim = 0;
//     can_expand = true;
//     while (input[i])
//     {
// 		token = get_next_token(&input[i], delim);
// 		push_string(tokens, token);
// 		while (!is_token_delim(input[i]))
// 			i++;
// 		if (is_token_delim(input[i]))
// 		{
// 			delim = input[i];
// 			if (input[i] == '\'')
// 				can_expand = !can_expand;
// 			while(input[i] == delim)
// 				i++;
// 		}
//     }   
// }