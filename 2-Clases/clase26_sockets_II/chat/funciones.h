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

#define LEN 1024
typedef struct {
        int pid;
        int csock;
        int pfds[2];
} sockdata_t;

struct nodo {
        sockdata_t * data;
        struct nodo * prox;
};
typedef struct nodo nodo_t;

nodo_t * crear_nodo (sockdata_t auxdata);
void enviar_mensajes(nodo_t *p);
int insertar_nodo (nodo_t **p, sockdata_t auxdata);
