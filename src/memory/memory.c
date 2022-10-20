/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:57:45 by aramirez          #+#    #+#             */
/*   Updated: 2022/10/20 18:45:37 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_memory(void *pnt)
{
	g_minishell->memory.quantity++;
	g_minishell->memory.memory = ft_realloc(g_minishell->memory.memory,
			sizeof(void *) * (g_minishell->memory.quantity));
	g_minishell->memory.memory[g_minishell->memory.quantity - 1] = pnt;
}

/**
 * @brief Reserva memoria
 * 
 * @param size Memoria a reservar
 * @return void* puntero a la memoria reservada
 */
void	*ft_malloc(size_t size, bool is_permanent)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		memory_error();
	if (!is_permanent)
		add_memory(mem);
	return (mem);
}

/**
 * @brief Reasigna un espacio de memoria
 * 
 * @param ptr puntero con la memoria reservada
 * @param size nuevo size a reservar
 * @return void* nuevo puntero con la memoria reasignada
 */
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (ft_malloc(size, true));
	if (!size)
		return (ptr);
	new_ptr = ft_malloc(size, true);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

/**
 * @brief Libera toda la memoria reservada
 * Falta hacer free de g_minishell->traces
 */
//VALIDATE
void	free_memory(void)
{
	int	i;
	int	j;

	i = g_minishell->memory.quantity - 1;
	while (i >= 0)
	{
		free(g_minishell->memory.memory[i]);
		i--;
	}
	// LIBERAMOS T_PROCESS
	//DENTRO DE PROCESS HAY T_PIPE
	i = g_minishell->process.quantity -1;
	while (i >= 0)
	{
		free(g_minishell->process.content[i].raw);
		free(g_minishell->process.content[i].input);
		j = g_minishell->process.content[i].redirs.quantity - 1;
		while (j >= 0)
		{
			free(g_minishell->process.content[i].redirs.info[j].files);
			j--;
		}
		i--;
	}
	i = g_minishell->env.count -1;
	while (i >= 0)
	{
		free(g_minishell->env.vars[i].title);
		free(g_minishell->env.vars[i].content);
		i--;
	}
	if (g_minishell->input)
		free(g_minishell->input);
	if (g_minishell->traces)
		ft_free_split(g_minishell->traces);
	if (g_minishell->paths)
		ft_free_split(g_minishell->paths);
	// if (g_minishell->old_dir)
	// 	free(g_minishell->old_dir);
	// LIBERAMOS EL ARRAY DE EXPORT
	// free_all_env();
	// free(g_minishell);
}

void	ft_free_usual(void)
{
	free (g_minishell->input);
	ft_free_split(g_minishell->traces);
}
