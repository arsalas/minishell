/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:48:28 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/15 12:14:18 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

void		ft_parse(void);
void		ft_number_pipes(void);
void		ft_odd_quotes(char *traces);
void		ft_search_command_in_pipe(void);
t_builtins	ft_command_in_pipe(void);

int	        ft_is_empty(char *str);
t_builtins	ft_get_command(char *inside_pipes);
int			ft_is_cd(char **words);
int			ft_is_export(char **words);
int			ft_is_echo(char **words);
int			ft_is_exit(char **words);
int			ft_is_unset(char **words);
int			ft_is_env(char **words);
int			ft_is_pwd(char **words);

char        *extract_next_echo_token(char *input);
char        **parse_echo(char *input);

#endif