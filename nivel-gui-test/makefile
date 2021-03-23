# Completar con sus paths
COMMONS_NAME=commons

all: nivel
	
nivel: main.c
	gcc main.c  -I..  -L../nivel-gui/build -l$(COMMONS_NAME) -lnivel-gui -lncurses -o nivel

debug: CC += -DDEBUG -g
debug: all

test: nivel
	-LD_LIBRARY_PATH="../nivel-gui/build/" ./nivel

valgrind: nivel
	-LD_LIBRARY_PATH="../nivel-gui/build/" valgrind --log-file="test.log" ./nivel

clean:
	rm -f nivel

# PHONY targets son los que no producen un archivo llamado como el target
# Se los marca para evitar confusion si se crea un archivo llamado asi
.PHONY: all debug test valgrind clean
