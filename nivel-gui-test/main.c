
#include <tad_items.h>

#include <stdlib.h>
#include <curses.h>
#include <commons/collections/list.h>
/*
 * @NAME: rnd
 * @DESC: Modifica el numero en +1,0,-1, sin pasarse del maximo dado
 */
int rnd() {
	return (rand() % 3) - 1;
}

int main(void) {
	int cols, rows;

	nivel_gui_inicializar();

	nivel_gui_get_area_nivel(&rows, &cols);

	crear_personaje('@', cols, rows);
	crear_personaje('#', 1, 1);

	crear_enemigo('1', 10, 14);
	crear_enemigo('2', 20, 3);

	crear_caja('H', 26, 10, 5); 
	crear_caja('M', 8, 15, 3);
	crear_caja('F', 19, 9, 2);

	nivel_gui_dibujar("Test Chamber 04");

	while ( 1 ) {
		int key = getch();

		switch( key ) {

			case KEY_UP:
				desplazar_item('#', 0, -1);
			break;

			case KEY_DOWN:
				desplazar_item('#', 0, 1);
			break;

			case KEY_LEFT:
				desplazar_item('#', -1, 0);
			break;
			case KEY_RIGHT:
				desplazar_item('#', 1, 0);
			break;

			case 'w':
			case 'W':
				desplazar_item('@', 0, -1);
			break;

			case 's':
			case 'S':
				desplazar_item('@', 0, 1);
			break;

			case 'a':
			case 'A':
				desplazar_item('@', -1, 0);
			break;
			case 'D':
			case 'd':
				desplazar_item('@', 1, 0);
			break;
			case 'Q':
			case 'q':
				nivel_gui_terminar();
				exit(0);
			break;
		}

		desplazar_item('1', rnd(), rnd());
		desplazar_item('2', rnd(), rnd());

		if (items_chocan('H', '@') || items_chocan('H', '#')) {
			restar_recurso('H');
		}

		if (items_chocan('F', '@') || items_chocan('F', '#')) {
			restar_recurso('F');
		}

		if (items_chocan('M', '@') || items_chocan('M', '#')) {
			restar_recurso('M');	
		}

		if(items_chocan('#', '@')) {
			borrar_item('#');
		}

		nivel_gui_dibujar("Test Chamber 04");
	}

	nivel_gui_terminar();

}
