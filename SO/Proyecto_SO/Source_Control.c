#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "News.h"


news nuevaNoticia;

int main(int argc, char const *argv[])
{
    int cuantos;
    int datos;
    int crear = 0;

    if (argc != 2)
    {
        perror("\tNumero de argumentos invalidos\n");
        printf("\t[] argumento opcional \n");
        exit(0);
    }
    mode_t fifo_mode = S_IRUSR | S_IWUSR;
    int fd, bytes;
    unlink(argv[3]);
    if (mkfifo(argv[3], fifo_mode) == -1){
        perror("\t[!]Request mkfifo");
        exit(1);
    }
    do {
    if (fd = open(argv[3], O_RDONLY) == -1) {
    perror("\t[!] Error en la lectura del pipe\n");
    printf("\tSe volvera a intentar despues\n");
    sleep(3);
      } else crear = 1;
      } while (crear == 0);
      

    bytes = read(fd, &nuevaNoticia, sizeof(nuevaNoticia));
   
    cuantos = read (fd, &datos, sizeof(datos));
   if (cuantos == -1) 
  
  
 perror("proceso lector:");
 exit(1);



    char *token;
    const unsigned MAX_LENGTH = 256;
    char delimitador[] = ":";
    char buffer[MAX_LENGTH];
    char *mensaje;

    token = strtok(buffer, delimitador);
    if (token == NULL)
    {
        perror("No hay noticias seleccionadas\n");
        exit(0);
    }
    else
    {
        while (token != NULL)
        {
            if (*token == 'P')
            {
                token = strtok(NULL, delimitador);
                mensaje = token;
                printf("%s\n", mensaje);
            }
            else if (*token == 'C')
            {
                token = strtok(NULL, delimitador);
                mensaje = token;
                printf("%s\n", mensaje);
            }
            token = strtok(NULL, delimitador);
        }
    }

 do { 
         if ((fd = open(argv[3], O_WRONLY))== -1) {
            perror("\t[!] Error en la lectura del pipe\n");
            printf("\tSe volvera a intentar despues\n");
            sleep(3);        
         } else crear = 1;
      } while (crear== 0);

      readFile(argv[3]);
      printf("\tse leyo del archivo %s\n", argv[3]);
      for(int i = 0; i < buffer; i++){
        
      }

    return 0;
}
