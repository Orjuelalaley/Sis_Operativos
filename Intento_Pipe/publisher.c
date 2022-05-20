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
    


    mode_t fifo_mode = S_IRUSR | S_IWUSR;
    newp noti;
    int creado = 0;
    int fd;
    char tema;
    char tema2;
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
    printf("Creando el pipe Publicador...\n");
    do
    {
        fd = open(argv[1], O_WRONLY);
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
    } while (creado == 0);

    
    

    for (int i = 0; i < NNOTICIAS; i++)
    {
        strcpy(noti.noticia, mensajes1[i]);
        tema = 'B';
        tema2 = 'P';
        noti.topico = tema;
        if (write(fd, &noti, sizeof(newp)) == -1)
        {
            
            perror("error al escribir en el pipe\n");
            return 2;
        }
        else
        {
            printf("Pipe escrito correctamente\n");
            sleep(2);
        }
        strcpy(noti.noticia, mensajes2[i]);
        noti.topico = tema2;
        if (write(fd, &noti, sizeof(newp)) == -1)
        {
            
            perror("error al escribir en el pipe\n");
            return 2;
        }
        else
        {
            printf("Pipe escrito correctamente\n");
            sleep(2);
        }
        

    }
    close(fd);
    printf("Pipe cerrado con exito\n");
    return 0;
}
