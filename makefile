########## Makefile ############

conversoes: convercoes.o main.o
	gcc convercoes.o main.o -o tp -lm
main.o: main.c convercoes.h
	gcc -g -c main.c
convercoes.o: convercoes.h convercoes.c
	gcc -g -c convercoes.c
