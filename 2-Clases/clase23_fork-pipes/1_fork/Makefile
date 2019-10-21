all: clean
	gcc -Wall -o fork fork.c
	gcc -Wall -o fork-sleep fork-sleep.c
	gcc -Wall -o fork-sleep-sin-wait fork-sleep-sin-wait.c
	gcc -Wall -o zombie zombie.c

clean:
	rm -f ./fork
	rm -f ./fork-sleep
	rm -f ./fork-sleep-sin-wait
	rm -f ./zombie
