all:
	gcc  -shared -fPIC nivel.c -I . -o libnivel-gui.so
install:
	touch /lib/libnivel-gui.so ; rm /lib/libnivel-gui.so
	ln -s `pwd`/libnivel-gui.so /lib
clean:
	touch /lib/libnivel-gui.so; rm /lib/libnivel-gui.so
	touch libnivel-gui.so; rm libnivel-gui.so

	

