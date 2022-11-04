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

# include "stdbool.h"

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3);
char	*ft_strjoin_four(char *s1, char *s2, char *s3, char *s4);
char	*get_prompt(void);
void	not_implemented(void);
void	memory_error(void);
void	*ft_malloc(size_t size, bool is_permanent);
void	free_memory(void);
int		create_process(void);
int		ft_skip_one_word(char *str);
int		ft_strncmp_mod(const char *s1, const char *s2, size_t n);

bool	is_quote(char c);
bool	is_scaped_char(char c);
bool	is_redirect(char c);
bool	is_doubble_redirect(char *raw, int count);

bool	is_strdigit(char *str);
char	*get_next_token2(char *input);
char	*parse_token2(char *input);
char	**get_tokens2(char *input);
bool	is_correct_tokens(char *raw);

char	*parse_double_quotes(char *input);
char	*parse_quotes_more(char *input, char aux, char *str, int start);

#endif