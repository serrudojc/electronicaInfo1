CC=gcc
CFLAGS= -Wall
LIBS= ./lib/info1-sockets.c ./lib/listdirlib.c

default: all

mp3_server: mp3_server.c mp3.h
	$(CC) $(CFLAGS) -o $@ mp3_server.c $(LIBS)

mp3_client: mp3_client.c mp3.h
	$(CC) $(CFLAGS) -o $@ mp3_client.c $(LIBS)

clean:
	rm -f mp3_server
	rm -f mp3_client

all: clean mp3_server mp3_client

