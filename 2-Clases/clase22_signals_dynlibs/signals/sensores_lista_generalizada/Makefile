CC=gcc
CFLAGS=-c
LDFLAGS=­
OBJS=sensores.o 1_main_original.o 2_main_control_c.o 3_main_multiple.o 4_main_alarma.o
SOURCES=$(OBJS:.o=.c)
HEADERS=*.h

sens: $(OBJS)
	$(CC) 1_main_original.o sensores.o -o 1_sens_original 
	$(CC) 2_main_control_c.o sensores.o -o 2_main_control_c 
	$(CC) 3_main_multiple.o sensores.o -o 3_sens_multiple 
	$(CC) 4_main_alarma.o sensores.o -o 4_sens_alarma 

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f 1_sens_original
	rm -f 2_main_control_c
	rm -f 3_sens_multiple
	rm -f 4_sens_alarma

all: clean sens

