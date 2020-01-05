#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include "./lib/info1-sockets.h"

int main (void){

	int sock;               // -- Descriptor del socket --
	int r;			// -- Variable de lectura --
	int i=0;		// -- Contador --
	char buf[10];		// -- Buffer Auxiliar --
	char *auth[] = {"26Buenos Aires;rjzQk11FDZhMU","21Rosario;IjFSPTbZqAk1w"};
	char *tramas[]={"000123.22,2019-11-20,10:21:11","012345.12,2019-11-21,12:13:14","001234.56,2019-11-22,15:23:12","123456.78,2019-11-23,18:23:21"};

	// -- Abro el socket en el puerto establecido --
	sock = open_tcp_client("127.0.0.1", 8877);
	// -- Si no pude abrir el socket me voy --
	if(!sock)
		return -1;
	// -- Hago aleatoria la autenticacion para que a veces falle --
	r=rand()%2;
	write(sock, auth[0], strlen(auth[0]));
	
	// -- Me quedo esperando el OK --
	r=read(sock, buf, 2);
	
	// -- Si llego otra cosa que no sea OK me voy --
	if(r!=2)
		return -2;
	if(strncmp(buf, "OK", 2))
		return -3;

	// -- Me quedo mandando tramas cada 2 segundos --
	while(1){
		write(sock, tramas[i], strlen(tramas[i]));
		i++;
		i%=4;
		sleep(2);
	}

	return 0;
}
	
	
