src= ./src
obj = ./obj
include = ./include
apps=./apps
bin = .\bin
lib = ./lib

flags = -O3 -Wall
libs= -lm -led -L $(lib)

all: libed myapps

run:
	$(bin)\app

libed: $(obj)/Float_Vector.o
	ar -rcs $(lib)/libed.a $(obj)/*.o
#tem que ter o 'lib' e o .a 


myapps: $(bin)/app 


$(obj)/%.o: $(src)/%.c $(include)/%.h
	gcc $(flags) -c $< -I $(include) -o $@

$(bin)/%: $(apps)/%.c
	gcc $(flags) $< $(libs) -I $(include) -o $@

clean:
	@rm $(lib)\*.a $(obj)\*.o $(bin)\*exe