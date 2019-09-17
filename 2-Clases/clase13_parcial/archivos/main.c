#include <stdio.h>
#include "func.h"

int main(int ac, char** av){
    int n;
    char* p;

    // validar que al programa se le pasen la cantidad de parametros necesarios
    // sino, return 1;

    n = contar_palabra(av[1], av[2]);
    printf("la cantidad de veces que aparece \"%s\" en \"%s\" es %d\n\n", av[2], av[1], n);

    p = elimina_palabra(av[1], av[2], &n);
    printf("despues de eliminar queda \"%s\". Se eliminaron %d palabras\n\n", p, n);

    p = ordena_string(p, fcomp_ascendente);
    printf("despues de ordenar en forma ascendente queda \"%s\"\n\n", p);

    p = ordena_string(p, fcomp_descendente);
    printf("despues de ordenar en forma descendente queda \"%s\"\n\n", p);

    return 0;
}