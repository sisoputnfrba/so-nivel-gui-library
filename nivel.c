#include <stdlib.h>
#include <stdio.h>
#include "nivel.h"

#include <curses.h>

WINDOW * mainwin;


void Inicializar(void) {

	if ( (mainwin = initscr()) == NULL ) {
		perror("error initialising ncurses");
		exit(0);
	}

	noecho();
	keypad(mainwin, TRUE);
}


void Dibujar(Items* items) {

	Items *temp = items;

	erase();
	box(stdscr, 0, 0);

	while (temp != NULL) {
		move (temp->posx, temp->posy);
		addch(temp->id);
		temp = temp->next;
	}

	refresh();

}


void Terminar(void) {

        delwin(mainwin);
        endwin();
        refresh();

}

