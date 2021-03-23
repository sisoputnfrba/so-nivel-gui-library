
#include <nivel-gui/nivel.h>
#include <nivel-gui/tad_items.h>

#include <stdlib.h>
#include <curses.h>
#include <commons/collections/list.h>

#define ASSERT_CREATE(id, err)                                                          \
    if(err) {                                                                           \
        nivel_gui_terminar();                                                           \
        fprintf(stderr, "Error al crear '%c': %s\n", id, nivel_gui_string_error(err));  \
        return EXIT_FAILURE;                                                            \
    }

/*
 * @NAME: rnd
 * @DESC: Retorna un entero en el rango [-1, 1]
 */
int rnd() {
	return (rand() % 3) - 1;
}

int main(void) {
	int cols, rows;
	int err;

	nivel_gui_inicializar();

	nivel_gui_get_area_nivel(&cols, &rows);

	err = crear_personaje('@', cols - 1, rows - 1);
	ASSERT_CREATE('@', err);

	err = crear_personaje('#', 0, 0);
	ASSERT_CREATE('#', err);
	
	err = crear_enemigo('1', 10, 14);
	ASSERT_CREATE('1', err);

	err = crear_enemigo('2', 20, 3);
	ASSERT_CREATE('2', err);

	err = crear_caja('H', 26, 10, 5); 
	ASSERT_CREATE('H', err);

	err = crear_caja('M', 8, 15, 3);
	ASSERT_CREATE('M', err);
	
	err = crear_caja('F', 19, 9, 2);
	ASSERT_CREATE('F', err);

	while ( 1 ) {
		nivel_gui_dibujar("Test Chamber 04");

		int key = getch();

		switch( key ) {

			case KEY_UP:
				err = desplazar_item('#', 0, -1);
			break;

			case KEY_DOWN:
				err = desplazar_item('#', 0, 1);
			break;

			case KEY_LEFT:
				err = desplazar_item('#', -1, 0);
			break;
			case KEY_RIGHT:
				err = desplazar_item('#', 1, 0);
			break;

			case 'w':
			case 'W':
				err = desplazar_item('@', 0, -1);
			break;

			case 's':
			case 'S':
				err = desplazar_item('@', 0, 1);
			break;

			case 'a':
			case 'A':
				err = desplazar_item('@', -1, 0);
			break;

			case 'D':
			case 'd':
				err = desplazar_item('@', 1, 0);
			break;
			
			case 'Q':
			case 'q':
				err = nivel_gui_terminar();
				exit(0);
			break;
		}

		if(err) {
			printf("WARN: %s\n", nivel_gui_string_error(err));
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
	}

	nivel_gui_terminar();

}
