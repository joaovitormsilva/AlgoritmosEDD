src= .\src
obj = .\obj
include = .\include
apps=.\apps
bin = .\bin

all: libed myapps

run:
	$(bin)\app

libed:
	gcc -c $(src)\Float_Vector.c -I $(include)\ -o $(obj)\Float_Vector.o

myapps:
	gcc $(apps)/app.c $(obj)/* -I $(include)\ -o $(bin)/app

clean:
	rm $(bin)\* $(obj)\*