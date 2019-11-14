#include <stdio.h>

struct data {
	int id;
	char msg[20];
	};

int main(int ac, char **av){
	FILE *fp;
	struct data d;	//estructura vacia o con basura. Esto me permite que yo al hacer fread, que lea la chorrera de bytes , me lo interprete como estructura

	
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
	
	// leo del disco
	//leeme la estructura, una, desde este puntero
	//casteo pq espera char pointers, a la structura tomamela todo como bytes
	fread((char*)&d, sizeof(struct data), 1, fp);
	
	//imprimo los datos
	printf("id=%d   msg=%s\n", d.id, d.msg);
		
	// cierro el archivo
	fclose(fp);
	
	return 0;
}

al ejecutar
./read_structs pirulo.dat
