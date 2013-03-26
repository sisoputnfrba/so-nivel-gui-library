all:
	gcc  -shared -fPIC src/nivel.c -I includes -o libnivel.so
	touch /lib/libnivel.so ; rm /lib/libnivel.so
	ln -s `pwd`/libnivel.so /lib
clean:
	touch /lib/libnivel.so; rm /lib/libnivel.so
	touch libnivel.so; rm libnivel.so

	

