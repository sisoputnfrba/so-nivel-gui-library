all:
	cd nivel-gui; make
	cd nivel-gui-test; make
install:
	cd nivel-gui; sudo make	install
uninstall:
	cd nivel-gui; sudo make	uninstall
clean:
	cd nivel-gui; sudo make clean
	cd nivel-gui-test; make clean


