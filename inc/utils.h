/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 18:49:18 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	print_prompt(void);
void	not_implemented(void);
void	memory_error(void);
void	*get_memory(size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	free_memory(void);
int		create_process(void);

char	**ft_split_words(char *str);
void	ft_free_split(char **words);
bool	ft_strcmp(const char *s1, const char *s2);
char	*ft_strstr(const char *haystack, const char *needle);

#endif