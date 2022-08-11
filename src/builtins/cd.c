/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:31:29 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 13:45:42 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// PRIMERO vamos a mirar si despues de CD nos dan ~/
// En caso de que NO, vamos a coger el environment de HOME y lo vamos a poner desde
// la primera posicion hasta la longitud de lo que hay despues de CD
char	*ft_add_home_path(char *word)
{
	char	*path;
	char	*paths;

	if (!ft_strncmp(word, "~/", 2))
	{
		path = getenv("HOME");
		paths = ft_substr(path, 1, ft_strlen(word));
		free(word);
		word = ft_strjoin(path, paths);
		free (path);
		free (paths);
		return (word);
	}
	return (word);
}

char	*ft_old_cd(void)
{
	char	*path;

	path = getenv("OLDPWD");
	if (path == getenv("OLDPWD"))
	{
		path = getenv("PWD");
		ft_putstr_fd(path, 1);
		ft_putchar_fd('\n', 1);
		return (path);
	}
	printf("cd: OLDPWD not set");
	return (0);
}
/*
//ANADIMOS EL DIRECTORIO
void	ft_set_directory(char *input)
{
	int	home;
}*/

//SI NOS DAN ~ O -- HAY QUE BUSCAR HOME EN EL ENVIRONMENT
void	ft_cd(char *input)
{
	char	**words;
	char	*path;

	words = ft_split_words(input);
	if (!words[1])
		return ;
	if (words[1][0] == '~' || (words[1][0] == '-' && words[1][1] == '-'))
	{
		ft_putstr_fd("minishell: cd: HOME\n", 1);
		return ;
	}
	if (words[1][0] == '-')
	{
		path = ft_old_cd();
		return ;
	}
	words[1] = ft_add_home_path(words[1]);
	// ft_set_directory(input);
	// printf("words is %s\n", words[1]);
}
