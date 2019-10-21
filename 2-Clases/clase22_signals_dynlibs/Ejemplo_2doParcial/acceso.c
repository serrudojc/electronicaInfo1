#include <time.h>
#include "shared.h"
#include "acceso.h"

// Funcion que recibe la senal
void signal_acceso(int signum) {
	// El comienzo de la lista enlazada. 
	// Se inicializa en NULL la primera vez solamente,
	// luego mantiene cualquier valor que se le asigne.
	static nodo_t * L = NULL;
	// A implementar.
	// Que tengo que hacer al recibir una accion de ingreso o egreso?
}

nodo_t * nuevo_acceso(char * i) {
	// Implementar
	return NULL;
}

int registrar_acceso(nodo_t ** L, char * i) {
	// Implementar
	// ...
	//return analizar_accesos(...);
	return 0;
}

int analizar_accesos(nodo_t * n) {
	// Implementar
	return 0;
}

char * formatear_cuit(char * cuit) {
	// Implementar
	return NULL;
}

void imprimir_acceso(nodo_t * n) {
	// Implementar. Recordar el uso de strftime!
}