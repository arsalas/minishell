/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:16:06 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/01 22:00:39 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strstr(const char *haystack, const char *needle);

//Comprobamos comillas
void	ft_odd_quotes(t_minishell *minishell)
{
	int	count;

	count = 0;
	while (minishell->input[count])
	{
		if (minishell->input[count] == 34
			&& (minishell->simple_quo % 2 == 0 || minishell->simple_quo == 0))
			minishell->double_quo++;
		else if (minishell->input[count] == 39
			&& (minishell->double_quo % 2 == 0 || minishell->double_quo == 0))
			minishell->simple_quo++;
		count++;
	}
	if ((minishell->double_quo > 0 && minishell->double_quo % 2 != 0)
		|| (minishell->simple_quo > 0 && minishell->simple_quo % 2 != 0))
	{
		printf("Error\nComillas no cerradas\n");
		exit (0);
	}
}

//Miramos la cantidad de comandos que tenemos
void	ft_number_pipes(t_minishell *minishell)
{
	int	count;

	count = 0;
	while (minishell->input[count])
	{
		if (minishell->input[count] == 124)
			minishell->pipe++;
		count++;
	}
	if (count > 0)
		minishell->traces = ft_split(minishell->input, '|');
}

//Miramos si tenemos flags
void	ft_count_commands(t_minishell *minishell)
{
	int	count;

	count = 0;
	while (minishell->input[count])
	{
		if (ft_strstr(minishell->input, "echo -n"))
			minishell->flag++;
		count++;
	}
}

void	ft_get_pid(t_minishell *minishell)
{
	pid_t	pid;

	pid = fork();
	if (!pid || pid < 0)
		exit (0);
	waitpid(pid, NULL, 0);
	minishell->pid = pid;
}

//INICIALIZAMOS LAS VARIABLES DE NUESTRA ESTRUCTURA MINISHELL
void	ft_init_minishell(t_minishell *minishell)
{
	minishell->pid = 0;
	minishell->pid = 0;
	minishell->input = 0;
	minishell->double_quo = 0;
	minishell->simple_quo = 0;
	minishell->pipe = 0;
}

//En caso de que solo nos hayan pasado un comando
//Miramos que comando nos han pasado. De momento solo hacemos un triste printf
void	ft_which_command(t_minishell *minishell)
{
	if (ft_strstr(minishell->input, "echo"))
		printf("echo\n");
	else if (ft_strstr(minishell->input, "cd"))
		printf("cd\n");
	else if (ft_strstr(minishell->input, "pwd"))
		printf("pwd\n");
	else if (ft_strstr(minishell->input, "export"))
		printf("export\n");
	else if (ft_strstr(minishell->input, "unset"))
		printf("unset\n");
	else if (ft_strstr(minishell->input, "env"))
		printf("env\n");
	else if (ft_strstr(minishell->input, "exit"))
		printf("exit\n");
}

//En caso de que nos hayan pasado mas de un comando con pipes
void	ft_command_in_pipe(t_minishell *minishell)
{
	int	count;

	count = 0;
	while (minishell->traces[count])
	{
		if (ft_strstr(minishell->traces[count], "echo"))
			printf("echo\n");
		else if (ft_strstr(minishell->traces[count], "cd"))
			printf("cd\n");
		else if (ft_strstr(minishell->traces[count], "pwd"))
			printf("pwd\n");
		else if (ft_strstr(minishell->traces[count], "export"))
			printf("export\n");
		else if (ft_strstr(minishell->traces[count], "unset"))
			printf("unset\n");
		else if (ft_strstr(minishell->traces[count], "env"))
			printf("env\n");
		else if (ft_strstr(minishell->traces[count], "exit"))
			printf("exit\n");
		count++;
	}
}

/*
* COSAS QUE ESTAN MAL:
* 1. Solamente miro que este la palabra echo, no que antes y despues tenga un espacio, o sea inicio o final de linea. nomecho tambien cuenta como echo
* 2. Hay que mirar si el flag que hay despues de echo no es "echo -nono". Mismo caso que el punto 1
*/
void	ft_parse(t_minishell *minishell)
{
	ft_init_minishell(minishell);
	ft_get_pid(minishell);
	while (1)
	{
		minishell->input = readline("minishell");
		ft_odd_quotes(minishell);
		ft_number_pipes(minishell);
		ft_count_commands(minishell);
		if (minishell->pipe == 0)
			ft_which_command(minishell);
		if (minishell->pipe > 0)
			ft_command_in_pipe(minishell);
	}
}
