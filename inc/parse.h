/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:48:28 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/24 17:59:42 by amurcia-         ###   ########.fr       */
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
bool        have_redirect(char *raw);
int	        get_redirect_quantity(char *raw);
t_redir_type get_redirect_type(char *raw, int number);
char        *extract_content_input(char *raw);
char        *get_filename_redirect(char *raw, int number);
void    	get_input_parsed(t_pipe *command);
char		*get_input_redirect(char *raw);

#endif