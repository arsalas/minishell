#include <stdlib.h>
#include <stdio.h>

#include <readline/readline.h>
#include <readline/history.h>

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "libft.h"

#include "minishell.h"
#include <stdio.h>

int main(void)
{
	t_minishell	*minishell;

	minishell = malloc(sizeof(t_minishell));
	if (!minishell)
		return (-1);
    ft_parse(minishell);
    return (0);
}
