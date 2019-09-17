CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
OBJS= func_holamundo.o holamundo.o

holamundo: $(OBJS)
	$(CC) $(OBJS) -o holamundo $(LDFLAGS)

holamundo.o: holamundo.c
	$(CC) $(CFLAGS) holamundo.c -o holamundo.o

func_holamundo.o: func_holamundo.c
	$(CC) $(CFLAGS) func_holamundo.c -o func_holamundo.o

clean:
	rm $(OBJS)
	rm holamundo
