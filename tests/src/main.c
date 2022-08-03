#include "minishell.h"
#include "test.h"

t_minishell	*g_minishell;

int main(int argc, char *argv[], char *envp[])
{
    g_minishell = get_memory(sizeof(t_minishell));
    init_env(envp);
    (void)argv;
    (void)argc;
    (void)envp;
    test_pwd();
    // test_env(envp);
    create_pipe(67, true);

    // char *str[4];
    // str[0] = "";
    // str[1] = "Hola $USER";
    // str[2] = "Mundo";
    // str[3] = NULL;
    // str[1] = NULL;
    // execve("/bin/env", str, envp);
    // execve("/bin/echo", str, envp);
    return (0);

    // printf("\n");
    // char cwd[256];
    // printf("USER: %s\n", getenv("USER"));
    // printf("ft_atoi: %i\n", ft_atoi("1000"));
    // printf("line: %s", line);
    // // F_OK flag : Used to check for existence of file.
    // // R_OK flag : Used to check for read permission bit.
    // // W_OK flag : Used to check for write permission bit.
    // // X_OK flag : Used to check for execute permission bit.
    // printf("current path: %s\n", getcwd(cwd, sizeof(cwd)));
    // printf("access: %i\n", access("./main.c", F_OK));
    // chdir("src");
    // printf("current path: %s\n", getcwd(cwd, sizeof(cwd)));
    // printf("access: %i\n", access("./main.c", F_OK));
    // return 0;
}
