#include <stdio.h>
#include <string.h>

struct data {
	int id;
	char msg[20];
	};

int main(int ac, char **av){
	FILE *fp;
	struct data d;

	
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
	
	// cargo la estructura con algo. Todavia no la salvé
	d.id = 66;
	strcpy(d.msg, "mensaje #1");
	
	// la salvo en disco. casteada como si fuese un char pointer (si no lo casteo, es una estructura d)
	//toda la estructura tomamela como si fuese un monton de bytes
	fwrite((char*)&d, sizeof(struct data), 1, fp);
	
	// cierro el archivo
	fclose(fp);
	
	return 0;
}

