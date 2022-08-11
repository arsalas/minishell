/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 15:42:17 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	pwd(void);
void	env(void);
void	export(char *name, char *content);
void	unset(char *name);
void    ft_others(char *path, char**argv);
// void	ft_look_for_flag(char *word);
// void	ft_print_the_echo(char **words);

//FILES IN BULTINGS: EXIT
void	ft_exit(char *str);

//CD
void	ft_cd(char *input);

#endif