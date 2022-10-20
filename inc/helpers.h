/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/10/20 16:38:11 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "minishell.h"

void	ft_free_split(char **words);
// char	*ft_join(char **elements, char c);
char	**ft_split_words(char *str);
bool	ft_strcmp(const char *s1, const char *s2, bool strict);
void	*ft_realloc(void *ptr, size_t size);
char	*ft_strcpy(const char *s1);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_trim(char *str);
char	**ft_split_quotes(char const *s, char delimiter);
char	*ft_strjoin_four(char *s1, char *s2, char *s3, char *s4);

#endif