

#include <stdio.h>

int main(int argc, char const *argv[], char **envp)
{
    printf("ARGS\n");
    for (size_t i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    int j = 0;
    printf("ENV\n");
    while (envp[j])
    {
        printf("%s\n", envp[j]);
        j++;
    }
    return 0;
}
