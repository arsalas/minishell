/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_aux4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:05:17 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/04 20:06:55 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increment_shlvl(void)
{
	char	*lvl;
	int		lvl_i;

	lvl = get_env_var("SHLVL");
	lvl_i = ft_atoi(lvl);
	if (lvl_i < 0)
		lvl_i = 0;
	lvl_i++;
	lvl = ft_itoa(lvl_i);
	update_env_var("SHLVL", lvl);
	free (lvl);
}

void	free_all_env(void)
{
	int	i;

	i = 0;
	while (i < g_minishell->env.count)
	{
		free_env(i);
		i++;
	}
}

char	**get_env_arr(void)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_malloc(sizeof(char *) * (g_minishell->env.count + 1), true);
	arr[g_minishell->env.count] = NULL;
	while (i < g_minishell->env.count)
	{
		arr[i] = ft_strjoin_three(g_minishell->env.vars[i].title, "=",
				g_minishell->env.vars[i].content);
		i++;
	}
	return (arr);
}

/**
 * @brief Comprueba si el nombre de la variable de entorno es valido
 * a-z, A-Z, _ and 0-9
 * May NOT begin with a number
 * 
 * @param name 
 * @return boolean 
 */
bool	is_valid_env_name(char *name)
{
	int	i;

	if (!name || !(ft_isalpha(name[0]) == 1 || name[0] == '_'))
		return (false);
	i = 1;
	while (name[i])
	{
		if (!(ft_isalnum(name[i]) == 1 || (name[i]) == '_'))
			return (false);
		i++;
	}
	return (true);
}
