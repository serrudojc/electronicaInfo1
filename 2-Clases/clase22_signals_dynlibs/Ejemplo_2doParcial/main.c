#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "shared.h"
#include "acceso.h"

int main(void) {
	srandom(time(NULL));

	printf("Process ID: %d\n", getpid());

	signal(SIGINT, interrupcion);

	while(1) {
		sleep(1);
	}
	return 0;
}