/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/02 17:38:37 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

int		get_env_elements(char **env);
void	init_env(char **env);
void	complete_env_info(char **env);
void	set_env_element(int count, char *env);
int		get_title_len(char *env);
char	*get_env_title(char *env);
char	*get_env_content(char *env);
void	print_env(void);
void	push_env(char *title, char *content);
void	delete_env(char *name);

#endif