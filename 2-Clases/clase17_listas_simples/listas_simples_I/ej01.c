#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int dato;
	struct nodo *prox;
};
typedef struct nodo nodo_t;

//-----------------------------------
nodo_t* crear_nodo(int data);
nodo_t* agregar_nodo(nodo_t *l, nodo_t *n);
void    imprimir_lista(nodo_t *l);
void    liberar_lista(nodo_t *l);

//-----------------------------------
int main(void){
	nodo_t *lista = NULL;
	nodo_t *n = NULL;
	int d;
	while(1){
		puts("ingrese dato: ");
		scanf("%d", &d);
		printf("dato ingresado: %d\n", d);
		if(d==0){
			liberar_lista(lista);
			puts("chau!\n");
			return 0;
		}
		// creo el nodo
		if((n=crear_nodo(d))==NULL)
			return 1;
		// agrego nodo
		lista = agregar_nodo(lista, n);
		imprimir_lista(lista);
	}
	return 0;
}

//-----------------------------------
nodo_t* crear_nodo(int data){
	nodo_t *p;
	p = (nodo_t *)malloc(sizeof(nodo_t));
	if(p==NULL){
		puts("No pude crear el nodo\n");
		return p;
	}
	p->dato = data;
	p->prox = NULL;
	return p;
}
	
//-----------------------------------
nodo_t* agregar_nodo(nodo_t *l, nodo_t *n){
	nodo_t *lista_original = l;
	if(l==NULL) //la lista esta vacia
		return n;   		

	//no esta vacia. voy hasta el final y agrego nodo
	while(l->prox != NULL)
		l = l->prox;
	l->prox = n;
	return lista_original;
}

//-----------------------------------
void imprimir_lista(nodo_t *l){
	if(l==NULL){ 
		puts("la lista esta vacia");
		return;
	}
	printf("lista => "); 
	do{
		printf("%d ", l->dato);
		l = l->prox;
	}while(l != NULL);
	printf("\n");
}

//-----------------------------------
void liberar_lista(nodo_t *l){
	nodo_t * p;
	if(l==NULL) // la lista esta vacia no hay nada para liberar
		return;
	while(1){ 
		if(l->prox == NULL){ // es el ultimo nodo
			free(l);
			return;
		}
		p = l->prox;	// me guardo el proximo
		free(l);		// libero el actual
		l = p;			// me muevo al siguiente
	}
}	
	
	









