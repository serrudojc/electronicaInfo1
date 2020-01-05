#include "funciones.h"

int main (void){
	int ssock;                      // -- Descriptor del socket del servidor --
	int csock;                      // -- Descriptor del socket del servidor --
	struct sockaddr_in cl_addr;     // -- Direccion del cliente --
	unsigned int len;               // -- Size de la direccion --
	char lon[3];
	char buf[100];

	ssock = open_tcp_server(TCP_PORT);
	len = sizeof(cl_addr);
        csock = accept(ssock, (struct sockaddr *)&cl_addr, &len);
	read(csock,lon, 2);
	lon[2]=0;
	printf("%d\n", atoi(lon));
	read(csock, buf, atoi(lon));
	buf[atoi(lon)]=0;
	puts(buf);
	if(!strncmp(buf,"Buenos Aires;rjzQk11FDZhMU" , atoi(lon)))
		write(csock, "OK", 2);
	else{ 
		write(csock, "ER",2);
		return -1;
	}
	buf[29]=0;
	while(1){
		read(csock, buf, 29);
		puts(buf);
		sleep(1);
	}

	return 0;
}
