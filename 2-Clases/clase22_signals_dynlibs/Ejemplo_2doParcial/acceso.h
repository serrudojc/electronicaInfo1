// Funcion que recibe la senal SIGUSR1
void signal_acceso(int signum);

// Otras funciones implementar
nodo_t * nuevo_acceso(char * a);
int registrar_acceso(nodo_t ** L, char * a);
int analizar_accesos(nodo_t * n);
char * formatear_cuit(char * cuit);
void imprimir_acceso(nodo_t * n);