src= ./src
obj = ./obj
include = ./include
apps=./apps
bin = ./bin

all: libed myapps

run:
	$(bin)\app

libed: $(obj)/Float_Vector.o

myapps: $(bin)/app 


$(obj)/%.o: $(src)/%.c $(include)/%.h
	gcc -c $< -I $(include) -o $@

$(bin)/%: $(apps)/%.c $(include)/*.h
	gcc $< $(obj)/*.o -I $(include) -o $@

clean:
	rm $(bin)\*