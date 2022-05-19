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
    char abeja[30];
    int rc;
    printf("Abriendo el pipe...\n");
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
        if (rc = read(fd, abeja, sizeof(abeja)) == -1)
        {
            perror("pipe no leido correctamente");
        }
        else
        {
            printf("Received data: %s\n", abeja);
        }

    } while (rc > 0);
    close(fd);

    return 0;
}
