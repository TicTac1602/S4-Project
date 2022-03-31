all : test

test: main.o
	gcc -Wall main.o -o test `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`


main.o: main.c
	gcc -c -Wall main.c -o main.o `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

clean:
	rm -rf *.o test
