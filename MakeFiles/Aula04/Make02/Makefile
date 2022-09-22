

all:
	gcc -c .\src\Float_Vector.c -I .\include\ -o .\obj\Float_Vector.o
	gcc ./apps/app.c ./obj/* -I .\include\ -o ./bin/app
run:
	./bin/app
clean:
	rm .\bin\* .\obj\*