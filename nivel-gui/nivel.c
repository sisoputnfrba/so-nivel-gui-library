#include <stdlib.h>
#include <stdio.h>
#include "nivel.h"
#include <sys/ioctl.h>
#include <curses.h>

WINDOW * secwin;
WINDOW * mainwin;

int rows, cols;

void nivel_gui_inicializar(void) {

	mainwin = initscr();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	init_pair(1,COLOR_GREEN, COLOR_BLACK);
	init_pair(2,COLOR_WHITE, COLOR_BLACK);
	init_pair(3,COLOR_BLACK, COLOR_YELLOW);
	box(stdscr, 0, 0);
	refresh();

	nivel_gui_get_term_size(&rows, &cols);
	secwin = newwin(rows - 2, cols, 0, 0);
	box(secwin, 0, 0);
	wrefresh(secwin);

}


void nivel_gui_dibujar(ITEM_NIVEL* items) {

	ITEM_NIVEL *temp = items;
	int i = 0;

	werase(secwin);
	box(secwin, 0, 0);
	wbkgd(secwin, COLOR_PAIR(1));

	move(rows - 2, 2);
	printw("Recursos: ");

	while (temp != NULL) {
		wmove (secwin, temp->posx, temp->posy);
		if (temp->item_type) {
			waddch(secwin, temp->id | COLOR_PAIR(3));
		} else {
			waddch(secwin, temp->id | COLOR_PAIR(2));
		}
		if (temp->item_type) {
			move(rows - 2, 7 * i + 3 + 9);
			printw("%c: %d - ", temp->id, temp->quantity);
			i++;
		}
		temp = temp->next;

	}
	wrefresh(secwin);
	wrefresh(mainwin);

}


void nivel_gui_terminar(void) {

        delwin(mainwin);
        delwin(secwin);
        endwin();
        refresh();

}

void nivel_gui_get_term_size(int * rows, int * cols) {

    struct winsize ws;

    if ( ioctl(0, TIOCGWINSZ, &ws) < 0 ) {
        perror("couldn't get window size");
    }

    *rows = ws.ws_row;
    *cols = ws.ws_col;
}

void nivel_gui_get_area_nivel(int * rows, int * cols) {
	nivel_gui_get_term_size(rows, cols);
	*rows = *rows - 4;
	*cols = *cols - 2;
}
