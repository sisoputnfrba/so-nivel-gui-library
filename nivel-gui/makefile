# Completar con sus paths
COMMONS_NAME=commons

NIVEL_SO=libnivel-gui.so
INSTALL_DIR=/usr/lib
INSTALL_DIR_INCLUDE=/usr/include

compile:
	gcc -shared -fPIC tad_items.c nivel.c -o $(NIVEL_SO) -l$(COMMONS_NAME)

install: compile
	cp -u $(NIVEL_SO) $(INSTALL_DIR)
	cp -u *.h $(INSTALL_DIR_INCLUDE)

uninstall:
	rm -f $(INSTALL_DIR)/$(NIVEL_SO)
	rm -f $(INSTALL_DIR_INCLUDE)/nivel.h
	rm -f $(INSTALL_DIR_INCLUDE)/tad_items.h
	
clean:
	rm -f $(NIVEL_SO)

# PHONY targets son los que no producen un archivo llamado como el target
# Se los marca para evitar confusion si se crea un archivo llamado asi
.PHONY: compile install uninstall clean
