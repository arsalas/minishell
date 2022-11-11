/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:48:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/11 17:11:21 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	export_env_var(char *token)
{
	char	*name;
	char	*content;

	if (!have_correct_format(token))
		return (true);
	name = get_export_name(token);
	if (!is_valid_env_name(name))
	{
		free(name);
		return (false);
	}
	content = get_export_content(token);
	if (exist_env_var(name))
		update_env_var(name, content);
	else
		push_env(name, content);
	free(name);
	free(content);
	return (true);
}

/**
 * @brief Crea una nueva variable de entorno
 * 
 * @param name 
 * @param content 
 */
void	ft_export(char **tokens)
{
	int		count;

	g_minishell->status = DEFAULT;
	if (tokens[1] == NULL)
	{
		export_alone();
		ft_free_split(tokens);
		return ;
	}
	count = 1;
	while (tokens[count])
	{
		if (!export_env_var(tokens[count]))
		{
			while (tokens[count])
			{
				printf("export: `%s': not a valid identifier\n", tokens[count]);
				count++;
			}
		}
		count++;
	}
	ft_free_split(tokens);
}

/**
 * @brief Ordenamos en orden alfabetico un array de chars
 * 
 * @param environ
 */
char	**ft_sort_array(char **array, int size)
{
	int		cont;
	char	*temp;

	cont = 0;
	while (array[cont + 1] && cont < size)
	{
		if (ft_strncmp_mod(array[cont], array[cont + 1], size) > 0)
		{
			temp = array[cont];
			array[cont] = array[cont + 1];
			array[cont + 1] = temp;
		}
		cont++;
	}
	cont = 0;
	while (array[cont + 1] && cont < size)
	{
		if (ft_strncmp_mod(array[cont], array[cont + 1], size) > 0)
			ft_sort_array(array, size);
		cont++;
	}
	return (array);
}

char	**ft_create_environ(char **environ)
{
	int		i;

	i = 0;
	while (i < g_minishell->env.count)
	{
		environ[i] = ft_strjoin_four(g_minishell->env.vars[i].title, "=", "\"",
				g_minishell->env.vars[i].content);
		i++;
	}
	return (environ);
}

/**
 * @brief Nos pasan EXPORT sin nada mas, hay que añadir declare -x
 *			y lista todas las variables exportadas
 * 
 * @param environ
 */
void	export_alone(void)
{
	int		i;
	char	**environ;

	environ = malloc(sizeof(char *) * g_minishell->env.count + 1);
	environ[g_minishell->env.count] = NULL;
	environ = ft_create_environ(environ);
	environ = ft_sort_array(environ, g_minishell->env.count);
	i = 0;
	while (i < g_minishell->env.count)
	{
		printf("declare -x %s\"\n", environ[i]);
		i++;
	}
	ft_free_split(environ);
}
