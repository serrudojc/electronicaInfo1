#define OK 0
#define ALARMA 1
#define INTERRUPCION 2

typedef struct nodo_s {
  char accion;          // Ingreso ‘I’ o Egreso ‘E’
  short int puerta;     // Numero de puerta
  char cuit[20];        // CUIL del usuario
  time_t timestamp;     // Fecha y hora de la accion
  struct nodo_s * prev;		// Elemento anterior de la lista
  struct nodo_s * next;        // Siguiente elemento de la lista
} nodo_t;

typedef struct nodo_s nodo_t;

// Termina el programa
void interrupcion(int signum);

// Generador de ingresos
char * trama_acceso();