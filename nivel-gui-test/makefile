# Completar con sus paths
COMMONS_DIR_HEADERS=/home/utnso/so-commons-library/src
COMMONS_DIR_BIN=/home/utnso/so-commons-library/Debug
COMMONS_NAME=so-commons-library

all: compile
	
compile:
	gcc main.c -I$(COMMONS_DIR_HEADERS) -I../nivel-gui -L$(COMMONS_DIR_BIN) -L../nivel-gui -l$(COMMONS_NAME) -lnivel-gui -lncurses -o nivel

clean:
	rm -f nivel

# PHONY targets son los que no producen un archivo llamado como el target
# Se los marca para evitar confusion si se crea un archivo llamado asi
.PHONY: compile clean
