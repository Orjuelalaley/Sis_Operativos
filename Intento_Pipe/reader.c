#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "nom.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        perror("Numero de argumentos invalidos");
        exit(0);
    }
    int rc;
    newp noti;
    printf("Abriendo el pipe del publicador...\n");
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("no se pudo abrir el pipe de envio\n");
        return 1;
    }
    else
    {
        printf("Pipe abierto correctamente...\n");
    }

    do
    {
        rc = read(fd, &noti, sizeof(newp)); // recordar validar llamadas al sistema
        if (rc == 0)
        {
            printf("Lectura del pipe Publicador completada\n");
            break;
        }
        else
        {
            printf("Received data: %s\n", noti.noticia);
        }
    } while (rc > 0);
    unlink(argv[1]);
    close(fd);

    return 0;
}
