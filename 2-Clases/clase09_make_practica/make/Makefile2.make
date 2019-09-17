all:
	gcc -Wall -c -o func_holamundo.o func_holamundo.c
	gcc -Wall -c -o holamundo.o holamundo.c
	gcc -Wall -o holamundo holamundo.o func_holamundo.o
clean:
	rm *.o
	rm holamundo
