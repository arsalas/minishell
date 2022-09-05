/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/09/05 19:00:07 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

//EXIT
void	ft_exit(char **str);
int		ft_its_not_digit(char *str, int len);
int		ft_after_exit(char *str, int count);
int		ft_empty_piece(char *str, int count);
void	ft_make_exit(void);

//CD
void	ft_cd(char *input);
void	ft_parse_cd(char *input);
bool	ft_look_for_old(char *words);
int		ft_no_more_data(char **words);
bool	ft_get_home_dir(char *words);
void	ft_go_home(void);
int		ft_change_pos(char *path);
void	ft_can_go(char *path);
int		ft_cant_go(char *path);
bool	ft_look_for_home(char **words);
int		ft_set_directory(char *words);

void	pwd(void);
void	ft_env(void);
void	ft_export(char *input);
void	ft_unset(char **tokens);
void	ft_others(char *path);
void	ft_echo(char *input);
bool	ft_look_for_root(char *words);

bool	ft_export_alone(char *input);

// OTHERS
bool	is_path(char *str);

#endif