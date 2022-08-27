#include "minishell.h"
#include "test.h"

t_minishell *g_minishell;
/*
int main(int argc, char *argv[], char *envp[])
{
    (void)argc;
    (void)argv;
    (void)envp;

    // chdir("../");
    // t_pipe commands[3];
    // commands[0].command = C_ECHO;
    // commands[0].content = "Primer pipe1";
    // commands[1].command = C_ECHO;
    // commands[1].content = "Segundo pipe2";
    // commands[2].command = C_ECHO;
    // commands[2].content = "Tercer pipe3";
    // // execute_pipe(3, commands);
    // test_echo();
    // printf("%s\n", ft_trim("     \t      \t           "));
    // ft_init_minishell(envp);
    // printf("pipes: %i\n", get_quantity_process_in_input("echo fsdfsd  |  echo \\' | fsdfsd"));
    // printf("%s\n", extract_next_echo_token("\'Hola Mundo $\""));
    // parse_echo("\\\"Hola Mundo \"Como estamos\"");
    // parse_echo("\"Hola Mundo\"Como estamos'Todo' Bien");
    // char *arr[] = {"System", "Volumes", "Data", "sgoinfre", "Perso", "aramirez", "minishell", NULL};
    // char *str = ft_join(arr, '/');
    // printf("%s\n", str);

    return (0);
}*/

char *ft_sort_array(void)
{
    int	cont;
	char	*temp;
    char    *array;

	cont = 0;
	while ((array[cont] <= array[cont + 1]) && (cont < size))
	{
		cont++;
	}
	if (cont == (size -1))
		return ;
	else
	{
		temp = array[cont];
		array[cont] = array[cont + 1];
		array[cont + 1] = temp;
	}
	ft_sort_array(array, size);
}

int main(int argc, char *argv[], char *envp[])
{
    (void)argc;
    (void)argv;
    (void)envp;

    ft_sort_array();
}
