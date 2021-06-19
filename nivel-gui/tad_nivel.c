
#include "tad_nivel.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

ITEM_NIVEL* _search_item_by_id(NIVEL* nivel, char id);
int _cambiar_posicion(ITEM_NIVEL* item, int x, int y);
bool _validar_posicion(int x, int y);

NIVEL* nivel_crear(char* nombre) {
	NIVEL* nivel = malloc(sizeof(NIVEL));
	
	nivel->nombre = string_duplicate(nombre);
	nivel->items = list_create();

	return nivel;
}

void nivel_destruir(NIVEL* nivel) {
	list_destroy_and_destroy_elements(nivel->items, (void*) free);
	free(nivel->nombre);
	free(nivel);
}

int item_crear(NIVEL* nivel, ITEM_NIVEL item) {
	if(!_validar_posicion(item.posx, item.posy)) {
		return NGUI_ITEM_INVALID_POSITION;
	}

	if (_search_item_by_id(nivel, item.id) != NULL) {
		return NGUI_ITEM_ALREADY_EXISTS;
	}

	ITEM_NIVEL* new_item = malloc(sizeof(ITEM_NIVEL));
	*new_item = item;
	list_add(nivel->items, new_item);

	return NGUI_SUCCESS;
}

int personaje_crear(NIVEL* nivel, char id, int x , int y) {
	return item_crear(
		nivel, 
		(ITEM_NIVEL) {
			.id = id,
			.posx = x,
			.posy = y,
			.show = id,
			.color = NGUI_BLACK,
			.srcs = -1
		}
	);
}

int enemigo_crear(NIVEL* nivel, char id, int x , int y) {
	return item_crear(
		nivel, 
		(ITEM_NIVEL) {
			.id = id,
			.posx = x,
			.posy = y,
			.show = '*',
			.color = NGUI_BLUE,
			.srcs = -1
		}
	);
}

int caja_crear(NIVEL* nivel, char id, int x, int y, int cant) {
	if(cant < 0) {
		return NGUI_ITEM_INVALID_SRCS;
	}
	return item_crear(
		nivel, 
		(ITEM_NIVEL) {
			.id = id,
			.posx = x,
			.posy = y,
			.show = id,
			.color = NGUI_YELLOW,
			.srcs = cant
		}
	);
}

int item_borrar(NIVEL* nivel, char id) {
	bool found = false;
	bool _search_by_id(ITEM_NIVEL* item) {
		found = item->id == id;
		return found;
	}
	list_remove_and_destroy_by_condition(nivel->items, (void*) _search_by_id, (void*) free);

	return found ? NGUI_SUCCESS : NGUI_ITEM_NOT_FOUND;
}

int item_mover(NIVEL* nivel, char id, int x, int y) {
	ITEM_NIVEL* item = _search_item_by_id(nivel, id);

	if (item == NULL) {
		return NGUI_ITEM_NOT_FOUND;
	}

	return _cambiar_posicion(item, x, y);
}

int item_desplazar(NIVEL* nivel, char id, int offset_x, int offset_y) {
	ITEM_NIVEL* item = _search_item_by_id(nivel, id);

	if (item == NULL) {
		return NGUI_ITEM_NOT_FOUND;
	}

	return _cambiar_posicion(item, item->posx + offset_x, item->posy + offset_y);
}

int caja_quitar_recurso(NIVEL* nivel, char id) {
	ITEM_NIVEL* item = _search_item_by_id(nivel, id);

	if (item == NULL) {
		return NGUI_ITEM_NOT_FOUND;
	}

	if(item->srcs == -1) {
		return NGUI_ITEM_NOT_A_BOX;
	}

	if(item->srcs == 0) {
		return NGUI_ITEM_EMPTY_BOX;
	}

	item->srcs--;
	
	return NGUI_SUCCESS;
}

int caja_agregar_recurso(NIVEL* nivel, char id) {
	ITEM_NIVEL* item = _search_item_by_id(nivel, id);

	if (item == NULL) {
		return NGUI_ITEM_NOT_FOUND;
	}

	if(item->srcs == -1) {
		return NGUI_ITEM_NOT_A_BOX;
	}

	item->srcs++;
	
	return NGUI_SUCCESS;
}

bool items_chocan(NIVEL* nivel, char id1, char id2) {
	ITEM_NIVEL* item1 = _search_item_by_id(nivel, id1);
	ITEM_NIVEL* item2 = _search_item_by_id(nivel, id2);
	if(item1 == NULL || item2 == NULL) {
		return false;
	} else {
		return (item1->posx == item2->posx) && (item1->posy == item2->posy);
	}
}

ITEM_NIVEL* _search_item_by_id(NIVEL* nivel, char id) {
	bool _search_by_id(ITEM_NIVEL* item) {
		return item->id == id;
	}

	return list_find(nivel->items, (void*) _search_by_id);
}

int _cambiar_posicion(ITEM_NIVEL* item, int x, int y) {
	if (!_validar_posicion(x, y)) {
		return NGUI_ITEM_INVALID_POSITION;
	}
	
	item->posx = x;
	item->posy = y;

	return NGUI_SUCCESS;
}

bool _validar_posicion(int x, int y) {
	if(x < 0 || y < 0) {
		return false;
	}

	int columnas, filas;
	nivel_gui_get_area_nivel(&columnas, &filas);

	if(x >= columnas || y >= filas) {
		return false;
	}

	return true;
}