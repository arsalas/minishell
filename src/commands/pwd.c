/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:48:03 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/01 19:44:40 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Printa la ruta actual
 * 
 */
void	cmd_pwd(void)
{
	char	cwd[256];

	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}
