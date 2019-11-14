#include <stdlib.h> // para srand
#include <time.h>   // para time
#include "faux.h"

#define MIN 1
#define MAX 100
#define SIZE 10
#define ASCENDENTE 0
#define DESCENDENTE 1

// prototipos
void bubble_sort(int *p, int len, int modo); //segun que le paso, como lo tengo que ordenar
void swap(int *p, int *q);
int comp_ascendente(int x, int y);
int comp_descendente(int x, int y);

int main(void){
    int a[SIZE];

    srand((int)time(NULL));
    fill_array(a, SIZE, MIN, MAX);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, ASCENDENTE);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, DESCENDENTE);
    print_array(a, SIZE);

    return 0;
}

// ordena un array usando el algoritmo bubble sort con el orden dependiendo de modo
void bubble_sort(int *p, int len, int modo){
    int i, j;

    //el secreto de todo esto, es esto:
    int (*fcomp)(int x, int y);     //fcomp es un puntero a una funcion que recibe dos enteros y devuelve un entero. 
    if(modo == ASCENDENTE)          //comparacion por MODO
	    fcomp = comp_ascendente;       // igualo el puntero con la direccion de comienzo de comparacion ascendente.  IGUAL PQ TIENEN EL MISMO PROTOTIPO
    else
	    fcomp = comp_descendente;      //estamos inicializando el puntero, pq tiene basura antes. el nombre de una funcion es como un array. ej int *p --->p=a
  //el secreto de todo esto, fue esto.

    for(i=0; i<len-1; i++)
        for(j=i+1; j<len; j++)
	        if(fcomp(p[i], p[j]))  //la uso como una funcion. Que funcion es? es a la que apunta.
		        swap(&p[i], &p[j]);
}

// intercambia los valores apuntados por ambos punteros
void swap(int *p, int *q){
    int aux;
    aux = *p;
    *p = *q;
    *q = aux;
}

// compara para ordenar en forma ascendente
int comp_ascendente(int x, int y){      //ambas funciones deben ser iguales, recibir dos punteros y devolver un entero. al igual que el puntero a funcion declarado
    return x > y;
}

// compara para ordenar en forma descendente
int comp_descendente(int x, int y){     //el nombre de una funcion es como un array. ej int *p --->p=a
    return x < y;
}

//puntero= variable que guarda direcciones de memoria
//hasta ahora usamos para guardar datos. Ahora usamos puntero de funcion, guarda direccion del comienzo de una funcion.
//REGLA PARA DECLARARLO. ver carpeta
//