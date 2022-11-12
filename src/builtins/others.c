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
	env = ft_malloc(sizeof(char) * g_minishell->env.count + 1, true);
	env[g_minishell->env.count] = NULL;
	while (i < g_minishell->env.count)
	{
		len = (ft_strlen(g_minishell->env.vars[i].title)
				+ ft_strlen(g_minishell->env.vars[i].content));
		env[i] = ft_malloc(sizeof(char) * len + 1, true);
		env[i] = ft_strjoin_three(g_minishell->env.vars[i].title,
				"=", g_minishell->env.vars[i].content);
		i++;
	}
}

bool	access_others(char *absolute_path)
{
	if (!is_path(absolute_path))
	{
		printf("%s: command not found\n", absolute_path);
		g_minishell->status = CN_FOUND;
		return (true);
	}
	if (access(absolute_path, F_OK) == -1)
	{
		printf("%s: No such file or directory\n", absolute_path);
		g_minishell->status = CN_FOUND;
		return (true);
	}
	if (access(absolute_path, X_OK) == -1)
	{
		printf("permission denied: %s\n", absolute_path);
		g_minishell->status = GENERAL;
		return (true);
	}
	return (false);
}

/**
 * @brief Ejecuta un programa
 * 
 * @param path 
 */
void	ft_others(char **tokens)
{
	char	*absolute_path;
	char	*aux;

	g_minishell->status = DEFAULT;
	aux = get_valid_path(tokens[0]);
	if (aux)
	{
		absolute_path = ft_strjoin_three(aux, "/", tokens[0]);
		free(aux);
	}
	else
		absolute_path = tokens[0];
	if (access_others(absolute_path))
		return ;
	execve(absolute_path, tokens, get_env_arr());
	ft_free_split(tokens);
}
