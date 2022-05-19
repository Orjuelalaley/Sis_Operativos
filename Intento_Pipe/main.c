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
    mode_t fifo_mode = S_IRUSR | S_IWUSR;
    newp noti;
    int creado = 0;
    char topico = 'C';
    char topico2 = 'S';
    char *mensajes1[] = {"Biologia", "La vegetacion es exuberante", "Animales", "Zorro", "El Loro"};
    char *mensajes2[] = {"Petro", "pais en elecciones", "Fico en Medellin", "Fajardo quedo de tercero", "Pronto Elegimos"};

    if (mkfifo(argv[1], fifo_mode) == -1)
    {
        if (errno != EEXIST)
        {
            perror("code not create \n");
            return 1;
        }
    }
    printf("Abriendo el Publicador pipe...\n");
    do
    {
        int fd = open(argv[1], O_WRONLY);
        if (fd == -1)
        {
            perror("no se pudo abrir el pipe de envio\n");
            sleep(5);
            exit(0);
        }
        else
        {
            creado = 1;
            printf("Pipe abierto correctamente...\n");
        }
    }while (creado == 0);

    thenews.contenido = noticia;
    thenews.tipo = topico;

    for (int i = 0; i < NNOTICIAS; i++)
    {
        /* code */
    }
    

    if (write(fd, noticia, sizeof(noticia)) == -1)
    {
        perror("error al escribir en el pipe\n");
        return 2;
    }
    else
    {
        printf("Pipe escrito correctamente\n");
    }
    close(fd);
    printf("Pipe cerrado con exito\n");
    return 0;
}
