#include <stdio.h>

// uniones
union u {
            int i;
            char b[sizeof(int)];
        };
         
typedef union {
                char c;
                int i;
                double d;
              } utrucha_t;
               
// main
int main(void){
    union u uprueba;
    utrucha_t ut;
    int i;
    
    // verificamos el tamanio de las uniones
    printf("el tamanio de la union u es %ld\n", sizeof(uprueba));
    printf("el tamanio de la union trucha es %ld\n", sizeof(ut));

    // cargo la union u como entero y la leo como chars
    uprueba.i = 0x12345678;
    for(i=0; i<sizeof(uprueba.b); i++)
        printf("%02X ", uprueba.b[i]);
    printf("\n");

    return 0;
}

