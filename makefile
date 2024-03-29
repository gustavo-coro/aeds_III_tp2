all: main

main: main.o ler_arquivo.o gridPD.o gridFB.o
	gcc -o tp2 main.o ler_arquivo.o gridPD.o gridFB.o

main.o: main.c ler_arquivo.c gridPD.c gridFB.c
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic -std=c99

ler_arquivo.o: ler_arquivo.c ler_arquivo.h
	gcc -o ler_arquivo.o ler_arquivo.c -c -W -Wall -ansi -pedantic -std=c99

gridPD.o: gridPD.c gridPD.h
	gcc -o gridPD.o gridPD.c -c -W -Wall -ansi -pedantic -std=c99

gridFB.o: gridFB.c gridFB.h
	gcc -o gridFB.o gridFB.c -c -W -Wall -ansi -pedantic -std=c99

clean:
	rm -rf *.o *~ tp2