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
    // env();
    // printf(RED"Test addenv TEST=test:\n"RESET);
    // push_env("TEST", "Esto es una variable de entorno test");
    // env();
    // printf(RED"Test modificar:\n"RESET);
    // update_env_var("TEST", "Esto es una variable de entorno test modificada");
    // env();
    // printf(GRNHB"La variable de entorno es:"RESET" %s\n", get_env_var("TEST"));
    // printf(RED"Test deleteenv TEST=test:\n"RESET);
    // delete_env("TEST");
    // env();
}