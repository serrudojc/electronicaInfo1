#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

#define UN_GIGABYTE 1*1024*1024

int main (void) {
	int tam = UN_GIGABYTE;
	void * p;
	p = malloc(tam);
	while(1) {
		printf("%p\n", p);
		sleep(5);
		tam += UN_GIGABYTE;
		p = realloc(p, tam);
	}
	return 0;
}

