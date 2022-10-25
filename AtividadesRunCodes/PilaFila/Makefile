src= ./src
obj = ./obj
include = ./include
apps=./apps
bin = .\bin
lib = ./lib

flags = -O3 -Wall
libs= -lm -led -L $(lib)

all: 
	gcc -c PilhaDin.c -o PilhaDin.o
	gcc -c fila.c -o fila.o

	gcc pilafila.c PilhaDin.o fila.o -o main

run:
	./main