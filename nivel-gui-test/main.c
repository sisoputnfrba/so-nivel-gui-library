
#include <tad_items.h>

#include <stdlib.h>
#include <curses.h>
#include <commons/collections/list.h>
/*
 * @NAME: rnd
 * @DESC: Modifica el numero en +1,0,-1, sin pasarse del maximo dado
 */
void rnd(int *x, int max) {
	*x += (rand() % 3) - 1;
	*x = (*x<max) ? *x : max-1;
	*x = (*x>0) ? *x : 1;
}

int main(void) {
	t_list* items = list_create();

	int rows, cols;
	int q, p;

	int x = 1;
	int y = 1;

	int ex1 = 10, ey1 = 14;
	int ex2 = 20, ey2 = 3;

	nivel_gui_inicializar();

	nivel_gui_get_area_nivel(&rows, &cols);

	p = cols;
	q = rows;

	crear_personaje(items, '@', p, q);
	crear_personaje(items, '#', x, y);

	crear_enemigo(items, '1', ex1, ey1);
	crear_enemigo(items, '2', ex2, ey2);

	crear_caja(items, 'H', 26, 10, 5); 
	crear_caja(items, 'M', 8, 15, 3);
	crear_caja(items, 'F', 19, 9, 2);

	nivel_gui_dibujar(items, "Test Chamber 04");

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

		rnd(&ex1, cols);
		rnd(&ey1, rows);
		rnd(&ex2, cols);
		rnd(&ey2, rows);
		mover_personaje(items, '1', ex1, ey1 );
		mover_personaje(items, '2', ex2, ey2 );

		mover_personaje(items, '@', p, q);
		mover_personaje(items, '#', x, y);

		if (   ((p == 26) && (q == 10)) || ((x == 26) && (y == 10)) ) {
			restar_recurso(items, 'H');
		}

		if (   ((p == 19) && (q == 9)) || ((x == 19) && (y == 9)) ) {
			restar_recurso(items, 'F');
		}

		if (   ((p == 8) && (q == 15)) || ((x == 8) && (y == 15)) ) {
			restar_recurso(items, 'M');	
		}

		if((p == x) && (q == y)) {
			borrar_item(items, '#'); //si chocan, borramos uno (!)
		}

		nivel_gui_dibujar(items, "Test Chamber 04");
	}

	borrar_item(items, '#');
	borrar_item(items, '@');

	borrar_item(items, '1');
	borrar_item(items, '2');

	borrar_item(items, 'H');
	borrar_item(items, 'M');
	borrar_item(items, 'F');

	nivel_gui_terminar();

}
