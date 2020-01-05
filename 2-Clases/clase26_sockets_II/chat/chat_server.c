#include "funciones.h"

int main(int ac, char *av[]){
    	int ssock;             		// -- Descriptor del socket del servidor --
    	struct sockaddr_in cl_addr;	// -- Direccion del cliente --
    	unsigned int len;		// -- Size de la direccion --
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
	// -- Leo los flags actuales del socket --
	flags = fcntl(ssock, F_GETFL, 0);
	// -- Agrego flag de no bloqueo y asigno --
	fcntl(ssock, F_SETFL, flags | O_NONBLOCK);
	
  	while(1){
		
		// acepta la conexion entrante
        	len = sizeof(cl_addr);
	    	auxdata.csock = accept(ssock, (struct sockaddr *)&cl_addr, &len);
		
		// -- Si acepte una nueva conexion la atiendo --
		if(auxdata.csock>0){
			// -- Me creo dos pipes para comunicarme con el proceso --
			if (pipe(auxdata.pfds_in) == -1){
                		perror("error en pipe");
                		exit(1);
        		}
			if (pipe(auxdata.pfds_out) == -1){
                		perror("error en pipe");
                		exit(1);
        		}
			// -- Seteo flag para que los reads no sean bloqueantes --
			flags = fcntl(auxdata.csock, F_GETFL, 0);
			fcntl(auxdata.csock, F_SETFL, flags | O_NONBLOCK);
			flags = fcntl(auxdata.pfds_in[0], F_GETFL, 0);
			fcntl(auxdata.pfds_in[0], F_SETFL, flags | O_NONBLOCK);
			flags = fcntl(auxdata.pfds_out[0], F_GETFL, 0);
			fcntl(auxdata.pfds_out[0], F_SETFL, flags | O_NONBLOCK);
				
			// -- Creo un proceso que lo atienda --
			if(!(auxdata.pid=fork())){
				// -- Seteo Nombre Default --
				sprintf(auxdata.name, "Anonymous-%d", getpid());
        			while(1){
					error = 0;
					// -- Checkeo si el socket sigue abierto, sino me muero --
					socklen_t len = sizeof (error);
					getsockopt (auxdata.csock, SOL_SOCKET, SO_ERROR, &error, &len);
            			
					if (error != 0) {
    						/* socket has a non zero error status */
			    			fprintf(stderr, "Cliente Desconectado: %s\n", inet_ntoa(cl_addr.sin_addr));
						exit(0);
					}
					// -- Leo el pipe para ver si tengo que mandarle algo al cliente --
					if((rd=read(auxdata.pfds_in[0], buf, LEN))>0){
						write(auxdata.csock, buf, LEN);   // envia mensaje
					}
					// -- Leo el socket, si recibo algo lo envío al servidor --
					if((rd=read(auxdata.csock, buf, LEN))>0){
						write(auxdata.pfds_out[1], buf, LEN);   // envia mensaje
					}
					sleep(1);
        			}
			}
			
			// -- Informo quien se conectó --
			sprintf(auxdata.name, "Anonymous-%d", auxdata.pid);
        		printf(" Conectado %s desde %s ...\n", auxdata.name, inet_ntoa(cl_addr.sin_addr));
			
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
