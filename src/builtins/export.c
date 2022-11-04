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

char	*get_export_name(char *input)
{
	int	len;
	int	start;

	start = 0;
	len = get_finish_position(input);
	return (ft_substr_mod(input, start, len - start));
}

static char	*get_export_content(char *input)
{
	int		len;
	int		start;
	char	*str;

	start = get_finish_position(input) + 1;
	len = ft_strlen(input);
	str = ft_substr_mod(input, start, len);
	return (str);
}

bool	exist_env_var(char *name)
{
	if (get_index_by_var(name) == -1)
		return (false);
	return (true);
}

/**
 * @brief Miamos que tenga el formato correcto y que el nombre de la variable sea correcto
 * Tambien asignamos el nombre a la variable
 * 
 * @param token 
 */
// void	export_env_var(char *token)
// {
// 	char	*name;
// 	char	*content;

// 	if (!have_correct_format(token))
// 		return ;
// 	name = get_export_name(token);
// 	printf("TOKEN IS %s\n", token);
// 	printf("NAME IS %s\n", token);
// 	if (!is_valid_env_name(name))
// 	{
// 		printf("export: `%s': not a valid identifier\n", name);
// 		free(name);
// 		return ;
// 	}
// 	content = get_export_content(token);
// 	if (exist_env_var(name))
// 		update_env_var(name, content);
// 	else
// 		push_env(name, content);
// 	free(name);
// 	free(content);
// }

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
		environ[i] = ft_strjoin_four(g_minishell->env.vars[i].title, "=", "\"", g_minishell->env.vars[i].content);
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
