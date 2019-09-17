#include <stdio.h>

#define SIZE 10

int main(void){
    int a[SIZE];
    int *p;
    int i;

    // lleno el array usando subindice
    for(i=0; i<SIZE; i++)
        a[i] = i*2;

    // lo imprimo usando un puntero
    p = a;
    for(i=0; i<SIZE; i++)
        printf("%d ", *(p+i));
    putchar('\n');

    return 0;
}
