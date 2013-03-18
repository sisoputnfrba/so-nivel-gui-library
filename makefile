all: nivel.o
	gcc main.c nivel.o -o nivel -lncurses -ggdb

nivel:
	gcc nivel.c -c -o nivel.o -lncurses

clean:
	rm nivel.o nivel
