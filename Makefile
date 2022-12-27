CFLAGS = -std=c2x -Wall -Wextra
LDFLAGS =  `pkg-config --cflags --libs sdl2 ` -lSDL2_image -ltmx -lz -lxml2


GameTest: main.c
	gcc $(CFLAGS) -o GameTest main.c  $(LDFLAGS) 


GameBug:
	gcc $(CFLAGS) -g -DDEBUG -o GameBug main.c $(LDFLAGS) 
 

.PHONY: test bug clean

test: GameTest
	./GameTest

bug: GameBug
	./GameBug


clean:
	rm -f GameTest GameBug