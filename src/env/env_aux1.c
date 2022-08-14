/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_aux1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:45:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/10 16:03:58 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Obtiene el numero de elementos de entorno
 *
 * @param env entorno
 * @return int
 */
int	get_env_elements(char **env)
{
	int	count;

	count = 0;
	while (env[count])
		count++;
	return (count);
}

/**
 * @brief Inicia las variables de entorno
 *
 * @param env
 */
void	init_env(char **env)
{
	g_minishell->env.count = get_env_elements(env);
	g_minishell->env.vars = get_memory(sizeof(t_env_details)
			* g_minishell->env.count);
	complete_env_info(env);
    push_env("OLDPWD", get_env_var("PWD"));
}

/**
 * @brief Completa la informacion del entorno
 * 
 * @param env variables de entorno
 */
void	complete_env_info(char **env)
{
	int	i;

	i = 0;
	while (i < g_minishell->env.count)
	{
		set_env_element(i, env[i]);
		i++;
	}
}

/**
 * @brief Da valor a la variable de entorno correspondiente
 * 
 * @param count posicion de la variable de entorno
 * @param env string de la variable de entorno
 */
void	set_env_element(int count, char *env)
{
	g_minishell->env.vars[count].title = get_env_title(env);
	g_minishell->env.vars[count].content = get_env_content(env);
}

/**
 * @brief Obtiene el contenido de una variable de entorno
 * 
 * @param name 
 * @return contenido de la variable 
 */
char	*get_env_var(char *name)
{
	int	i;

	i = get_index_by_var(name);
	if (i == -1)
		return ("");
	return (g_minishell->env.vars[i].content);
}
