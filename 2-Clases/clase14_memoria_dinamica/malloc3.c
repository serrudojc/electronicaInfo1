#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

#define UN_GIGABYTE 1*1024*1024*1024 /4

int main (void) {
	while(1) {
		// "Pido" memoria que no es tal hasta que no la uso
        // mirar con el monitor del sistema el uso de memoria
        // luego comentar este malloc y descomentar el proximo
		malloc(UN_GIGABYTE);

		// Pido memoria y la uso
        // mirar con el monitor del sistema el uso de memoria    
		// bzero(malloc(UN_GIGABYTE), UN_GIGABYTE);
		
        sleep(5);
	}
	return 0;
}

