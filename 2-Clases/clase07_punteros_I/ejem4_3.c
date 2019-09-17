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
    for(i=0, p=a; i<SIZE; i++, p++){
        printf("%d ", *p);
    }
    putchar('\n');

    return 0;
}
