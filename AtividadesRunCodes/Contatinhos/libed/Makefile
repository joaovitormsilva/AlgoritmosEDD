src= ./src
obj = ./obj
include = ./include
apps=./apps
bin = .\bin
lib = ./lib

flags = -O3 -Wall
libs= -lm -led -L $(lib)

all: 
	gcc -c lista_ligada.c -o lista_ligada.o
	gcc teste_listaLigada.c lista_ligada.o -o main
run:
	./main