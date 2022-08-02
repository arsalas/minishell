#include "minishell.h"
#include "test.h"

int main(int argc, char **argv, char *envp[])
{
   
    (void)argv;
    (void)argc;
    (void)envp;
    test_pwd();
    // test_env(envp);
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
