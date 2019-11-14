#include <stdlib.h> // para srand
#include <time.h>   // para time
#include "faux.h"

#define MIN 1
#define MAX 100
#define SIZE 10

// prototipos
void bubble_sort(int *p, int len);

int main(void){
    int a[SIZE];

    srand((int)time(NULL)); //inicializacmos la semilla para el generador random
    fill_array(a, SIZE, MIN, MAX);
    print_array(a, SIZE);
    bubble_sort(a, SIZE);   //funcion de ordenamiento, puntero al comienzo del array y tamaño
    print_array(a, SIZE);

    return 0;
}

// ordena un array de menor a mayor usando el algoritmo bubble sort
void bubble_sort(int *p, int len){
    int i, j, aux;  //dos variables para cada loop y una aux para el swap (intercambiar)
    for(i=0; i<len-1; i++){ // primer parte: primer loop
        for(j=i+1; j<len; j++){     //segundo loop
            if(p[i] > p[j]){        //segunda parte : funcion de comparacion
		        aux = p[i];           // tercera parte: hacer swapping
		        p[i] = p[j];          //MEMORIZAAR IMPORTANTE: ESTE ALGORITMO SIEMPRE TIENE ESTA ESTRUCTURA DE 3 PARTES.
		        p[j] = aux;
	        }
	    }
    }
}


