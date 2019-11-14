#include <stdio.h>

// definicion de las estructuras
typedef struct {
                int x;
                int y;
               } spunto_t;


// prototipos
void imprime_punto(spunto_t *p);
spunto_t *crea_punto(spunto_t *p, int x, int y);

// main
int main(void){
    spunto_t p1 = {4, 23};  // declaro una estructura usando el tipo definido con typedef
                            // y la inicializo
    spunto_t *pp1;	//declaro puntero a estructura del tipo spunto. 
    spunto_t p2, *pp2;	//si mi sistema es de 32 bits, el tamaño del puntero es siempre igual, 4 bytes

    // inicializo el puntero a la estructura
    pp1 = &p1; 	//apunta a la direccion de memoria de p1

    // imprimo los miembros de la estructura usando la estructura
    printf("x=%d, y=%d\n", p1.x, p1.y);

    // imprimo los miembros de la estructura usando el puntero a la estructura
    printf("x=%d, y=%d\n", (*pp1).x, (*pp1).y); //el contenido de lo apuntado por el puntero (*pp1).nombreMiembro

    // pero, como la construccion (*pp1). es tan comun se reemplaza por la sintaxis pp1->
    printf("x=%d, y=%d\n", pp1->x, pp1->y);	//el puntero que apunta p1 al miembro x, SOLO PARA PUNTEROS DE ESTRUCTURAS

    // inicializo una estructura pasandole un puntero.
    // Como ejemplo adicional la funcion devuelve un puntero a la estructura inicializada
    pp2 = crea_punto(&p2, 26, 69);	//pp2 es un puntero, p2 es la direccion de la estructura

    // imprime los miembros de la estructura usando el puntero
    imprime_punto(pp2); 	//imprimo pasando un puntero

    return 0;
}

// -------------------------------------------------------------------
void imprime_punto(spunto_t *p){
    printf("x=%d, y=%d\n", p->x, p->y);
}

// -------------------------------------------------------------------
spunto_t *crea_punto(spunto_t *p, int x, int y){ //le paso un puntero a una estructura (debe esxistir la estructura), le paso dos valores a inicializar
    p->x = x;
    p->y = y;
    return p;
}
