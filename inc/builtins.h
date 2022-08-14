/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/12 15:20:32 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	pwd(void);
void	ft_env(void);
void	ft_export(char *input);
void	unset(char *name);
void    ft_others(char *path, char**argv);
void    ft_echo(char *input);
// void	ft_look_for_flag(char *word);
// void	ft_print_the_echo(char **words);

//EXIT
void	ft_exit(char *str);
int		ft_its_not_digit(char *str, int len);
int		ft_after_exit(char *str, int count);
int		ft_empty_piece(char *str, int count);
void	ft_make_exit(char *str);

//CD
void	ft_cd(char *input);
void	ft_parse_cd(char *input);
char	*ft_old_cd(void);
char	*ft_add_home_paths(char *word);

#endif