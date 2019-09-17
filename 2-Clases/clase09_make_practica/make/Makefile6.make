CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
OBJS= func_holamundo.o holamundo.o

holamundo: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

holamundo.o: holamundo.c
	$(CC) $(CFLAGS) $< -o $@

func_holamundo.o: func_holamundo.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJS)
	rm holamundo
