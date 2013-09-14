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

void nivel_gui_get_term_size(int * filas, int * columnas);
int nivel_gui_int_validar_inicializado(void);
void nivel_gui_print_perror(const char* mensaje);

// ------------------------------------------------------

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
 * 		nombre_nivel - nombre del nivel
 */
int nivel_gui_dibujar(t_list* items, char* nombre_nivel) {

	if (!nivel_gui_int_validar_inicializado()){
		nivel_gui_print_perror("nivel_gui_dibujar: Library no inicializada!");
		return EXIT_FAILURE;
	}

	if (items == NULL){
		nivel_gui_print_perror("nivel_gui_dibujar: La lista de items no puede ser NULL");
		return EXIT_FAILURE;
	}

	int i = 0;
	werase(secwin);
	box(secwin, 0, 0);
	wbkgd(secwin, COLOR_PAIR(1));

	move(rows - 3, 2);
	printw("Nivel: %s", nombre_nivel);
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
        
        list_iterate(items, (void*) _draw_element);
       
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



