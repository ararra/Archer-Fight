HEADERS = -lraylib  

default: main	


test: main.c $(HEADERS)
	gcc -c main.c -o main.o


clean:
	-rm -f program.o
	-rm -f program