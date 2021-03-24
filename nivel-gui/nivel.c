#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <curses.h>

#include "nivel.h"

static WINDOW * secwin;
static WINDOW * mainwin;
static int rows, cols;
static int inicializado = 0;

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

/*
 * @NAME: nivel_gui_item_show
 * @DESC: Devuelve el caracter a mostrarse en pantalla 
 * segun el item
 */
char nivel_gui_item_show(ITEM_NIVEL* item);

// ------------------------------------------------------

int nivel_gui_inicializar(void) {

	if (nivel_gui_int_validar_inicializado()) {
		return NGUI_ALREADY_INIT;
	}

	mainwin = initscr();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	init_pair(1                  , COLOR_GREEN, COLOR_BLACK);
	init_pair(PERSONAJE_ITEM_TYPE, COLOR_WHITE, COLOR_BLACK);
	init_pair(CAJA_ITEM_TYPE     , COLOR_BLACK, COLOR_YELLOW);
	init_pair(ENEMIGO_ITEM_TYPE  , COLOR_BLACK, COLOR_BLUE);
	box(stdscr, 0, 0);
	refresh();

	nivel_gui_get_term_size(&rows, &cols);
	secwin = newwin(rows - 3, cols, 0, 0);
	box(secwin, 0, 0);
	wrefresh(secwin);

	inicializado = 1;

	return NGUI_SUCCESS;

}

int nivel_gui_dibujar(NIVEL* nivel) {

	if (!nivel_gui_int_validar_inicializado()) {
		return NGUI_NO_INIT;
	}

	char* srcs_text = string_duplicate("Recursos: ");

	werase(secwin);
	box(secwin, 0, 0);
	wbkgd(secwin, COLOR_PAIR(1));

	void _draw_element(ITEM_NIVEL* item) {
		wmove(secwin, item->posy + 1, item->posx + 1);
		waddch(secwin, nivel_gui_item_show(item) | COLOR_PAIR(item->item_type));
		if (item->item_type == CAJA_ITEM_TYPE) {
			string_append_with_format(&srcs_text, "%c: %d - ", item->id, item->quantity);
		}
	}

	list_iterate(nivel->items, (void*) _draw_element);

	move(rows - 3, 2);
	printw("Nivel: %s - Tamanio: %dx%d", nivel->nombre, cols - 2, rows - 5);
	move(rows - 2, 2);
	printw(srcs_text);

	wrefresh(secwin);
	wrefresh(mainwin);

	free(srcs_text);

	return NGUI_SUCCESS;

}

int nivel_gui_terminar(void) {

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

char nivel_gui_item_show(ITEM_NIVEL* item) {
	return item->item_type == ENEMIGO_ITEM_TYPE ? '*' : item->id;
}