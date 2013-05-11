#include "tad_items.h"

#include <stdlib.h>
#include <curses.h>

int main(void) {

	ITEM_NIVEL* ListaItems = NULL;

	int rows, cols;
	int q, p;

	int x = 1;
	int y = 1;

	nivel_gui_inicializar();

    nivel_gui_get_area_nivel(&rows, &cols);

	p = cols;
	q = rows;

	CrearPersonaje(&ListaItems, '@', p, q);
	CrearPersonaje(&ListaItems, '#', x, y);

	CrearCaja(&ListaItems, 'H', 26, 10, 5); 
	CrearCaja(&ListaItems, 'M', 8, 15, 3);
	CrearCaja(&ListaItems, 'F', 19, 9, 2);

	nivel_gui_dibujar(ListaItems);

	while ( 1 ) {
		int key = getch();

		switch( key ) {

			case KEY_UP:
				if (y > 1) {
					y--;
				}
			break;

			case KEY_DOWN:
				if (y < rows) {
					y++;
				}
			break;

			case KEY_LEFT:
				if (x > 1) {
					x--;
				}
			break;
			case KEY_RIGHT:
				if (x < cols) {
					x++;
				}
			break;
			case 'w':
			case 'W':
				if (q > 1) {
					q--;
				}
			break;

			case 's':
			case 'S':
				if (q < rows) {
					q++;
				}
			break;

			case 'a':
			case 'A':
				if (p > 1) {
					p--;
				}
			break;
			case 'D':
			case 'd':
				if (p < cols) {
					p++;
				}
			break;
			case 'Q':
			case 'q':
				nivel_gui_terminar();
				exit(0);
			break;
		}

		MoverPersonaje(ListaItems, '@', p, q);
		MoverPersonaje(ListaItems, '#', x, y);

		if (   ((p == 26) && (q == 10)) || ((x == 26) && (y == 10)) ) {
			restarRecurso(ListaItems, 'H');
		}

		if (   ((p == 19) && (q == 9)) || ((x == 19) && (y == 9)) ) {
			restarRecurso(ListaItems, 'F');
		}

		if (   ((p == 8) && (q == 15)) || ((x == 8) && (y == 15)) ) {
			restarRecurso(ListaItems, 'M');	
		}

		if((p == x) && (q == y)) {
			BorrarItem(&ListaItems, '#'); //si chocan, borramos uno (!)
		}

		nivel_gui_dibujar(ListaItems);
	}

	BorrarItem(&ListaItems, '#');
	BorrarItem(&ListaItems, '@');
	BorrarItem(&ListaItems, 'H');
	BorrarItem(&ListaItems, 'M');
	BorrarItem(&ListaItems, 'F');

	nivel_gui_terminar();

}
