#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <curses.h>

#include "nivel.h"

static WINDOW * secwin;
static WINDOW * mainwin;
static int rows, cols;
static int inicializado = 0;

t_list* NIVEL_GUI_ITEMS = NULL;

// ------ Prototipos de Funciones utilitarias ------------

/*
 * @NAME: nivel_gui_get_term_size
 * @DESC: Devuelve el tamanio total de la pantalla
 * @PARAMS:
 *      filas    - valor de retorno de filas
 *      columnas - valor de retorno de columnas
 */
void nivel_gui_get_term_size(int * filas, int * columnas);

/*
 * @NAME: nivel_gui_int_validar_inicializado
 * @DESC: Informa si se inicializo el nivel corectamente
 */
int nivel_gui_int_validar_inicializado(void);

// ------------------------------------------------------

int nivel_gui_inicializar(void) {

	if (nivel_gui_int_validar_inicializado()) {
		return NGUI_ALREADY_INIT;
	}

	mainwin = initscr();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	init_pair(1,COLOR_GREEN, COLOR_BLACK);
	init_pair(2,COLOR_WHITE, COLOR_BLACK);
	init_pair(3,COLOR_BLACK, COLOR_YELLOW);
	init_pair(4,COLOR_BLACK, COLOR_BLUE);
	box(stdscr, 0, 0);
	refresh();

	nivel_gui_get_term_size(&rows, &cols);
	secwin = newwin(rows - 3, cols, 0, 0);
	box(secwin, 0, 0);
	wrefresh(secwin);

	NIVEL_GUI_ITEMS = list_create();

	inicializado = 1;

	return NGUI_SUCCESS;

}

int nivel_gui_dibujar(char* nombre_nivel) {

	if (!nivel_gui_int_validar_inicializado()) {
		return NGUI_NO_INIT;
	}

	int i = 0;
	werase(secwin);
	box(secwin, 0, 0);
	wbkgd(secwin, COLOR_PAIR(1));

	move(rows - 3, 2);
	printw("Nivel: %s - Tamanio: %dx%d", nombre_nivel, cols - 2, rows - 5);
	move(rows - 2, 2);
	printw("Recursos: ");

	void _draw_element(ITEM_NIVEL* item) {
		wmove(secwin, item->posy, item->posx);
		if(item->item_type == ENEMIGO_ITEM_TYPE) {
			waddch(secwin, '*' | COLOR_PAIR(4));
		} else if (item->item_type == RECURSO_ITEM_TYPE) {
			waddch(secwin, item->id | COLOR_PAIR(3));
		} else if(item->item_type == PERSONAJE_ITEM_TYPE) {
			waddch(secwin, item->id | COLOR_PAIR(2));
		}
		if (item->item_type == RECURSO_ITEM_TYPE) {
			move(rows - 2, 7 * i + 3 + 9);
			printw("%c: %d - ", item->id, item->quantity);
			i++;
		}
	}

	list_iterate(NIVEL_GUI_ITEMS, (void*) _draw_element);

	wrefresh(secwin);
	wrefresh(mainwin);

	return NGUI_SUCCESS;

}

int nivel_gui_terminar(void) {
	list_destroy_and_destroy_elements(NIVEL_GUI_ITEMS, (void*) free);

	if (!nivel_gui_int_validar_inicializado()) {
		return NGUI_NO_INIT;
	}

	delwin(mainwin);
	delwin(secwin);
	endwin();
	refresh();

	return NGUI_SUCCESS;

}

int nivel_gui_get_area_nivel(int * cols, int * rows) {

	if (!nivel_gui_int_validar_inicializado()) {
		return NGUI_NO_INIT;
	}

	nivel_gui_get_term_size(rows, cols);
	if(rows) *rows = *rows - 5;
	if(cols) *cols = *cols - 2;

	return EXIT_SUCCESS;
}

char* nivel_gui_string_error(int errnum) {
	switch ( errnum ) {
		case NGUI_SUCCESS:
			return "Exito.";
		case NGUI_ITEM_NOT_FOUND: 
			return "No se encontro el item.";
		case NGUI_ITEM_ALREADY_EXISTS: 
			return "El item ya existe.";
		case NGUI_NOT_RECURSO_ITEM: 
			return "El item no es un recurso.";
		case NGUI_ITEM_INVALID_POSITION: 
			return "La posicion se encuentra fuera del tablero.";
		case NGUI_ITEM_INVALID_CANT: 
			return "La cantidad de elementos recibida no es valida.";
		case NGUI_EMPTY_RECURSO: 
			return "El recurso se encuentra vacio.";
		case NGUI_NO_INIT:
			return "Library no inicializada.";
		case NGUI_ALREADY_INIT:
			return "Library ya inicializada.";
		default:
			return "Desconocido.";
	}
}

/*---------------- Funciones utilitarias ----------------*/

void nivel_gui_get_term_size(int * rows, int * cols) {

	struct winsize ws;

	if ( ioctl(0, TIOCGWINSZ, &ws) < 0 ) {
		perror("couldn't get window size");
		return;
	}

	if(rows) *rows = ws.ws_row;
	if(cols) *cols = ws.ws_col;
}

int nivel_gui_int_validar_inicializado(void) {
	return inicializado;
}
