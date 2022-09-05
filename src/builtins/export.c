/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:48:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 16:48:32 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	have_correct_format(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '=' && input[i - 1] != ' ')
			return (true);
		i++;
	}
	return (false);
}

static int	get_finish_position(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '=')
		i++;
	return (i);
}

static int	get_start_export(char *input)
{
	int	i;

	i = 6;
	while (input[i] == ' ')
		i++;
	return (i);
}

char	*get_export_name(char *input)
{
	int	len;
	int	start;

	start = get_start_export(input);
	len = get_finish_position(input);
	return (ft_substr(input, start, len - start));
}

static char	*get_export_content(char *input)
{
	int	len;
	int	start;

	start = get_finish_position(input) + 1;
	len = ft_strlen(input);
	return (ft_substr(input, start, len));
}

bool	exist_env_var(char *name)
{
	if (get_index_by_var(name) == -1)
		return (false);
	return (true);
}

/**
 * @brief Crea una nueva variable de entorno
 * 
 * @param name 
 * @param content 
 */
void	ft_export(char *input)
{
	char	*name;
	char	*content;

	g_minishell->status = DEFAULT;
	if (ft_export_alone(input))
		return ;
	if (!have_correct_format(input))
		return ;
	name = get_export_name(input);
	if (!is_valid_env_name(name))
	{
		printf("export: not an identifier: %s\n", name);
		free(name);
		return ;
	}
	content = get_export_content(input);
	if (exist_env_var(name))
		update_env_var(name, content);
	else
		push_env(name, content);
	free(name);
	free(content);
}

/**
 * @brief Ordenamos en orden alfabetico un array de chars
 * 
 * @param environ
 */
char **ft_sort_array(char **array, int size)
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
		environ[i] = ft_strjoin(ft_strjoin(ft_strjoin(g_minishell->env.vars[i].title, "="), "\""), g_minishell->env.vars[i].content);
		i++;
	}
	return (environ);
}

/**
 * @brief Nos pasan EXPORT sin nada mas, hay que añadir declare -x
 *			lista todas las variables exportadas
 * 
 * @param environ
 */
bool	ft_export_alone(char *input)
{
	int		i;
	char	**environ;

	i = 0;
	environ = malloc(sizeof(char *) * g_minishell->env.count + 1);
	environ[g_minishell->env.count] = NULL;
	i = ft_skip_one_word(input);
	if (input[i] == '\0')
	{
		environ = ft_create_environ(environ);
		environ = ft_sort_array(environ, g_minishell->env.count);
		i = 0;
		while (i < g_minishell->env.count - 1)
		{
			printf("declare -x ");
			printf("%s", environ[i]);
			printf("\"\n");
			i++;
		}
		ft_free_split(environ);
		return (true);
	}
	free (environ);
	return (false);
}
