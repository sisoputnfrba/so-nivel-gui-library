#include <stdlib.h>
#include <stdio.h>
#include "nivel.h"
#include <sys/ioctl.h>
#include <curses.h>


static WINDOW * secwin;
static WINDOW * mainwin;
static int rows, cols;
static int inicializado = 0;


// ------ Prototipos de Funciones utilitarias ------------

void nivel_gui_get_term_size(int * rows, int * cols);
int nivel_gui_int_validar_inicializado(void);
void nivel_gui_print_perror(const char* message);

// ------------------------------------------------------





int nivel_gui_inicializar(void) {

	if (nivel_gui_int_validar_inicializado()){
			nivel_gui_print_perror("nivel_gui_inicializar: Library ya inicializada!");
			return EXIT_FAILURE;
		}

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

	inicializado = 1;

	return EXIT_SUCCESS;

}


int nivel_gui_dibujar(ITEM_NIVEL* items) {

	if (!nivel_gui_int_validar_inicializado()){
		nivel_gui_print_perror("nivel_gui_dibujar: Library no inicializada!");
		return EXIT_FAILURE;
	}

	if (items == NULL){
		nivel_gui_print_perror("nivel_gui_dibujar: La lista de items no puede ser NULL");
		return EXIT_FAILURE;
	}


	ITEM_NIVEL *temp = items;
	int i = 0;

	werase(secwin);
	box(secwin, 0, 0);
	wbkgd(secwin, COLOR_PAIR(1));

	move(rows - 2, 2);
	printw("Recursos: ");

	while (temp != NULL) {
		wmove (secwin, temp->posy, temp->posx);
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

	return EXIT_SUCCESS;

}


int nivel_gui_terminar(void) {

		if (!nivel_gui_int_validar_inicializado()){
			nivel_gui_print_perror("nivel_gui_terminar: Library no inicializada!");
			return EXIT_FAILURE;
		}

        delwin(mainwin);
        delwin(secwin);
        endwin();
        refresh();

        return EXIT_SUCCESS;

}


int nivel_gui_get_area_nivel(int * rows, int * cols) {

	if (!nivel_gui_int_validar_inicializado()){
			nivel_gui_print_perror("nivel_gui_get_area_nivel: Library no inicializada!");
			return EXIT_FAILURE;
			}

	if (rows == NULL || cols == NULL){
		nivel_gui_print_perror("nivel_gui_get_area_nivel: Ninguno de los argumentos puede ser NULL");
		return EXIT_FAILURE;
	}


	nivel_gui_get_term_size(rows, cols);
	*rows = *rows - 4;
	*cols = *cols - 2;

	return EXIT_SUCCESS;
}


void nivel_gui_get_term_size(int * rows, int * cols) {

    struct winsize ws;

    if ( ioctl(0, TIOCGWINSZ, &ws) < 0 ) {
        perror("couldn't get window size");
    }

    *rows = ws.ws_row;
    *cols = ws.ws_col;
}

int nivel_gui_int_validar_inicializado(void){
	return inicializado;
}

void nivel_gui_print_perror(const char* message){
	fprintf(stderr, "%s\n", message);
}



