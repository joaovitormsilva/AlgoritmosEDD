src= ./src
obj = ./obj
include = ./include
apps=./apps
bin = ./bin

all: libed myapps

run:
	$(bin)\app

libed: $(obj)/Float_Vector.o

myapps:
	gcc $(apps)/app.c $(obj)/*.o -I $(include)\ -o $(bin)/app

$(obj)/%.o: $(src)/%.c $(include)/%.h
	gcc -c $< -I $(include) -o $@

clean:
	rm -rf $(bin)\* $(obj)\*