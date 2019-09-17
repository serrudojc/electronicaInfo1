#include <stdio.h>

//algunas definiciones

enum {ON=1, OFF=0};
enum {NO, SI};



// campos de bits
struct flags {
                unsigned int encendido:     1;
                unsigned int error:         1;
                unsigned int sobretension:  1;
              };

// prototipos
void imprimir_bits(struct flags f);

              
// main
int main(void){
    struct flags flg;
    
    flg.encendido = OFF;
    flg.error = NO;
    flg.sobretension = NO;
    imprimir_bits(flg);
    
    // muevo algunos bits y los muestro
    flg.encendido = ON;
    imprimir_bits(flg);
    
    flg.encendido = OFF;
    flg.error = SI;
    flg.sobretension = SI;
    imprimir_bits(flg);
    
    if(flg.sobretension)
        printf("CUIDADO: Sobretension !!!\n");

    return 0;
}

void imprimir_bits(struct flags f){
    printf("encendido    = %d\n", f.encendido);
    printf("error        = %d\n", f.error);
    printf("sobretension = %d\n", f.sobretension);
    printf("---------------------\n");
}
