/* main.c */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "sensores.h"

int main(int ac, char **av){
	sensor_t *sens;
	int c;
	
	if ((c=verifica_argumentos(ac, av)) != 0)
		return c;
	
	sens = (sensor_t*)malloc(ac * sizeof(sensor_t));
	inicializa_sensores(sens, ac, av);
	while(1){
		lee_sensores(sens);
		imprime_sensores(sens);
		imprime_maxt(calcula_maxt(sens));
		imprime_mint(calcula_mint(sens));
		imprime_promedio(calcula_promedio(sens));
		sleep(PERIODO);
		printf("-------------------------\n");
	}

	return 0;
}
