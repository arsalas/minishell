/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_aux2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:45:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/02 17:14:01 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Obtiene el len del nombre de la variable de entorno
 * 
 * @param env variable de entorno
 * @return int 
 */
int	get_title_len(char *env)
{
	int	len;

	len = 0;
	while (env[len] != '=')
		len++;
	return (len);
}

/**
 * @brief Obtiene el nombre de la variable de entorno
 * 
 * @param env variable de entorno
 * @return nombre
 */
char	*get_env_title(char *env)
{
	int	title_len;

	title_len = get_title_len(env);
	return (ft_substr(env, 0, title_len));
}

/**
 * @brief Obtiene el contenido de la variable de entorno
 * 
 * @param env variable de entorno
 * @return contenido
 */
char	*get_env_content(char *env)
{
	int	title_len;

	title_len = get_title_len(env) + 1;
	return (ft_substr(env, title_len, ft_strlen(env) - title_len));
}

/**
 * @brief Printa las variables de entorno
 * 
 */
void	print_env(void)
{
	int	i;

	i = 0;
	while (i < g_minishell->env.count)
	{
		printf("%s=%s\n", g_minishell->env.vars[i].title,
			g_minishell->env.vars[i].content);
		i++;
	}
}
