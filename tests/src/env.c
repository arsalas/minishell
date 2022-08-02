#include "minishell.h"

void test_pwd(void)
{
    printf(RED"Test pwd:\n"RESET);
    chdir("../");
    cmd_pwd();
}

void test_env(char **envp)
{
    printf(RED"Test pwd:\n"RESET);
    cmd_env(envp);
}