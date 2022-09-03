/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:34:47 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/12 15:24:34 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Comprueba si el string es un path valido
 * 
 * @param str path
 * @return true 
 * @return false 
 */
bool	is_path(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (true);
		i++;
	}
	return (false);
}

/**
 * @brief Crea un array en el que esta el title y el content de env
 * 
 * @param void 
 */
void	ft_env_array(void)
{
	char	**env;
	int		len;
	int		i;

	i = 0;
	env = get_memory(sizeof(char) * g_minishell->env.count + 1, true);
	env[g_minishell->env.count] = NULL;
	while (i < g_minishell->env.count)
	{
		len = (ft_strlen(g_minishell->env.vars[i].title)
				+ ft_strlen(g_minishell->env.vars[i].content));
		env[i] = get_memory(sizeof(char) * len + 1, true);
		env[i] = ft_strjoin_three(g_minishell->env.vars[i].title,
				"=", g_minishell->env.vars[i].content);
		i++;
	}
}

/**
 * @brief Ejecuta un programa
 * 
 * @param path 
 */
void	ft_others(char *path)
{
	char	**argv;
    char    *absolute_path;
    char    *aux;

	g_minishell->status = DEFAULT;
	argv = ft_split_quotes(ft_trim(path), ' ');
    aux = get_valid_path(argv[0]);
    if (aux)
    {
        absolute_path = ft_strjoin(ft_strjoin(aux, "/"), argv[0]);
        free(aux);
    }
    else
	    absolute_path = argv[0];
	if (!is_path(absolute_path))
	{
		printf("%s: command not found\n", absolute_path);
		g_minishell->status = CN_FOUND;
		return ;
	}
	if (access(absolute_path, F_OK) == -1)
	{
		printf("%s: No such file or directory\n", absolute_path);
		g_minishell->status = CN_FOUND;
		return ;
	}
	if (access(absolute_path, X_OK) == -1)
	{
		printf("permission denied: %s\n", absolute_path);
		g_minishell->status = GENERAL;
		return ;
	}
	execve(absolute_path, argv, get_env_arr());
}
