#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    mode_t fifo_mode = S_IRUSR | S_IWUSR;
    char *abeja = "This is the first test string";

    if (mkfifo(argv[1], fifo_mode) == -1)
    {
        if (errno != EEXIST)
        {
            perror("code not create \n");
            return 1;
        }
    }
    printf("Abriendo el pipe...\n");

    int fd = open(argv[1], O_WRONLY);
    if (fd == -1)
    {
        perror("no se pudo abrir el pipe de envio\n");
        exit(0);
    }
    else{   
        printf("Pipe abierto correctamente...\n");
    }
    if (write(fd, abeja, strlen(abeja) + 1) == -1)
    {
        perror("error al escribir en el pipe\n");
        return 2;
    }else{
        printf("Pipe escrito correctamente\n");
    }
    close(fd);
    printf("Pipe cerrado con exito\n");
    return 0;
}
