CC=gcc
CFLAGS= -Wall
LIBS=./lib/info1-sockets.c

default: all

main: main.c funciones.c funciones.h
	$(CC) $(CFLAGS) -o $@ main.c funciones.c $(LIBS)

clean:
	rm -f main client

client: client.c
	$(CC) $(CFLAGS) -o $@ client.c $(LIBS)

all: clean main client

