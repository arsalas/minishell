/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 14:10:33 by aramirez         ###   ########.fr       */
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
char	*get_env_var(char *name);
int		get_index_by_var(char *name);
void	update_env_var(char *name, char *content);
void	free_all_env(void);
char	*expand_env_vars(char *str);
char	*get_export_name(char *input);
void	increment_shlvl(void);
bool	is_valid_env_name(char *name);
char	**get_env_arr(void);
void	free_env(int position);

#endif