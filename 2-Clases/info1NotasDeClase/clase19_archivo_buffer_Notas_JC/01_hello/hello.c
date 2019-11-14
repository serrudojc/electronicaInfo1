#include <stdio.h>

int main(void){
	//declaro puntero
	FILE *fp;	
	//fopen devuelve un puntero del tipo estructura tipo FILE
	//le paso como parametro dos punteros char. 
	//primer parametro. Path o nombre del archivo.
	//segundo parametro string, modo en q voy abrir el archivo. Hay 6 modos.
	if((fp = fopen("hello.txt", "w")) == NULL){
		puts("ERROR!!!");
		return 1;
	}
	//idem printf, pero el primer argumento es el file pointer que me da al haber abierto el archivo.
	fprintf(fp, "Hola, mundo!\n");
	//siempre cerrar 
	fclose(fp);
	return 0;
}
