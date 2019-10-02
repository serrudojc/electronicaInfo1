
// estructura que contiene la informacion de un archivo mp3
typedef struct{
  char titulo[31];
  char artista[31];
  char album[31];
  char anio[5];
  char comentario[30];
  unsigned char track;
  unsigned char genero;
  }mp3data_t;

// estructura de un nodo de la lista  
typedef struct nodo{
  mp3data_t *mp3;
  struct nodo *prox;
  }nodo_t;

// -- Defines --
#define SIZETAG 3
#define TAG "TAG"
#define SIZE_INFO 128
  // codigos de error de salida de la funcion agregar_nodo 
#define ERR_OPEN -1       // error al abrir el archivo mp3
#define ERR_TAG -2        // no encontro el TAG
#define ERR_MALLOC -3     // error al hacer algun malloc
  // codigos de salida del main
#define OK 0              // todo ok              
#define ERR_PARAM -1      // cantidad de parametros insuficiente
#define ERR_LISTARDIR -2  // fallo la funcion listardir

// agrega un nodo a la lista.
// devuelve 0 si todo anduvo bien
int agregar_nodo(nodo_t **L, char *archivo_mp3);

// ordena la lista por numero de track en forma ascendente
void ordenar_lista_x_track(nodo_t **L);

// imprime la informacion de un archivo mp3
void imprimir_mp3(mp3data_t *m);

// imprime la informacion de todos los nodos de la lista
void imprimir_lista(nodo_t **L);

// libera la memoria ocupada por un nodo
void liberar_nodo(nodo_t *n);

// libera la memoria ocupada por toda la lista
void liberar_lista(nodo_t **L);
 

