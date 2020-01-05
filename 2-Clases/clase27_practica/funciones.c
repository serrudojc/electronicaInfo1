#include "funciones.h"

/*	-- Lee del socket la trama de autenticacion, valida los datos y envía la trama "OK" si corresponde --
	-- Devuelve OK o ERR_AUTH si la validacion falla --
*/
int autenticar_estacion (int csock, FILE *fd){
	return OK;
}
	
/* 	-- Recibe la trama de autenticacion y valida los datos con el archivo "ciudades.txt" --
	-- Devuelve OK o ERR_AUTH si la validacion falla --
*/
int validar_trama (FILE *fd, char * trama){
	return OK;
}

//	-- Envía la trama "OK" al socket pasado como parámetro --
void enviar_ok (int csock){
	return;
}

/*	-- Lee un registro del socket y lo agrega en el array de estructuras dinámicas --
	-- Devuelve el comienzo del array --
*/
data_t * leer_dato (data_t *p, int csock){
	return p;
}

/*	-- Salva los datos del array de estructuras al archivo pasado como parámetro --
	-- Devuelve OK o ERR_FILE si no pudo escribir en el archivo --
*/
int salvar_datos (char *ciudad, data_t *p){
	return OK;
}

//	-- Maneja la señal que indica que se deben salvar los datos --
void signal_handler (int sigint){
	return;
}
