/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:24:05 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/01 13:16:48 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_create_tokens(minishell)
// {
// 	minishell->tokens = (char **)malloc(sizeof(char *) * (minishell->separator + minishell->phrases + 1));
// }

// //AQUI CONTAMOS SI HAY ALGO ENTRE SEPARADORES
// void	ft_is_token(t_minishell *minishell)
// {
// 	int	count;

// 	count = 0;
// 	while (minishell->input[count])
// 	{
// 		if ((ft_is_alpha(minishell->input[count]) == 1 && ft_is_separator(minishell->input[count + 1]) == 1)
// 			|| (ft_is_alpha(minishell->input[count]) == 1 && minishell->input[count + 1] = NULL))
// 		{
// 			minishell->phrases++;
// 			count++;
// 		}
// 		count++;
// 	}
// }

// //UN TOKEN ES TODO AQUELLO SEPARADO POR SEPPARADORES Y LOS PROPIOS SEPARADORES
// //AQUI CONTAMOS LA CANTIDAD DE SEPARADORES
// int	ft_is_separator(t_minishell *minishell)
// {
// 	if (minishell->input[count] == 60 && minishell->input[count + 1] == 60)
// 	{
// 		minishell->separator++;
// 		return (1);
// 	}
// 	else if (minishell->input[count] == 62 && minishell->input[count + 1] == 62)
// 	{
// 		minishell->separator++;
// 		return (1);
// 	}
// 	else if (minishell->input[count] == 124 && minishell->input[count + 1] == 124)
// 	{
// 		minishell->separator++;
// 		return (1);
// 	}
// 	else if (minishell->input[count] == 60 || minishell->input[count] == 62 || minishell->input[count] == 124)
// 	{
// 		minishell->separator++;
// 		return (1);
// 	}
// 	return (0);
// }

// //CONTAMOS COMILLAS DOBLES Y SIMPLES
// void	ft_parsing_quotes(t_minishell *minishell)
// {
// 	int	count;

// 	count = 0;
// 	while (minishell->input[count])
// 	{
// 		if (minishell->input[count] == 34)
// 			minishell->double_quo++;
// 		else if (minishell->input[count] == 39)
// 			minishell->simple_quo++;
// 		count++;
// 	}
// 	if ((info->double_quo > 0 && minishell->double_quo % 2 != 0)
// 		|| info->simple_quo > 0 && minishell->simple_quo % 2 != 0)
// 	{
// 		printf("Error\n Comillas no cerradas\n");
// 		exit (0);
// 	}
// 	ft_is_separator(minishell);
// 	ft_is_alpha(minishell->input);
// 	ft_create_tokens(minishell);
// }

// //FORK CREA UN PROCESO HIJO QUE SE EJECUTA SIMULTANEAMENTE EN EL PROCESO QUE REALIZA LA LLAMADA
// //FORK DEVELVE UNA VARIABLE DEL TIPO PID_T
// //WAITPID ESPERA UN CAMBIO DE ESTADO EN EL PROCESO HIJO
// void	ft_get_pid(t_minishell *minishell)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (!pid || pid < 0)
// 	{
// 		printf("ERROR\n");
// 		exit (0);
// 	}
// 	waitpid(pid, NULL, 0);
// 	minishell->pid = pid;
// }

// //INICIALIZAMOS LAS VARIABLES DE NUESTRA ESTRUCTURA MINISHELL
// void	ft_init_minishell(t_minishell *minishell)
// {
// 	minishell->tokens = 0;
// 	minishell->pid = 0;
// 	minishell->input = 0;
// 	minishell->line = 0;
// 	minishell->double_quo = 0;
// 	minishell->simple_quo = 0;
// 	minishell->phrases = 0;
// 	minishell->separator = 0;
// }

// //CREAMOS LA ESTRUCTURA MINISHELL Y LEEMOS DEL TERMINAL
// //PARSEAMOS AQUELLO QUE HAN ESCRITO EN EL TERMINAL
// int main(int argc, char **argv, char **env)
// {
// 	t_minishell	*minishell;
// 	char		*parsed;

// 	parsed = 0;
// 	minishell = (t_minishell)malloc(sizeof(t_minishell));
// 	if (!minishell)
// 		return (-1);
// 	ft_init_minishell(minishell);
// 	ft_get_pid(minishell);
// 	while (argc && argv)
// 	{
// 		minishell->input = readline(minishell->line);
// 		if (minishell->input)
// 		{
// 			parsed = ft_parsing_quotes(minishell);
// 		}
// 	}
//     printf("Minishell not implemented yet\n");
//     return 0;
// }

int main(void)
{
	/* code */
	return 0;
}
