#define TAMMENSAJE 20
#define TAMNOMBRE 20
#define TAMNEW 30
#define NNOTICIAS 5
#define NTOP 2
#define NSUSCR 20
#define TRUE 1
#define FALSE 0
// Estructuras para que el suscriptor en vie el nombre del topico. 
typedef  struct data {
  char segundopipe[TAMNOMBRE];
    int pid;
    int topico;
} datap;

typedef  struct data1 {
    int pid;
    int topico;
} topicos;

// Estructura para que el o los publicadores envien noticias

typedef  struct new {
  char noticia[TAMNEW];
    int topico;
} newp;