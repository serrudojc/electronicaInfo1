CC=gcc
CFLAGS=-c -g
LDFLAGS=­
OBJS=listarmp3.o listdirlib.o listmp3lib.o
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

listarmp3: $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f listarmp3

all: clean listarmp3

