#include <stdio.h>

// definicion de las estructuras
typedef struct {
                int x;
                int y;
               } spunto_t;
typedef struct {		//defino una nueva esrtuctura para contener la informacion de un rectangulo.Se define por dos puntos.
                spunto_t p1;	//mi estructura del tipo rectangulo, tiene dos estructuras del tipo punto
                spunto_t p2;
               } srectangulo_t;

// prototipos
void imprime_rectangulo (srectangulo_t *r);


// main
int main(void){

    // declaro un rectangulo e inicializo los puntos
    srectangulo_t rect1 = { {2, 5}, {7, 10} };	//inicializado a mano 
    srectangulo_t rect2;	// dos rectangulos vacios
    srectangulo_t rect3;

    spunto_t punto1 = {23, 45}; //declaro dos PUNTOS de estas coordenadas
    spunto_t punto2 = {67, 98};

    // imprimo rectangulo usando un puntero
    imprime_rectangulo(&rect1);		//recibe un puntero a una estructura de çl tipo rectangulo

    // inicializo un rectangulo inicializando cada uno de los miembros 
    rect2.p1.x = 44;		//variable del tipo struct rectangulo
    rect2.p1.y = 12;
    rect2.p2.x = 55;
    rect2.p2.y = 88;
    imprime_rectangulo(&rect2);		//le paso la direccion de comienzo

    // inicializo un rectangulo con los puntos creados anteriormente
    rect3.p1 = punto1;	//p1 lo igualo a punto1, igualo los miembros con otras estructuras que habian sido inicializadas a mano antes.
    rect3.p2 = punto2;
    imprime_rectangulo(&rect3);

    return 0;
}

// -------------------------------------------------------------------
void imprime_rectangulo(srectangulo_t *r){	//r es un puntero, que apunta a la estructura del tipo rectangulo. 
    printf("(%d, %d), (%d, %d)\n", r->p1.x, r->p1.y, r->p2.x, r->p2.y);	//para acceder a los miembros de las estructuas del tipo punto
						    // (*r)p1.x es lo mismo
}
