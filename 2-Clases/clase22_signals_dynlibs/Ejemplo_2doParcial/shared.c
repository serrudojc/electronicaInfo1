#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shared.h"

void interrupcion(int signum) {
	printf("Terminando el programa...\n");
	exit(INTERRUPCION);
}

char * trama_acceso() {
	// Tomar esta funcion como viene, no forma parte del examen.
	char * i;
	char * cuits[] = {"20123450000","20123450001","20123450002","20123450003","20123450004"};

	i = (char *) malloc(sizeof(char)*15);

	i[0] = (random()%2) ? 'I' : 'E';
	i[1] = '0' + random()%10;
	i[2] = '0' + random()%10;
	strcpy(&i[3],cuits[random()%5]);
	i[14] = '\0';

	return i;
}