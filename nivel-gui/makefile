INCLUDE_COMMONS=
SO_COMMONS=
COMMONS_NAME=commons-library

NIVEL_SO=libnivel-gui.so
INSTALL_DIR=/lib

compile:
	gcc -shared -fPIC nivel.c -I$(INCLUDE_COMMONS) -L$(SO_COMMONS) -o $(NIVEL_SO) -l$(COMMONS_NAME)

install: compile
	cp -u $(NIVEL_SO) $(INSTALL_DIR)

uninstall:
	rm -f $(INSTALL_DIR)/$(NIVEL_SO)	
	
clean:
	rm -f $(NIVEL_SO)

# PHONY targets son los que no producen un archivo llamado como el target
# Se los marca para evitar confusion si se crea un archivo llamado asi
.PHONY: compile install uninstall clean