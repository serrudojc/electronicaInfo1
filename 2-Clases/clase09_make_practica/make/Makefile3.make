holamundo: func_holamundo.o holamundo.o
	gcc func_holamundo.o holamundo.o -o holamundo

holamundo.o: holamundo.c
	gcc -c holamundo.c -o holamundo.o

func_holamundo.o: func_holamundo.c
	gcc -c func_holamundo.c -o func_holamundo.o

clean:
	rm *.o
	rm holamundo
