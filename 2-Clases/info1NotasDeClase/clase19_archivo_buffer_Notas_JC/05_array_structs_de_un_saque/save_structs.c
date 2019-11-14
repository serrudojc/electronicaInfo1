#include <stdio.h>
#include <string.h>

struct data {
	int id;
	char msg[20];
	};

#define CSTRUCTS 5

int main(int ac, char **av){
	FILE *fp;
	struct data d[CSTRUCTS];	//array de 5 estructuras, de este tipo de estructura
	int i;
	
	// verifico argumentos de la linea de comandos
	if(ac != 2){
		printf("ERROR! Invocar %s <archivo_donde_salvar>\n", av[0]);
		return 1;
	}
	
	// abro el archivo
	if((fp = fopen(av[1], "w")) == NULL){
		printf("ERROR! No pude abrir %s", av[1]);
		return 2;
	}
	
	// cargo las estructuras con algo
	for(i=0; i<CSTRUCTS; i++){
		d[i].id = i+1;
		//en lugar  strcpy, es como printf pero escribe en una array. 
		// uso pq mensjae 1, mensaje 2 es variable, si hago strcpy, deberia ser fijo
		sprintf(d[i].msg, "mensaje #%d", i+1);
	}
	
	// salvo el array completo y de un saque en disco
	//multiplicacion del tamaño de estructura por la cantidad
	fwrite((char*)&d, sizeof(struct data), CSTRUCTS, fp);
	//parate al ppio del array de estructuras, tomamelo como si fuese un puntero a chars y escrbime la cantidad
	
	// cierro el archivo
	fclose(fp);
	
	return 0;
}
/*
al ejecutar
./save_structs cadorna.dat
*/