src= ./src
obj = ./obj
include = ./include
apps=./apps
bin = .\bin
lib = ./lib

flags = -O3 -Wall
libs= -lm -led -L $(lib)

all: libed myapps

libed: \
	$(obj)/Float_Vector.o\
	$(obj)/lista_ligada.o
	ar -rcs $(lib)/libed.a $(obj)/*.o

#tem que ter o 'lib' e o .a 
myapps: $(bin)/test_float_vector 


$(obj)/%.o: $(src)/%.c $(include)/%.h
	gcc $(flags) -c $< -I $(include) -o $@

$(bin)/%: $(apps)/%.c
	gcc $(flags) $< $(libs) -I $(include) -o $@

run:
	$(bin)\app

clean:
	@rm $(lib)\*.a $(obj)\*.o $(bin)\*exe