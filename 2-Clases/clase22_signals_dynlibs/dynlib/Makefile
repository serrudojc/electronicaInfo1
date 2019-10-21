all:
	gcc -Wall -o main main.c -ldl

libs:
	gcc -c -fPIC -o printb.o printb.c
	gcc -c -fPIC -o printn.o printn.c
	gcc -shared -o libprinter.so printb.o printn.o -lc

clean:
	rm -f main *.o *.so
