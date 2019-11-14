#include <stdio.h>
#include <string.h> //por strerror()

int main(int ac, char **av){
	FILE *fp;
	char s[100];
	int i;

	// verifico argumentos de la linea de comandos
	if(ac != 2){
		printf("ERROR! Invocar %s <archivo_a_leer>\n", av[0]);
		return 1;
	}
	
	// abro el archivo
	if((fp = fopen(av[1], "r")) == NULL){
		printf("ERROR! No pude abrir %s", av[1]);
		return 2;
	}
	
	// -------------------------------------------------------
	// me muevo 30 bytes desde el comienzo del archivo
	//1ro paso el file pointer
	//cantidad
	//3ro desde donde. SEEK SET: mueve el cursor desde el comienzo del archivo. SEEK_CUR. desde donde estoy parado. SEEK_END empiezo del final
	if((i = fseek(fp, 30, SEEK_SET)) == -1){
		printf("%s\n", strerror(i));
		return 3;
	}
	//ftell me dice donde estoy parado
	printf("posicion = %ld\n", ftell(fp));

	// leo 50 bytes desde la posicion 30. NO LINEAS COMO fgets, sino que bytes. Lee hasta el final del archivo
	//tamaño de unidad de lectura, por cuantos valores
	//lee a lo sumo 1*50, s es donde me lo va guardar, un buffer 
	i = fread(s, 1, 50, fp);
	printf("leidos = %d bytes\n", i);
	//llamo de vuelta a ftell para que me diga donde estoy posicionado
	printf("posicion = %ld\n", ftell(fp));

	// los saco por pantalla
	//1er de donde saco los bytes
	// cantidad a escribir. Imprime 50, si yo tnia 48, me imprime basura
	// donde lo voy a escribir
	fwrite(s, 1, 50, stdout);
	puts("\n---------------------------------------------\n");	

	// -------------------------------------------------------
	// me muevo 20 bytes desde la posicion actual
	//me muevo desde donde estoy parado.
	if((i = fseek(fp, 20, SEEK_CUR)) == -1){
		printf("%s\n", strerror(i));
		return 3;
	}
	printf("posicion = %ld\n", ftell(fp));
	
	// leo 50 bytes desde la posicion corriente
	i = fread(s, 1, 50, fp);
	printf("leidos = %d bytes\n", i);
	printf("posicion = %ld\n", ftell(fp));
	
	// los saco por pantalla
	fwrite(s, 1, 50, stdout);
	puts("\n---------------------------------------------\n");	
	

	// -------------------------------------------------------
	// me muevo 50 bytes desde el final del archivo para atras
	//siempre paso negativos, pq es desde el final del archivo
	if((i = fseek(fp, -50, SEEK_END)) == -1){
		printf("%s\n", strerror(i));
		return 3;
	}
	printf("posicion = %ld\n", ftell(fp));
	
	// leo 50 bytes desde la posicion corriente
	i = fread(s, 1, 50, fp);
	printf("leidos = %d bytes\n", i);
	printf("posicion = %ld\n", ftell(fp));
	
	// los saco por pantalla
	fwrite(s, 1, 50, stdout);
	puts("\n---------------------------------------------\n");	

	// cierro el archivo
	fclose(fp); 
	//no se escribe en disco hasta q cierre el archivo
	return 0;
}

