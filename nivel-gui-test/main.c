
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
        exit(EXIT_FAILURE);                                                             \
    }

/*
 * @NAME: rnd
 * @DESC: Retorna un entero en el rango [-1, 1]
 */
int rnd() {
	return (rand() % 3) - 1;
}

/*
 * @NAME: dibujar_ejemplo_colores
 * @DESC: Escribe arriba a la derecha un ejemplo de uso de los distintos colores
 */
void dibujar_ejemplo_colores(NIVEL* nivel, int cols, int rows);

int main(void) {
	NIVEL* nivel;

	int cols, rows;
	int err;

	nivel_gui_inicializar();

	nivel_gui_get_area_nivel(&cols, &rows);

	nivel = nivel_crear("Test Chamber 04");
	dibujar_ejemplo_colores(nivel, cols, rows);

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

void dibujar_ejemplo_colores(NIVEL* nivel, int cols, int rows) {
	int err;

	err = item_crear(
		nivel, 
		(ITEM_NIVEL) {
			.id = '3',
			.posx = cols - 9,
			.posy = 0,
			.show = 'N',
			.color = NGUI_BLACK,
			.srcs = -1
		}
	);
	ASSERT_CREATE(nivel, '3', err);

	err = item_crear(
		nivel, 
		(ITEM_NIVEL) {
			.id = '4',
			.posx = cols - 8,
			.posy = 0,
			.show = 'I',
			.color = NGUI_YELLOW,
			.srcs = -1
		}
	);
	ASSERT_CREATE(nivel, '4', err);

	err = item_crear(
		nivel, 
		(ITEM_NIVEL) {
			.id = '5',
			.posx = cols - 7,
			.posy = 0,
			.show = 'V',
			.color = NGUI_BLUE,
			.srcs = -1
		}
	);
	ASSERT_CREATE(nivel, '5', err);

    err = item_crear(
		nivel, 
		(ITEM_NIVEL) {
			.id = '6',
			.posx = cols - 6,
			.posy = 0,
			.show = 'E',
			.color = NGUI_RED,
			.srcs = -1
		}
	);
	ASSERT_CREATE(nivel, '6', err);

	err = item_crear(
		nivel, 
		(ITEM_NIVEL) {
			.id = '7',
			.posx = cols - 5,
			.posy = 0,
			.show = 'L',
			.color = NGUI_GREEN,
			.srcs = -1
		}
	);
	ASSERT_CREATE(nivel, '7', err);

	err = item_crear(
		nivel, 
		(ITEM_NIVEL) {
			.id = '8',
			.posx = cols - 4,
			.posy = 0,
			.show = 'G',
			.color = NGUI_MAGENTA,
			.srcs = -1
		}
	);
	ASSERT_CREATE(nivel, '8', err);

	err = item_crear(
		nivel, 
		(ITEM_NIVEL) {
			.id = '9',
			.posx = cols - 3,
			.posy = 0,
			.show = 'U',
			.color = NGUI_CYAN,
			.srcs = -1
		}
	);
	ASSERT_CREATE(nivel, '9', err);

	err = item_crear(
		nivel, 
		(ITEM_NIVEL) {
			.id = '0',
			.posx = cols - 2,
			.posy = 0,
			.show = 'I',
			.color = NGUI_WHITE,
			.srcs = -1
		}
	);
	ASSERT_CREATE(nivel, '0', err);
}