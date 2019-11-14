#include <stdlib.h> // para srand
#include <time.h>   // para time
#include "faux.h"

#define MIN 1
#define MAX 100
#define SIZE 10

// prototipos
void bubble_sort(int *p, int len, int (*fcomp)(int x, int y), void (*fswap)(void *m, void *n));
void swap_enteros(void *p, void *q);
int comp_ascendente(int x, int y);
int comp_descendente(int x, int y);

int main(void){
    int a[SIZE];

    srand((int)time(NULL));
    fill_array(a, SIZE, MIN, MAX);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, comp_ascendente, swap_enteros);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, comp_descendente, swap_enteros);
    print_array(a, SIZE);

    return 0;
}

// ordena un array usando el algoritmo bubble sort 
// usando fcomp para comparar y fswap para permutar             //le paso un puntero void. generalizando, para poder swapear cosas que no sean enteros.
void bubble_sort(int *p, int len, int (*fcomp)(int x, int y), void (*fswap)(void *m, void *n)){
    int i, j;
    for(i=0; i<len-1; i++)
        for(j=i+1; j<len; j++)
	        if(fcomp(p[i], p[j]))
		        fswap(&p[i], &p[j]);
}

// intercambia los valores apuntados por ambos punteros // la funcion recibe dos void pointers, Que son estos void pointers? lo se dentro de la implementacion
void swap_enteros(void *p, void *q){    //puntero void, esta declarado como void, ahora cada vez que lo use, OJO que ahora son enteros. CASTEAR
    int aux;                            //si swapeo chars, el prototipo no cambia, cambia la implementacion de la funcion, casteando a char dentro de la funcion
    aux = *(int*)p;     //hago que el dato me lo tome como entero
    *(int*)p = *(int*)q; //casteo
    *(int*)q = aux;
}

// compara para ordenar en forma ascendente
int comp_ascendente(int x, int y){
    return x > y;
}

// compara para ordenar en forma descendente
int comp_descendente(int x, int y){
    return x < y;
}

