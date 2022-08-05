/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:36:59 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/05 18:50:59 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_count_words(char const *s, char space, char tab)
{
	size_t	cont;
	size_t	word;

	cont = 0;
	word = 0;
	while (s[cont])
	{
		if ((s[cont] != space && s[cont] != tab) && ((s[cont + 1] != space && s[cont + 1] != tab) || s[cont + 1] == '\0'))
			word++;
		cont++;
	}
	return (word);
}

static void	ft_free(char **d, size_t cont_d)
{
	while (cont_d > 0)
	{
		cont_d--;
		free(d[cont_d]);
	}
	free(d);
}

static char	**ft_refile(char const *s, char space, char tab, char **d)
{
	size_t	cont;
	size_t	start;
	size_t	cont_d;

	cont = 0;
	start = 0;
	cont_d = 0;
	while (s[cont])
	{
		if ((s[cont] == space || s[cont] == tab) && ((s[cont + 1] != space || s[cont + 1] != tab)))
			start = cont + 1;
		if ((s[cont] == space || s[cont] == tab) && ((s[cont + 1] == space || s[cont + 1] == tab) || s[cont + 1] == '\0'))
		{
			d[cont_d] = ft_substr(s, start, cont - start + 1);
			if (!d[cont_d])
			{
				ft_free(d, cont_d);
				return (NULL);
			}
			cont_d++;
		}
		cont++;
	}
	d[cont_d] = NULL;
	return (d);
}

char	**ft_split_tab(char const *s)
{
	char	**d;
	size_t	words;
    char    space;
    char    tab;

    space = 32;
    tab = 9;
	words = ft_count_words(s, space, tab);
	d = malloc(sizeof(char *) * (words + 1));
	if (!d || !s)
		return (NULL);
	d = ft_refile(s, space, tab, d);
	return (d);
}
