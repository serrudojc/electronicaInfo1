#include <sys/types.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include "./lib/info1-sockets.h"

typedef struct {
	char consumo[20];
	char fecha[11];
	char hora[9];
} data_t;

#define OK 0
#define ERR_AUTH 1
#define ERR_FILE 2
#define TCP_PORT 8877
#define FILE_CIUDADES "ciudades.txt"

int autenticar_estacion (int csock, FILE *fd);
int validar_trama (FILE *fd, char * trama);
void enviar_ok (int csock);
data_t * leer_dato (data_t *p, int csock);
int salvar_datos (char *ciudad, data_t *p);
void signal_handler (int sigint);
