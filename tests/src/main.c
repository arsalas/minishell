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



    // printf("%s\n", extract_content_input("echo > gd.txt"));
    // get_redirect_quantity("echo > gd.txt") == 1 ? printf(GRN"OK\n") : printf(RED"OK\n");
    // get_redirect_quantity("echo \\> gd.txt") == 0 ? printf(GRN"OK\n") : printf(RED"OK\n");
    // get_redirect_quantity("echo >> gd.txt") == 1 ? printf(GRN"OK\n") : printf(RED"OK\n");
    // printf("%s\n", get_input_redirect("echo holacaracola > gd.txt"));
    // printf("%s\n", get_input_redirect("echo holacaracola \\> gd.txt"));
    // printf("%s\n", get_input_redirect("echo holacaracola \">\" gd.txt"));
    // printf("%s\n", get_input_redirect("'echo holacaracola \\'>\\' gd.txt'"));
    // input = ft_get_input();
    // if (input[cont] == '>' && input[cont + 1] == ' ')
    // {
    //     fd1 = open("/System/Volumes/Data/sgoinfre/Perso/amurcia-/minishell/prueba.txt", O_CREAT | O_RDWR | O_APPEND, 0666);
    //     ft_putstr_fd("hello", 2);
    //     close (fd1);
    // }
    // char **arr = ft_split_quotes("\"Hola mundo\" Chao mundo'", ' ');
    g_minishell = get_memory(sizeof(t_minishell), true);
	g_minishell->last_command = C_OTHERS;
	g_minishell->process.quantity = 0;
	g_minishell->memory.quantity = 0;
	init_env(envp);    
    // char **arr = ft_split_quotes("\"Hola $USER\" Chao '$USER' $USER $?", ' ');
    // int i = 0;
    // while (arr[i])
    // {
    //     printf("str_%i -> %s\n", i, arr[i]);
    //     i++;
    // }

    // char *str = get_next_token2("'hola mundo' hola");
    // char *str = get_next_token2("$?$USER");
    // char *str = "\"'$USER'\"$9USER? Hola Mundo";
    char *str = "echo $ $&USER";
    get_tokens2(str);
    // printf("%s\n", str);
    // printf("|%s|\n", parse_token2(str));
    

    return (0);
}
