
#include <nivel-gui/nivel-gui.h>
#include <nivel-gui/tad_nivel.h>

#include <stdlib.h>
#include <curses.h>
#include <commons/collections/list.h>

#define ASSERT_CREATE(nivel, id, err)                                                   \
    if(err) {                                                                           \
        nivel_destruir(nivel);                                                          \
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
	NIVEL* nivel;

	int cols, rows;
	int err;

	nivel_gui_inicializar();

	nivel_gui_get_area_nivel(&cols, &rows);

	nivel = nivel_crear("Test Chamber 04");

	err = personaje_crear(nivel, '@', cols - 1, rows - 1);
	ASSERT_CREATE(nivel, '@', err);

	err = personaje_crear(nivel, '#', 0, 0);
	ASSERT_CREATE(nivel, '#', err);

	err = enemigo_crear(nivel, '1', 10, 14);
	ASSERT_CREATE(nivel, '1', err);

	err = enemigo_crear(nivel, '2', 20, 3);
	ASSERT_CREATE(nivel, '2', err);

	err = caja_crear(nivel, 'H', 26, 10, 5); 
	ASSERT_CREATE(nivel, 'H', err);

	err = caja_crear(nivel, 'M', 8, 15, 3);
	ASSERT_CREATE(nivel, 'M', err);

	err = caja_crear(nivel, 'F', 19, 9, 2);
	ASSERT_CREATE(nivel, 'F', err);

	while ( 1 ) {
		nivel_gui_dibujar(nivel);

		int key = getch();

		switch( key ) {

			case KEY_UP:
				err = item_desplazar(nivel, '#', 0, -1);
			break;

			case KEY_DOWN:
				err = item_desplazar(nivel, '#', 0, 1);
			break;

			case KEY_LEFT:
				err = item_desplazar(nivel, '#', -1, 0);
			break;
			case KEY_RIGHT:
				err = item_desplazar(nivel, '#', 1, 0);
			break;

			case 'w':
			case 'W':
				err = item_desplazar(nivel, '@', 0, -1);
			break;

			case 's':
			case 'S':
				err = item_desplazar(nivel, '@', 0, 1);
			break;

			case 'a':
			case 'A':
				err = item_desplazar(nivel, '@', -1, 0);
			break;

			case 'D':
			case 'd':
				err = item_desplazar(nivel, '@', 1, 0);
			break;
			
			case 'Q':
			case 'q':
				nivel_destruir(nivel);
				nivel_gui_terminar();
				return EXIT_SUCCESS;
			break;
		}

		if(err) {
			printf("WARN: %s\n", nivel_gui_string_error(err));
		}

		item_desplazar(nivel, '1', rnd(), rnd());
		item_desplazar(nivel, '2', rnd(), rnd());

		if (items_chocan(nivel, 'H', '@') || items_chocan(nivel, 'H', '#')) {
			caja_quitar_recurso(nivel, 'H');
		}

		if (items_chocan(nivel, 'F', '@') || items_chocan(nivel, 'F', '#')) {
			caja_quitar_recurso(nivel, 'F');
		}

		if (items_chocan(nivel, 'M', '@') || items_chocan(nivel, 'M', '#')) {
			caja_quitar_recurso(nivel, 'M');	
		}

		if(items_chocan(nivel, '#', '@')) {
			item_borrar(nivel, '#');
		}
	}

}
