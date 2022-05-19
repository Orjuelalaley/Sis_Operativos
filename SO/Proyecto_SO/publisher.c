#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "News.h"

news nuevaNoticia;

int main(int argc, char const *argv[])
{
    int fd, bytes;
    //el primer argumento del main ingresador es el nombre del archivo para leer las noticias
    char const *filename = argv[1];
    //el segundo argumento del main ingresado es el nombre del pipe que se conecta con Source_control.c

    FILE *fp = fopen(filename, "r");
    news noticia;
    char *token;
    char *mensaje;
    mode_t fifo_mode = S_IRUSR | S_IWUSR;
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    char delimitador[] = ":";

    // validacion de argumentos
    if (argc != 3)
    {
        perror("\tNumero de argumentos invalidos\n");
        printf("\t[] argumento opcional \n");
        exit(0);
    }
    if (fp == NULL)
    {
        perror("Error: could not open file\n");
        printf("%s", filename);
        exit(0);
    }
    else
    {
        while (fgets(buffer, MAX_LENGTH, fp))
        {

            printf("%s",buffer);
        }
    }
    fclose(fp);
    return 0;
}
