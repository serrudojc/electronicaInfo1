CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
OBJS= func_holamundo.o holamundo.o
HEADERS=*.h
EXE=holamundo
MAKEFILE=Makefile8.make

$(EXE): $(OBJS)
	@echo "### Generando el ejecutable"
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c $(MAKEFILE) $(HEADERS)
	@echo "### Compilando " $<
	$(CC) $(CFLAGS) $< -o $@

clean:
	@echo "### Borrando todo"
	rm $(OBJS)
	rm $(EXE)

all: clean $(EXE)
