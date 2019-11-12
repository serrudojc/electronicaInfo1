CC=gcc
CFLAGS=-c
LDGLAGS=
OBJS= funciones.o main.o
HEADERS=*.h
EXE=control
MAKEFILE=Makefile

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
