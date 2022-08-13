/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:48:03 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/13 20:34:17 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Printa la ruta actual
 */
void	pwd(void)
{
	char	cwd[256];

	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}
