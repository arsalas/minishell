#include "minishell.h"

void test_pwd(void)
{
    printf(RED"Test pwd:\n"RESET);
    chdir("../");
    pwd();
}

void test_env(void)
{
    printf(RED"Test env:\n"RESET);
    env();
    printf(RED"Test addenv TEST=test:\n"RESET);
    push_env("TEST", "test");
    env();
    printf("a variable de entorno es %s", get_env_var("TEST"));
    printf(RED"Test deleteenv TEST=test:\n"RESET);
    delete_env("TEST");
    env();
}