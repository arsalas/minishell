#include "minishell.h"

void test_pwd(void)
{
    printf(RED"Test pwd:\n"RESET);
    chdir("../");
    cmd_pwd();
}

void test_env(void)
{
    printf(RED"Test env:\n"RESET);
    b_env();
    printf(RED"Test addenv TEST=test:\n"RESET);
    push_env("TEST", "test");
    b_env();
    printf(RED"Test deleteenv TEST=test:\n"RESET);
    delete_env("TEST");
    b_env();
}