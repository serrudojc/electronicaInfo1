#include "funciones.h"

void enviar_mensajes(nodo_t *p){
        nodo_t *aux=p, *q;
        char buf[LEN];
	char send[LEN];
	
		// -- Recorro la lista de hijos buscando mensajes --
                while(p){
			// -- Si recibí un mensaje de este hijo, lo reenvío a los demas --
                        if((read(p->data->pfds_out[0], buf, LEN))>0){
				// -- Si es el comando de cambio de nombre no lo reenvío y seteo la estructura --
                                if(!strncmp("name=", buf, 5)){
					strcpy(p->data->name, buf+5);		
				} else {
					q=aux;
					strcpy(send, p->data->name);
					strcat(send, " dice: ");
					strcat(send, buf);
                                	while(q){
                                        	if(p->data->pid != q->data->pid)
                                                	write (q->data->pfds_in[1],send, LEN);
                                        	q = q->prox;
                                	}
                        	}
			}
                        p=p->prox;
                }
        return;
}
int insertar_nodo (nodo_t **p, sockdata_t auxdata){
        nodo_t *aux;

        aux = crear_nodo(auxdata);
        if(!aux)
                return -1;
        aux->prox=*p;
        *p=aux;

        return 0;
}
nodo_t * crear_nodo ( sockdata_t auxdata ){
        nodo_t *p;

// -- Pido memoria para el nodo y valido --
        p = (nodo_t*) malloc (sizeof(nodo_t));
        if(!p)
                return NULL;
// -- Pido memoria para los datos y valido --
        p->data = (sockdata_t *) malloc (sizeof(sockdata_t));
        if(!(p->data))
                return NULL;
// -- Cargo los datos --
	strcpy(p->data->name, auxdata.name);
        p->data->pid = auxdata.pid;
        p->data->csock = auxdata.csock;
        p->data->pfds_in[0] = auxdata.pfds_in[0];
        p->data->pfds_in[1] = auxdata.pfds_in[1];
        p->data->pfds_out[0] = auxdata.pfds_out[0];
        p->data->pfds_out[1] = auxdata.pfds_out[1];
        p->prox=NULL;

        return p;
}
