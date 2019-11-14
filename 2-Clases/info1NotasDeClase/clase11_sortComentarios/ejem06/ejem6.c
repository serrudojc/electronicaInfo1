#include <stdlib.h> // para srand
#include <time.h>   // para time
#include "faux.h"

#define MIN 1
#define MAX 100
#define SIZE 10

// prototipos                           //puntero a funcion, que es funcion de compracion. fcomp es el nombre del puntero NO DE LA FUNCION
void bubble_sort(int *p, int len, int (*fcomp)(int x, int y));  //mejorarmos la funcion, sacando el MODO, pasandole la funcion de comparacion. Para no andar decidiendo andentro de la funcion, que codenamiento hacer.
void swap(int *p, int *q);
int comp_ascendente(int x, int y);
int comp_descendente(int x, int y);

int main(void){
    int a[SIZE];

    srand((int)time(NULL)); //inicializar el generador random
    fill_array(a, SIZE, MIN, MAX);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, comp_ascendente);  //direccion de comienzo de comp_ascendente (puntero a funcion)
    print_array(a, SIZE);
    bubble_sort(a, SIZE, comp_descendente);
    print_array(a, SIZE);

    return 0;
}

// ordena un array usando el algoritmo bubble sort
// usando fcomp para comparar
void bubble_sort(int *p, int len, int (*fcomp)(int x, int y)){      //fcomp es un puntero a funcion que ecibe dos enteros y devuelve un entero.
    int i, j;
    for(i=0; i<len-1; i++)
        for(j=i+1; j<len; j++)
	        if(fcomp(p[i], p[j]))  //que paso aca? el programa no lo sabe ni le importa. cualquier funcion que reciba dos enteros y devuelva un entero le va servir
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
int comp_ascendente(int x, int y){
    return x > y;
}

// compara para ordenar en forma descendente
int comp_descendente(int x, int y){
    return x < y;
}

