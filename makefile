all: main

main: main.o ler_arquivo.o grid.o
	gcc -o tp2 main.o ler_arquivo.o grid.o

main.o: main.c ler_arquivo.c grid.c
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic -std=c99

ler_arquivo.o: ler_arquivo.c ler_arquivo.h
	gcc -o ler_arquivo.o ler_arquivo.c -c -W -Wall -ansi -pedantic -std=c99

grid.o: grid.c grid.h
	gcc -o grid.o grid.c -c -W -Wall -ansi -pedantic -std=c99

clean:
	rm -rf *.o *~ tp2