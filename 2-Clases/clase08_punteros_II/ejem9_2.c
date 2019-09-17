#include <stdio.h>

char *nombre_mes(int n);

int main(void){
    int i;

    printf("ingrese el mes: ");
    scanf("%d", &i);
    printf("... el mes ingresado es %s\n", nombre_mes(i));

    return 0;
}

char *nombre_mes(int n){
    char *nombre[] = {"invalido", "Enero", "Febrero", "Marzo",
                      "Abril", "Mayo", "Junio", "Julio",
                      "Agosto", "Septiembre", "Octubre",
                      "Noviembre", "Diciembre"};
    
    return ((n<1) || (n>12)) ? nombre[0] : nombre[n];
}



