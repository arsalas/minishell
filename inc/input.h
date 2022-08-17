/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:57:35 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/17 16:36:27 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

void	req_new_input(void);
int		get_quantity_process_in_input(char *input);
char	*extract_content_process_input(char *input);
char	*extract_others_process_input(char *input);

#endif