#include <stdio.h>
#include <string.h>

// estructuras
typedef struct {
                int id;
                char nombre[20];
                char apellido[20];
               } salumno_t;

// prototipos
void imprime_alumno(salumno_t *a);
void imprime_curso(salumno_t **p);

void bubble_sort_x_id(salumno_t **p, int (*compare)(int a, int b));
void swap(salumno_t **p, salumno_t **q);
int ascendente_int(int a, int b);
int descendente_int(int a, int b);

void bubble_sort_x_apellido(salumno_t **p, int (*compare)(char *a, char *b));
int ascendente_str(char *a, char *b);
int descendente_str(char *a, char *b);


//main
int main(void){
    // crea varios alumnos y los inicializa
    salumno_t a1 = {1, "Rodolfo", "Perez"};
    salumno_t a2 = {4, "Carlos",  "Sanchez"};
    salumno_t a3 = {3, "Luis",    "Ruiz"};
    salumno_t a4 = {2, "Jose",    "Alvarez"};

    // crea un array de punteros a estructura de tipo alumno
    salumno_t *pa[20];

    // incializa el array de punteros asignando la direccion de cada una de las estructuras
    pa[0] = &a1;
    pa[1] = &a2;
    pa[2] = &a3;
    pa[3] = &a4;
    pa[4] = NULL;	//para cuando itere, sepa donde termine el array

    // imprime todo el curso desordenado
    printf("curso desordenado\n");
    imprime_curso(pa);	//le paso pa, direccion de comienzo del array
    printf("---------------------------\n");

    // ordena el curso por id en forma ascendente
    printf("curso ordenado por id ascendente\n");
    bubble_sort_x_id(pa, ascendente_int);	//le paso el array y la funcion de comparacion
    imprime_curso(pa);
    printf("---------------------------\n");

    // ordena el curso por id en forma descendente
    printf("curso ordenado por id descendente\n");	
    bubble_sort_x_id(pa, descendente_int);
    imprime_curso(pa);
    printf("---------------------------\n");

    // ordena el curso por apellido en forma ascendente
    printf("curso ordenado por apellido ascendente\n");
    bubble_sort_x_apellido(pa, ascendente_str);
    imprime_curso(pa);
    printf("---------------------------\n");

    // ordena el curso por apellido en forma descendente
    printf("curso ordenado por apellido descendente\n");
    bubble_sort_x_apellido(pa, descendente_str);
    imprime_curso(pa);
    printf("---------------------------\n");

    return 0;
}

// -------------------------------------------------------------------
void imprime_alumno(salumno_t *a){
    printf("Alumno %s, %s\tid=%d\n", a->apellido, a->nombre, a->id);
}

// -------------------------------------------------------------------
void imprime_curso(salumno_t **p){	//le paso direccion de comienzo de un array de enteeros, PUNTERO A PUNTERO. 
    while(*p){
        imprime_alumno(*p);	//espera recibir un alumno, y el contenido de p es un puntero
        p++; //se mueve SIZEOF DEL PUNTERO, no el tamaño de la estructura
    }
}

// -------------------------------------------------------------------
// ----------- x id --------------------------------------------------
// ordena un array de punteros a alumno por id usando el algoritmo bubble sort
void bubble_sort_x_id(salumno_t **p, int (*compare)(int a, int b)){ //comienzo del array **p, funcion de comparacion: recibe dos enteros
    int i, j, len;
    salumno_t **aux = p;
    for(len=0; *aux; aux++, len++); //calcula la longitud del array. calculo len hasta encontrar el puntero nulo, incrementando en cada vuelta

    for(i=0; i<len-1; i++)	//dos for, un if y un swap, si habia que hacerlo.
        for(j=i+1; j<len; j++)
            if(compare(p[i]->id, p[j]->id))	//comparo los dos id, dos enteros que son miembros de la estructura
                swap(&p[i], &p[j]);
}

// intercambia los valores apuntados por ambos punteros
void swap(salumno_t **p, salumno_t **q){
    salumno_t *aux;	//puntero auxiliar
    aux = *p;			//se puede usar para enteros o chars, indistinto, pq estoy permutando PUNTEROS
    *p = *q;
    *q = aux;
}

// devuelve verdadero si a > b
int ascendente_int(int a, int b){
    return a > b;
}

// devuelve verdadero si a < b
int descendente_int(int a, int b){
    return a < b;
}

// -------------------------------------------------------------------
// ----------- x apellido --------------------------------------------
// ordena un array de punteros a alumno por apellido usando el algoritmo bubble sort
void bubble_sort_x_apellido(salumno_t **p, int (*compare)(char *a, char *b)){
    int i, j, len;
    salumno_t **aux = p;
    for(len=0; *aux; aux++, len++); //calcula la longitud del array

    for(i=0; i<len-1; i++)
        for(j=i+1; j<len; j++)
            if(compare(p[i]->apellido, p[j]->apellido))	//comparo por el campo de apellido
                swap(&p[i], &p[j]);		//la funcion de swap no cambia, pq estoy permutando PUNTEROS
}


// devuelve verdadero si el string a es "mayor" que el string b. ver funcion strcmp
int ascendente_str(char *a, char *b){
    if(strcmp(b, a) < 1)	//funcion de comparacion
        return 1;
    return 0;
}

// devuelve verdadero si el srting a en "menor" que el string b. idem ver funcion strcmp
int descendente_str(char *a, char *b){
    if(strcmp(a, b) < 1)
        return 1;
    return 0;
}
