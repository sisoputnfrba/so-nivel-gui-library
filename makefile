all:
	-cd nivel-gui && $(MAKE) all
	-cd nivel-gui-test && $(MAKE) all

clean:
	-cd nivel-gui && $(MAKE) clean
	-cd nivel-gui-test && $(MAKE) clean

debug:
	-cd nivel-gui && $(MAKE) debug
	-cd nivel-gui-test && $(MAKE) debug

test: all
	-cd nivel-gui-test && $(MAKE) test

install: all
	-cd nivel-gui && sudo $(MAKE) install

uninstall:
	-cd nivel-gui && sudo $(MAKE) uninstall

valgrind: all
	-cd nivel-gui-test && $(MAKE) valgrind

.PHONY: all clean debug test install uninstall