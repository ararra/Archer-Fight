CFLAGS = -std=c2x -Wall -O0 -I/usr/include/libxml2
LDFLAGS =  -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lxml2 
TMX = third_party/tmx-tmx_1.2.0/src/*.c


Test: main.c 
	gcc $(CFLAGS) main.c $(TMX) $(LDFLAGS)

Bug: main.c $(TMX) 
	gcc $(CFLAGS) -ggdb -DDEBUG main.c $(TMX)  $(LDFLAGS)

.Phony: test bug clean

test: Test
	./a.out

bug: Bug
	./a.out

clean:
	rm -f a.out