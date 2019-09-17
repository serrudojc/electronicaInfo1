#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // strlen, strcpy
#include <ctype.h>  // toupper

char *str_toupper(char *s);
char **agregar_elemento(char **L, char *s);
void imprimir_array(char **L);
void liberar_memoria(char **L);

int main(int ac, char **av){
    int n;
    char *p;

    // l va a ser el puntero a comienzo de un array de punteros a char.
    // el array termina con un puntero NULL
    char **l;

    if(ac < 2){
        printf("Error! Se debe pasar por lo menos un argumento\n");
        return 1;
    }

    // pido memoria para el array. por ahora esta vacio 
    // por lo que el unico elemento esta inicializado a NULL
    l = (char**) malloc(sizeof(char**));
    *l = NULL;

    // por cada uno de los strings que vienen en la linea de comandos
    // lo agrego al final del array dinamico ya pasado a mayusculas
    for(n=1; n<ac; n++){
        // reservo memoria para guardar una copia del string av[n]
        p = (char*)malloc(strlen(av[n]) + 1);
        
        // copio el string en el lugar de memoria reservado
        strcpy(p, av[n]);
        
        // lo paso a mayusculas
        p = str_toupper(p);
        
        // lo agrego al final del array
        l = agregar_elemento(l, p);
    }

    imprimir_array(l);

    liberar_memoria(l);

    return 0;
}

// ---------------------------------------------------------------------------
char *str_toupper(char *s){
    char *p = s;
    for(; *s; s++)
        *s = toupper(*s);
    return p;
}

// ---------------------------------------------------------------------------
char **agregar_elemento(char **L, char *s){
    int n;
    char **p = L;

    // cuento cuantos punteros hay en el array
    for(n=0; *p; n++, p++)
        ;

    // n tiene la cantidad de punteros sin contar el ultimo que es el NULL
    // entonces realloco el array para que tenga el lugar para el nuevo puntero
    L = (char**)realloc(L, sizeof(char**) * (n + 1 + 1));
    L[n] = s;
    L[n+1] = NULL;
    return L;
}

// ---------------------------------------------------------------------------
void imprimir_array(char **L){
    char **p = L;
    while(*p){
        printf(" - %s\n", *p);
        p++;
    }
}

// ---------------------------------------------------------------------------
void liberar_memoria(char **L){
    char **p = L;

    // primero libero la memoria reservada para copiar cada uno de los strings
    // que venian por la linea de comandos
    while(*p){
        free(*p);
        p++;
    }

    // finalmente libero el array
    free(L);
}

