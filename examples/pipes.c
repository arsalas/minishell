#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define READ_END 0  /* index pipe extremo escritura */
#define WRITE_END 1 /* index pipe extremo lectura */

int main(int argc, char *argv[])
{
    int fd1[2], fd2[2];
    int status, pid;

    pipe(fd1); /* comunica ls y grep */

    pid = fork();

    if (pid == 0) /* hijo 1*/
    {
        // Cerramos el fd de lectura en el hijo
        close(fd1[READ_END]); /* cerrar extremo no necesario */
        // Pasamos el fd de escritura al stdout
        dup2(fd1[WRITE_END], STDOUT_FILENO);
        // Cerramos el fd de escritura en el hijo
        close(fd1[WRITE_END]);

        execlp("/bin/ls", "ls", "-l", NULL);
    }
    else /* padre */
    {
        // Cerramos el fd de escritura en el padre
        close(fd1[WRITE_END]); /* extremo no necesario ya */

        // Creamos un nuevo pipe parar comunicar el segundo proceso con el tercero
        pipe(fd2); /* comunica grep y wc */
        pid = fork();

        if (pid == 0) /* hijo 2 */
        {
            // Cerramos el fd de lectura en el hijo
            close(fd2[READ_END]); /* cerrar extremo no necesario */
            // Pasamos el fd de escritura del segundo proceso al stdin
            dup2(fd1[READ_END], STDIN_FILENO);
            // Cerramos el fd de lectura del primer proceso
            close(fd1[READ_END]);
            // Pasamos el fd de escritura del tercer proceso al stdout
            dup2(fd2[WRITE_END], STDOUT_FILENO);
            close(fd2[WRITE_END]);

            execlp("/bin/grep", "grep", "u", NULL);
        }
        else /* padre */
        {
            // Cerramos la lectura del primer pipe y la escritura del segundo pipe
            close(fd1[READ_END]);  /* cerrar extremo no necesario */
            close(fd2[WRITE_END]); /* cerrar extremo no necesario */

            pid = fork();

            if (pid == 0) /* hijo 3*/
            {
                // Pasamos el fd read del segundo pipe al stdin
                dup2(fd2[READ_END], STDIN_FILENO);
                // Cerramos el fd de lectura del segundo pipe
                close(fd2[READ_END]);

                execlp("/usr/bin/wc", "wc", "-l", NULL);
            }
        }
    }

    close(fd2[READ_END]); /* cerrar extremo que queda abierto en el padre  */

    /* wait para cada hijo */
    wait(&status);
    wait(&status);
    wait(&status);

    return 0;
}
