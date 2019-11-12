CC=gcc
CFLAGS= -Wall
LIBS=./lib/info1-sockets.c

default: all

chat_server: chat_server.c funciones.c funciones.h
	$(CC) $(CFLAGS) -o $@ chat_server.c funciones.c $(LIBS)

chat_client: chat_client.c funciones.c funciones.h
	$(CC) $(CFLAGS) -o $@ chat_client.c funciones.c $(LIBS)

clean:
	rm -f chat_server
	rm -f chat_client

all: clean chat_server chat_client

