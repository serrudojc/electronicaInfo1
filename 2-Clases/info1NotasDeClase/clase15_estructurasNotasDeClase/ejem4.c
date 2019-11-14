#include <stdio.h>
#include <string.h>

// estructuras
typedef struct {
                int id;
                char nombre[20];
                char apellido[20];
               } salumno_t;

// prototipos
void imprime_alumno(salumno_t *a);
salumno_t *buscar_alumno_x_id(salumno_t *p, int i);	//le pasa comienzo del array, el id que estoy buscando, y devuelve un puntero 
salumno_t *buscar_alumno_x_apellido(salumno_t *p, char *s);

//main
int main(void){
    // crea un array de alumnos y los inicializa, inicializo un array de estructuras
    salumno_t curso[] = {{1, "Rodolfo", "Perez"},
                         {4, "Carlos",  "Sanchez"},
                         {3, "Luis",    "Ruiz"},
                         {0, "",        ""}};
    salumno_t *a;	//declaro un puntero a alumno
    int i;
    char *n;

    // busca un alumno por su id y lo imprime
    i = 3;
    a = buscar_alumno_x_id(curso, i);	//le paso la direccion de comienzo del curso y le paso lo que quiero buscar, a es NULL o puneçtero a la estructura
    if (a != NULL)
        imprime_alumno(a);
    else
        printf("Alumno con id=%d no encontrado\n", i);

    // busca un alumno por su apellido y lo imprime
    n = "Sanchez";
    a = buscar_alumno_x_apellido(curso, n);	//le paso el puntero al curso y el string con el apellido
    if (a != NULL)
        imprime_alumno(a);
    else
        printf("Alumno con apellido '%s' no encontrado\n", n);


    // busca un alumno por apellido pero no existe
    n = "Messi";
    a = buscar_alumno_x_apellido(curso, n);
    if (a != NULL)
        imprime_alumno(a);
    else
        printf("Alumno con apellido '%s' no encontrado\n", n);

    return 0;
}

// -------------------------------------------------------------------
void imprime_alumno(salumno_t *a){	//le paso un puntero alumno
    printf("Alumno %s, %s\tid=%d\n", a->apellido, a->nombre, a->id);	
}

// -------------------------------------------------------------------
salumno_t *buscar_alumno_x_id(salumno_t *p, int i){	//le paso el comienzo al array, el dato y devuelve puntero del tipo estructura a donde esta el alumno
    while (p->id){
        if (p->id == i)
            return p;
        p++;	//si no encuentra, incremento el puntero, se mueve el sizeof de la estructura
    }
    return NULL;
}

// -------------------------------------------------------------------
salumno_t *buscar_alumno_x_apellido(salumno_t *p, char *s){ 
    while (p->id){
        if (strcmp(p->apellido, s) == 0) //busco por el apellido, USO STRCMP
            return p;
        p++;
    }
    return NULL;
}
