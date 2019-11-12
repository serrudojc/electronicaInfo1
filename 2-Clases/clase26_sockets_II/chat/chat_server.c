#include "funciones.h"

int main(int ac, char *av[]){
    	int ssock;             		// -- Descriptor del socket del servidor --
	int csock;			// -- Descriptor del socket del cliente --	
    	struct sockaddr_in cl_addr;	// -- Direccion del cliente --
    	unsigned int len;		// -- Size de la direccion --
	int pfds[2];			// -- Pipe --
	int pid;			// -- Process ID --
    	char buf[LEN];			// -- Buffer Auxiliar --
	nodo_t *p=NULL;			// -- Puntero a la cabeza de la lista de hijos --
	int error;			// -- Variables para chequeo de errores --
	int rd;				// -- Variable para lectura --
	int flags;			// -- Variable para gestion de flags de los sockets --
	sockdata_t auxdata;		// -- Estructura Auxiliar para gestion de sockets --
	
    	// verifica los argumentos de la linea de comandos
    	if(ac !=2){
    		printf("invocar %s <port_donde_servir>\n", av[0]);
		return -1;
	}

	// -- Inicia un servidor TCP y devuelve el socket asociado --
	// -- Escucha en todas las direcciones en el puerto indicado --
    	ssock = open_tcp_server(atoi(av[1]));

	// -- Seteo flag para que el accept no sea bloqueante --
	flags = fcntl(ssock, F_GETFL, 0);
	fcntl(ssock, F_SETFL, flags | O_NONBLOCK);
	
  	while(1){
		
		// acepta la conexion entrante
        	len = sizeof(cl_addr);
	    	csock = accept(ssock, (struct sockaddr *)&cl_addr, &len);
		
		// -- Si acepte una nueva conexion la atiendo --
		if(csock>0){
			// -- Me creo un pipe para comunicarme con el proceso --
			if (pipe(pfds) == -1){
                		perror("error en pipe");
                		exit(1);
        		}
			// -- Seteo flag para que los reads no sean bloqueantes --
			flags = fcntl(csock, F_GETFL, 0);
			fcntl(csock, F_SETFL, flags | O_NONBLOCK);
			
			// -- Informo quien se conectó --
        		printf(" Conectado desde %s ...\n", inet_ntoa(cl_addr.sin_addr));

			// -- Creo un proceso que lo atienda --
			if(!(pid=fork())){
        			while(1){
					error = 0;
					// -- Checkeo si el socket sigue abierto, sino me muero --
					socklen_t len = sizeof (error);
					getsockopt (csock, SOL_SOCKET, SO_ERROR, &error, &len);
            			
					if (error != 0) {
    						/* socket has a non zero error status */
			    			fprintf(stderr, "Cliente Desconectado: %s\n", inet_ntoa(cl_addr.sin_addr));
						exit(0);
					}
					if((rd=read(pfds[0], buf, LEN))){
						write(csock, buf, LEN);   // envia mensaje
					}
					sleep(1);
        			}
			}
			
			auxdata.pid=pid;
			auxdata.pfds[0]=pfds[0];	
			auxdata.pfds[1]=pfds[1];	
			auxdata.csock=csock;
			if(insertar_nodo(&p, auxdata))
				puts("No se pudo insertar");
		}
		
		enviar_mensajes(p);
		sleep(1);
    	}

    // cierra el socket del servidor
    close(ssock);
	return 0;
}
