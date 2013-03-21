all: tad_items
	gcc main.c -I ../libnivel/includes -L ../libnivel tad_items.o -lnivel -lncurses -o nivel
clean:
	touch tad_items.o; rm tad_items.o
	touch nivel; rm nivel
tad_items:
	gcc tad_items.c -I ../libnivel/includes -L ../libnivel -c -o tad_items.o
