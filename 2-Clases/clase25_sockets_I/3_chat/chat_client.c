#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include "../lib/info1-sockets.h"

int main(int ac, char *av[]){
    int sock;             		// descriptor del socket
    char buf[1024];				// buffer de recepcion

	// verifica los argumentos de la linea de comandos
    if(ac != 3){
        printf("invocar %s <ip_o_nombre_servidor> <puerto_servidor>\n", av[0]);
        return -1;
    }

    sock = open_tcp_client(av[1], atoi(av[2]));

    while(1){
        printf(">>> ");
        gets(buf);                          // lee mensaje del teclado
        write(sock, buf, strlen(buf)+1);    // envia mensaje
        if(!strcmp(buf, "chau!"))           // si envie "chau!", cierra la conexion
            break;
        if(!strcmp(buf, "cerrar!"))         // si envie "cerrar!", cierra la conexion
            break;

        memset(buf, 0, sizeof(buf));		// limpia el buffer para prepararlo para la recepcion
        read(sock, buf, sizeof(buf));       // lee los bytes recibidos
        printf("--- %s\n", buf);            // muestra el mensaje recibido
    }
    close(sock);							// cierra el socket

	return 0;
}
