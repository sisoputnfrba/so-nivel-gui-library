# Completar con sus paths
COMMONS_NAME=commons

all: compile
	
compile:
	gcc main.c  -I../nivel-gui  -L../nivel-gui -l$(COMMONS_NAME) -lnivel-gui -lncurses -o nivel

clean:
	rm -f nivel

# PHONY targets son los que no producen un archivo llamado como el target
# Se los marca para evitar confusion si se crea un archivo llamado asi
.PHONY: compile clean
