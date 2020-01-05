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

// -- Defines --
#define SIZETAG 3
#define TAG "TAG"
#define SIZE_INFO 128
