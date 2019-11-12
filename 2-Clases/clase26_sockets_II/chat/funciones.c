#include "funciones.h"

void enviar_mensajes(nodo_t *p){
        nodo_t *aux=p, *q;
        char buf[LEN];

                while(p){
                        if((read(p->data->csock, buf, LEN))>0){
                                q=aux;
                                while(q){
                                        if(p->data->pid != q->data->pid)
                                                write (q->data->pfds[1],buf, LEN);
                                        q = q->prox;
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
        p->data->pid = auxdata.pid;
        p->data->csock = auxdata.csock;
        p->data->pfds[0] = auxdata.pfds[0];
        p->data->pfds[1] = auxdata.pfds[1];
        p->prox=NULL;

        return p;
}
