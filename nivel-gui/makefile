CC=gcc

C_SRCS=$(shell find . -iname "*.c" | tr '\n' ' ')
H_SRCS=$(shell find . -iname "*.h" | tr '\n' ' ')
OBJS=$(C_SRCS:./%.c=build/nivel-gui/%.o)

COMMONS_NAME=commons

NIVEL_SO=libnivel-gui.so
INSTALL_DIR=/usr/lib
INSTALL_DIR_INCLUDE=/usr/include/nivel-gui

# Clean and compile .so
all: build/$(NIVEL_SO)

build/nivel-gui:
	mkdir -p $@

build/$(NIVEL_SO): build/nivel-gui $(OBJS)
	$(CC) -shared -o "build/$(NIVEL_SO)" $(OBJS) -l$(COMMONS_NAME)

build/nivel-gui/%.o: %.c
	$(CC) -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"

# Add debug parameters and compile
debug: CC += -DDEBUG -g
debug: all

# Clean build files
clean:
	rm -rf build

install: all
	cp -u build/$(NIVEL_SO) $(INSTALL_DIR)
	mkdir -p $(INSTALL_DIR_INCLUDE)
	cp --parents -u $(H_SRCS) $(INSTALL_DIR_INCLUDE)

uninstall:
	rm -f $(INSTALL_DIR)/$(NIVEL_SO)
	rm -rf $(INSTALL_DIR_INCLUDE)

# PHONY targets son los que no producen un archivo llamado como el target
# Se los marca para evitar confusion si se crea un archivo llamado asi
.PHONY: all debug clean install uninstall
