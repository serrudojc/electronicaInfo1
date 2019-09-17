CC=gcc
CFLAGS=-c -Wall
LDFLAGS=

holamundo: func_holamundo.o holamundo.o
	$(CC) func_holamundo.o holamundo.o -o holamundo $(LDFLAGS)

holamundo.o: holamundo.c
	$(CC) $(CFLAGS) holamundo.c -o holamundo.o

func_holamundo.o: func_holamundo.c
	$(CC) $(CFLAGS) func_holamundo.c -o func_holamundo.o

clean:
	rm *.o
	rm holamundo
