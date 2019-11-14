#include <stdio.h>
#include <stdlib.h>

struct data {
	int id;
	char msg[20];
	};


int main(int ac, char **av){
	FILE *fp;
	struct data *ps;	//declaro puntero
	
	// verifico argumentos de la linea de comandos
	if(ac != 2){
		printf("ERROR! Invocar %s <archivo_de_donde_leer>\n", av[0]);
		return 1;
	}
	
	// abro el archivo
	if((fp = fopen(av[1], "r")) == NULL){
		printf("ERROR! No pude abrir %s", av[1]);
		return 2;
	}
	// no se cuantas estructuras tiene el archivo : Cuando paro? EOF	


	// reservo memoria para alocar una estructura data para guardar UNA esctructura
	ps = (struct data *)malloc(sizeof(struct data));

	// leo del disco e imprimo los datos UNA structura
	while(1){
		fread((char*)ps, sizeof(struct data), 1, fp);
		if(feof(fp))	//feof y le paso el puntero, me dice si el cursor llego al final del archivo
			break;
		printf("id=%d   msg=%s\n", ps->id, ps->msg);	//uso flechita pq es PUNTEERO A ESTRUCTURA
	}
		
	// libero la estructura, libero la memoria que pedí al ppio
	free(ps);
	
	// cierro el archivo
	fclose(fp);
	
	return 0;
}
// lo bueno de esto, es que ningun lado le estoy diciendo la cantidad de estructuras que tengo
