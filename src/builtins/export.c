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

	if (ft_export_alone(input))
		return ;
	if (!have_correct_format(input))
		return ;
	name = get_export_name(input);
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
	environ = malloc(sizeof(char) * g_minishell->env.count + 1);
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
		return (true);
	}
	return (false);
}
/*
bool	ft_export_alone(char *input)
{
	int		i;
	int		len;
	char	**environ;

	i = 0;
	len = ft_strlen(g_minishell->env.vars[i].title)
		+ ft_strlen(g_minishell->env.vars[i].content) + 11;
	environ = malloc(sizeof(char) * g_minishell->env.count + 1);
	environ[g_minishell->env.count] = NULL;
	i = ft_skip_one_word(input);
	if (input[i] == '\0')
	{
		i = 0;
		while (i < g_minishell->env.count)
		{
			environ[i] = malloc(sizeof(char) * len + 1);
			environ[i] = ft_strjoin_three("declare -x ", g_minishell->env.vars[i].title, "=");
			environ[i] = ft_strjoin_three(environ[i], "\"", g_minishell->env.vars[i].content);
			environ[i] = ft_strjoin(environ[i], "\"");
			i++;
		}
		environ = ft_sort_array(environ, g_minishell->env.count);
		i = 2;
		while (i < g_minishell->env.count - 1)
		{
			printf("%s\n", environ[i]);
			i++;
		}
		return (true);
	}
	return (false);
}*/

/*
int	ft_end_export(int start, char *word)
{
	int	count;

	count = 0;
	while (word[start] != '\0' && word[start] != ' ' && word[start] != '\t' && word[start] != '\n')
	{
		start++;
		count++;
	}
	return (count);
}

int	ft_start_export(char *word)
{
	int	count;

	count = 0;
	printf("WORD IS %s\n", word);
	while (word[count] != '\0' && (word[count] == ' ' || word[count] == '\t' || word[count] == '\n'))
		count++;
	count += +6;
	while (word[count] != '\0' && (word[count] == ' ' || word[count] == '\t' || word[count] == '\n'))
		count++;
	return (count);
}

void	ft_equal_error(char *words)
{
	int	count;
	int	equal;

	count = 0;
	equal = 0;
	while (words[count])
	{
		if (words[count] == '=')
			equal++;
		count++;
	}
	if (equal != 1)
	{
		printf("ERROR\nVARIABLE NO ASIGNADA\n");
		close_minishell();
	}
}

void	ft_save_the_export(t_minishell *minishell, char *words, int start, int len)
{
	int		count;

	count = 0;
	minishell->prev = (char *)malloc((sizeof(char) * len + 1));
	minishell->post = (char *)malloc((sizeof(char) * len + 1));
	while (words[start] && words[start] != '=')
	{
		minishell->prev[count] = words[start];
		start++;
		count++;
	}
	minishell->prev[count] = '\0';
	if (words[start] == '=')
		start++;

	count = 0;
	while (words[start] && (words[start] != ' ' && words[start] != '\n' && words[start] != '\t'))
	{
		minishell->post[count] = words[start];
		start++;
		count++;
	}
	minishell->post[count] = '\0';
	printf("VAR IS %s\n", minishell->prev);
	printf("THE NAME OF THE VAR IS %s\n", minishell->post);
}

void	ft_make_export(t_minishell *minishell, char *inside_pipes)
{
	int	start;
	int	len;

	ft_odd_quotes(minishell, inside_pipes);
	ft_quotes_error(minishell, inside_pipes);
	ft_equal_error(inside_pipes);
	start = ft_start_export(inside_pipes);
	len = ft_end_export(start, inside_pipes);
	ft_save_the_export(minishell, inside_pipes, start, len);
}
*/