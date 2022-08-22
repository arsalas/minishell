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

int main(int argc, char *argv[], char *envp[])
{
    (void)argc;
    (void)argv;
    (void)envp;
    // char *input;
    // int fd1;
    // int cont = 1;



    printf("%i\n", have_redirect("dsfs <dgd"));
    // input = ft_get_input();
    // if (input[cont] == '>' && input[cont + 1] == ' ')
    // {
    //     fd1 = open("/System/Volumes/Data/sgoinfre/Perso/amurcia-/minishell/prueba.txt", O_CREAT | O_RDWR | O_APPEND, 0666);
    //     ft_putstr_fd("hello", 2);
    //     close (fd1);
    // }
    return (0);
}