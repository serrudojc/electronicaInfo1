#include <stdio.h>

//algunas definiciones

enum {ON=1, OFF=0};
enum {NO, SI};

union puerto {
                unsigned char byte;
                struct {
                        unsigned int b0 :1;
                        unsigned int b1 :1;
                        unsigned int b2 :1;
                        unsigned int b3 :1;
                        unsigned int b4 :1;
                        unsigned int b5 :1;
                        unsigned int b6 :1;
                        unsigned int b7 :1;
                       }bit;
              };                            


// prototipos
void imprimir_puerto(union puerto p);

              
// main
int main(void){
    union puerto p;
    
    p.byte = 0;
    imprimir_puerto(p);

    p.bit.b0 = ON;
    imprimir_puerto(p);
    
    p.bit.b7 = ON;
    imprimir_puerto(p);
    
    p.byte = 0x55;
    imprimir_puerto(p);

    return 0;
}

void imprimir_puerto(union puerto p){
    printf("b0 = %d\n", p.bit.b0);
    printf("b1 = %d\n", p.bit.b1);
    printf("b2 = %d\n", p.bit.b2);
    printf("b3 = %d\n", p.bit.b3);
    printf("b4 = %d\n", p.bit.b4);
    printf("b5 = %d\n", p.bit.b5);
    printf("b6 = %d\n", p.bit.b6);
    printf("b7 = %d\n", p.bit.b7);
    printf("byte = 0x%02X\n", p.byte);
    printf("---------------------\n");
}
