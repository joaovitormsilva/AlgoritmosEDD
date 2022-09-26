src= .\src
obj = .\obj
include = .\include
apps=.\apps
bin = .\bin

all: libed myapps

run:
	$(bin)\app

libed: \
	Float_Vector.o


myapps:
	gcc $(apps)/app.c $(obj)/* -I $(include)\ -o $(bin)/app

%.o: $(src)/%.c $(include)/%.h
	gcc -c $< -I $(include) -o $(obj)/$@

clean:
	rm -rf $(bin)\* $(obj)\*