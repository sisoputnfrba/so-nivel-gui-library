INCLUDE_COMMONS=$(HOME)/projects/commons-library/src
SO_COMMONS=$(HOME)/projects/commons-library/dist/Debug/GNU-Linux-x86

COMMONS_NAME=commons-library
NIVEL_GUI_NAME=nivel-gui

all: compile
	
compile:
	gcc main.c -I$(INCLUDE_COMMONS) -L$(SO_COMMONS) -l$(COMMONS_NAME) -l$(NIVEL_GUI_NAME) -lncurses -o nivel

clean:
	rm -f nivel

# PHONY targets son los que no producen un archivo llamado como el target
# Se los marca para evitar confusion si se crea un archivo llamado asi
.PHONY: compile clean
