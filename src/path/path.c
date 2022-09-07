/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:49:20 by aramirez          #+#    #+#             */
/*   Updated: 2022/09/07 16:43:32 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//VALIDATE
void    path_init(void)
{
    g_minishell->paths = ft_split(get_env_var("PATH"), ':');
}

char    *get_valid_path(char *command)
{
    int     i;
    char    *path;

    i = 0;
    while (g_minishell->paths[i])
    {
        path = ft_strjoin(ft_strjoin(g_minishell->paths[i], "/"), command);
        if (access(path, F_OK) == 0)
        {
            free(path);
            return (g_minishell->paths[i]);
        }
        free(path);
        i++;
    }
    return (NULL);
}