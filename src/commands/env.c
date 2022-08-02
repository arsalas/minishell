/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:31:29 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/01 19:47:56 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Obtiene el numero de elementos de entorno
 * 
 * @param env entorno
 * @return int 
 */
int get_env_elements(char **env)
{
    int count;

    count = 0;
    while(env[count])
        count++;
    return (count);
}

void	cmd_env(char **env)
{
	int elements;
    int i;

    i = 0;
    elements = get_env_elements(env);
    while (i < elements)
    {
        printf("%s\n", env[i]);
        i++;
    }
}
