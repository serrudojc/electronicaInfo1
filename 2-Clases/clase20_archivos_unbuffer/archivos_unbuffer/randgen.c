#include <stdio.h>		// printf, fflush
#include <sys/types.h>	// open, fstat 
#include <sys/stat.h>	// open, fstat
#include <fcntl.h>		// open
#include <unistd.h>		// fstat, read, write, close, sleep 

int main (void) {
	int fd;
	unsigned int i;
	
	fd = open("/dev/urandom", O_RDONLY);
	
	while(1) {
		read(fd, &i, sizeof(int));
		printf("%u\n", i%1001);
		fflush(stdout);
		sleep(1);	
	}
	
	close(fd);

	return 0;
}
