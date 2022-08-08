/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:34:56 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/08 19:28:45 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_len_word(char *str, int start)
{
	while (str[start] && str[start] != ' '
		&& str[start] != '\t' && str[start] != '\n')
		start++;
	return (start);
}

static char	*ft_bidimensional(char *str, int start)
{
	int		cont;
	int		len;
	char	*word;

	cont = 0;
	len = ft_len_word(str, start);
	word = (char *)malloc(sizeof(char) * len + 1);
	while (start < len)
	{
		word[cont] = str[start];
		cont++;
		start++;
	}
	word[start] = '\0';
	return (word);
}

static char	**ft_refile(char **array, char *str)
{
	size_t	cont;
	size_t	cont_w;

	cont = 0;
	cont_w = 0;
	while (str[cont] == ' ' || str[cont] == '\t' || str[cont] == '\n')
		cont++;
	while (str[cont] != '\0')
	{
		array[cont_w] = ft_bidimensional(str, cont);
		cont_w++;
		while (str[cont] && str[cont] != ' '
			&& str[cont] != '\t' && str[cont] != '\n')
			cont++;
		while (str[cont] == ' ' || str[cont] == '\t' || str[cont] == '\n')
			cont++;
	}
	return (array);

}

static size_t	ft_count_words(char *str)
{
	size_t	words;
	size_t	cont;

	words = 0;
	cont = 0;
	while (str[cont] == ' ' || str[cont] == '\t' || str[cont] == '\n')
		cont++;
	while (str[cont])
	{
		while (str[cont] && str[cont] != ' '
			&& str[cont] != '\t' && str[cont] != '\n')
			cont++;
		while (str[cont] == ' ' || str[cont] == '\t' || str[cont] == '\n')
			cont++;
		words++;
	}
	return (words);
}

char	**ft_split_words(char *str)
{
	char	**array;
	size_t	words;

	words = ft_count_words(str);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array || !str)
		return (NULL);
	array[words] = NULL;
	array = ft_refile(array, str);
	return (array);
}
