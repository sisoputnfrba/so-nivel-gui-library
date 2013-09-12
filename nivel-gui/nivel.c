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

/*
 * @NAME: rnd
 * @DESC: Modifica el numero en +1,0,-1, sin pasarse del maximo dado
 */
void rnd(int *x, int max){
	*x += (rand() % 3) - 1;
	*x = (*x<max) ? *x : max-1;
	*x = (*x>0) ? *x : 1;
}

/*
 * @NAME: nivel_gui_inicializar
 * @DESC: Inicializa el espacio de dibujo
 */
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
	init_pair(4,COLOR_BLACK, COLOR_BLUE);
	box(stdscr, 0, 0);
	refresh();

	nivel_gui_get_term_size(&rows, &cols);
	secwin = newwin(rows - 3, cols, 0, 0);
	box(secwin, 0, 0);
	wrefresh(secwin);

	inicializado = 1;

	return EXIT_SUCCESS;

}

/*
 * @NAME: nivel_gui_dibujar
 * @DESC: Dibuja cada entidad en la lista de items
 * @PARAMS:
 * 		items	  - lista de objetos a dibujar
 * 		nom_nivel - nombre del nivel
 */
int nivel_gui_dibujar(ITEM_NIVEL* items, char* nom_nivel) {

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

	move(rows - 3, 2);
	printw("Nivel: %s", nom_nivel);
	move(rows - 2, 2);
	printw("Recursos: ");

	while (temp != NULL) {
		wmove (secwin, temp->posy, temp->posx);
		if(temp->item_type == ENEMIGO_ITEM_TYPE) {
			waddch(secwin, '*' | COLOR_PAIR(4));
		} else	if (temp->item_type == RECURSO_ITEM_TYPE) {
			waddch(secwin, temp->id | COLOR_PAIR(3));
		} else if(temp->item_type == PERSONAJE_ITEM_TYPE) {
			waddch(secwin, temp->id | COLOR_PAIR(2));
		}
		if (temp->item_type == RECURSO_ITEM_TYPE) {
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

/*
 * @NAME: nivel_gui_terminar
 * @DESC: Termina el nivel de forma prolija
 */
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

/*
 * @NAME: nivel_gui_get_area_nivel
 * @DESC: Devuelve el tamanio de la pantalla usable
 * @PARAMS:
 * 		rows - valor de retorno de filas
 * 		cols - valor de retorno de columnas
 */
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
	*rows = *rows - 5;
	*cols = *cols - 2;

	return EXIT_SUCCESS;
}

/*
 * @NAME: nivel_gui_get_term_size
 * @DESC: Devuelve el tamanio total de la pantalla
 * @PARAMS:
 * 		rows - valor de retorno de filas
 * 		cols - valor de retorno de columnas
 */
void nivel_gui_get_term_size(int * rows, int * cols) {

    struct winsize ws;

    if ( ioctl(0, TIOCGWINSZ, &ws) < 0 ) {
        perror("couldn't get window size");
    }

    *rows = ws.ws_row;
    *cols = ws.ws_col;
}

/*
 * @NAME: nivel_gui_int_validar_inicializado
 * @DESC: Informa si se inicializo el nivel corectamente
 */
int nivel_gui_int_validar_inicializado(void){
	return inicializado;
}

/*
 * @NAME: nivel_gui_print_perror
 * @DESC: Imprime un error en el nivel
 * @PARAMS:
 * 		message - mensaje a imprimir
 */
void nivel_gui_print_perror(const char* message){
	fprintf(stderr, "%s\n", message);
}



