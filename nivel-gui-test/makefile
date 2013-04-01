all: tad_items
	gcc main.c -I ../nivel-gui -L ../nivel-gui tad_items.o -lnivel-gui -lncurses -o nivel
clean:
	touch tad_items.o; rm tad_items.o
	touch nivel; rm nivel
tad_items:
	gcc tad_items.c -I ../nivel-gui -L ../nivel-gui -c -o tad_items.o
