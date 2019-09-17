CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
OBJS= func_holamundo.o holamundo.o
EXEC=holamundo

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c holamundo.h Makefile7.make
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJS)
	rm $(EXEC)
