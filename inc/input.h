/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:57:35 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/05 16:47:35 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

void	req_new_input(void);
int		get_quantity_process_in_input(char *input);
char	*extract_content_process_input(char *input);
char	*extract_others_process_input(char *input);
int		get_finish_process_in_input(char *input);

#endif
