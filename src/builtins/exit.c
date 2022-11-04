/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:31:29 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 20:46:44 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Saber si la estructura del exit es correcta
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool	is_correct_structure_exit(char **str)
{
	if (str[1] == NULL)
		return (true);
	if (str[1][0] == '-' && is_strdigit(&str[1][1]))
		return (true);
	if (!is_strdigit(str[1]))
		return (false);
	if (str[2] != NULL)
		return (false);
	return (true);
}

/**
 * @brief 
 * 
 * @param str 
 * @return true si tiene que hacer exit
 * @return false no tiene que hacer exit
 */
bool	manage_errors_exit(char **str)
{
	if (!is_strdigit(str[1]))
	{
		printf("exit: %s: numeric argument required\n", str[1]);
		g_minishell->status = OUT_RANGE;
		return (true);
	}
	printf("exit: too many arguments\n");
	g_minishell->status = GENERAL;
	return (false);
}

/*
* Realizamos la funcion exit
*/
void	ft_make_exit(void)
{
	printf("exit\n");
	close_minishell(g_minishell->status);
}

/**
 * @brief Obtiene el codigo de error a partir 
 * del codigo introducido por el usuario
 * 
 * @param code_s 
 * @return int 
 */
int	get_exit_code(char *code_s)
{
	int	code;

	code = ft_atoi(code_s);
	if (code < 0)
		code *= -255;
	return (code % 256);
}

void	ft_exit(char **str)
{
	bool	is_exit;

	is_exit = true;
	if (!is_correct_structure_exit(str))
		is_exit = manage_errors_exit(str);
	else
	{
		if (str[1])
			g_minishell->status = get_exit_code(str[1]);
		else
			g_minishell->status = GENERAL;
	}
	ft_free_split(str);
	if (is_exit)
		ft_make_exit();
}
