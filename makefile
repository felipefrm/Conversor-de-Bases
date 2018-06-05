########## Makefile ############

all: main.o convercoes.o verificacoes.o
	gcc verificacoes.o convercoes.o main.o -o tp -lm

main.o: main.c convercoes.h verificacoes.h
	gcc -g -c main.c
convercoes.o: convercoes.h convercoes.c
	gcc -g -c convercoes.c
verificacoes.o: verificacoes.h verificacoes.c
	gcc -g -c verificacoes.c
