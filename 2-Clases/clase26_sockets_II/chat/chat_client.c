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
#include "./lib/info1-sockets.h"

int main(int ac, char *av[]){
    int sock;             		// descriptor del socket
    char buf_out[1024];				// buffer de recepcion
    char buf_in[1024];				// buffer de recepcion

	// verifica los argumentos de la linea de comandos
    	if(ac != 3){
        	printf("invocar %s <ip_o_nombre_servidor> <puerto_servidor>\n", av[0]);
        	return -1;
    	}

    	sock = open_tcp_client(av[1], atoi(av[2]));

	if(!fork()){
    		while(1){
        		memset(buf_out, 0, sizeof(buf_out));		// limpia el buffer para prepararlo para la recepcion
        		read(sock, buf_out, sizeof(buf_out));       // lee los bytes recibidos
        		printf("--- %s\n", buf_out);            // muestra el mensaje recibido
			sleep(1);
    		}
	}
	while(1){
		fgets(buf_in, sizeof(buf_in),stdin);
		write(sock, buf_in, 1024);
	}
    	close(sock);							// cierra el socket

	return 0;
}
