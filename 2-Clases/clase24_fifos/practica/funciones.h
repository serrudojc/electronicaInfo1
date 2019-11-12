#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct nodo_s {
	time_t timestamp;
	char patente[10];
	unsigned short int tipo;
	char direccion;
	struct nodo_s * next;
} nodo_t;

#define TAM_TRAMA 14
#define OK 0
#define ERROR 1

int recibir_trama(char * buff);

int validar_trama(char * buff);

int registrar_paso(nodo_t * L, char * trama);

void signal_paso(int signum);

char * tipo_str(char tipo);

int exportar_reporte(nodo_t * L);

