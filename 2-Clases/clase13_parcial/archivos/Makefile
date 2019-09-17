# compilador c
CC=gcc
# flags pasados al complilado
CFLAGS=-c -Wall
# flags pasados al linker
LDFLAGS=
# lista de todos los archivos objeto
OBJS=main.o func.o
# lista de todos los archivos fuente
SOURCES=$(OBJS:.o=.c)
# lista de todos los archivos header
HEADERS=*.h
# nombre del ejecutable
EXE=parcial
# nombre del makefile
MAKEFILE=Makefile

# regla para generar el ejecutable
$(EXE): $(OBJS)
	@echo "### Generando ejecutable"
	$(CC) $(OBJS) -o $@

# regla para generar los archivos objeto
%.o: %.c $(MAKEFILE) $(HEADERS)
	@echo "### Compilando" $<
	$(CC) $(CFLAGS) -o $@ $<

# regla para borrar el resultado de la compilacion anterior
clean:
	@echo "### Borrando todo..."
	rm -f ./*.o
	rm -f $(EXE)

# regla para hacer todo desde el comienzo (borrar todo, compilar y linkear)
all: clean $(EXE)

