/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:48:28 by amurcia-          #+#    #+#             */
/*   Updated: 2022/08/11 18:50:38 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

void		ft_search_command_in_pipe(void);
void		ft_number_pipes(void);
void		ft_odd_quotes(char *traces);
t_builtins	ft_command_in_pipe(void);
t_builtins	ft_get_command(char *inside_pipes);
int			ft_is_cd(char **words);
int			ft_is_export(char **words);
int			ft_is_echo(char **words);
int			ft_is_exit(char **words);
int			ft_is_unset(char **words);
int			ft_is_env(char **words);
int			ft_is_pwd(char **words);

#endif
