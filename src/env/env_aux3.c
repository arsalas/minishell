/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_aux3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:15:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/10 16:01:52 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Agrega una nueva variable de entorno
 * 
 * @param title 
 * @param content 
 */
void	push_env(char *title, char *content)
{
	g_minishell->env.count++;
	g_minishell->env.vars = ft_realloc(g_minishell->env.vars,
			sizeof(t_env_details) * g_minishell->env.count);
	g_minishell->env.vars[g_minishell->env.count - 1].title = ft_strdup(title);
	g_minishell->env.vars[g_minishell->env.count - 1].content
		= ft_strdup(content);
}

/**
 * @brief Obtiene el indice de la variable de entorno
 * 
 * @param name nombre variable de entorno
 * @return indice
 */
int	get_index_by_var(char *name)
{
	int	i;

	i = 0;
	while (i < g_minishell->env.count)
	{
		if (ft_strncmp(name, g_minishell->env.vars[i].title,
				ft_strlen(name)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Libera la memoria de un env
 * 
 * @param position 
 */
void	free_env(int position)
{
	free(g_minishell->env.vars[position].title);
	free(g_minishell->env.vars[position].content);
}

void	move_envmem(int position)
{
	int	i;

	i = position + 1;
	while (i < g_minishell->env.count)
	{
		g_minishell->env.vars[i] = g_minishell->env.vars[i - 1];
		i++;
	}
}

/**
 * @brief Elimina una variable de entorno
 * 
 * @param name nombre de la variable a eliminar
 */
void	delete_env(char *name)
{
	int	i;

	i = get_index_by_var(name);
	if (i == -1)
		return ;
	free_env(i);
	move_envmem(i);
	g_minishell->env.count--;
	g_minishell->env.vars = ft_realloc(g_minishell->env.vars,
			sizeof(t_env_details) * g_minishell->env.count);
}
