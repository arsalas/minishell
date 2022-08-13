#include "minishell.h"
#include "test.h"

t_minishell	*g_minishell;

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
    ft_init_minishell(envp);
    return (0);
}
