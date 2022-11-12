/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:48:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/08/11 16:48:32 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	have_correct_format(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '=' && input[i - 1] != ' ')
			return (true);
		i++;
	}
	return (false);
}

int	get_finish_position(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '=')
		i++;
	return (i);
}

char	*get_export_name(char *input)
{
	int	len;
	int	start;

	start = 0;
	len = get_finish_position(input);
	return (ft_substr_mod(input, start, len - start));
}

char	*get_export_content(char *input)
{
	int		len;
	int		start;
	char	*str;

	start = get_finish_position(input) + 1;
	len = ft_strlen(input);
	str = ft_substr_mod(input, start, len);
	return (str);
}

bool	exist_env_var(char *name)
{
	if (get_index_by_var(name) == -1)
		return (false);
	return (true);
}
