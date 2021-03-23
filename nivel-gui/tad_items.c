
#include "tad_items.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

extern t_list* NIVEL_GUI_ITEMS;

void _crear_item(char id, int x, int y, char tipo, int cant);
ITEM_NIVEL* _search_item_by_id(char id);
void _cambiar_posicion(ITEM_NIVEL* item, int x, int y);
bool _validar_posicion(int x, int y);

void crear_personaje(char id, int x , int y) {
	_crear_item(id, x, y, PERSONAJE_ITEM_TYPE, 0);
}

void crear_enemigo(char id, int x , int y) {
	_crear_item(id, x, y, ENEMIGO_ITEM_TYPE, 0);
}

void crear_caja(char id, int x , int y, int cant) {
	_crear_item(id, x, y, RECURSO_ITEM_TYPE, cant);
}

void borrar_item(char id) {
	bool _search_by_id(ITEM_NIVEL* item) {
		return item->id == id;
	}
	list_remove_and_destroy_by_condition(NIVEL_GUI_ITEMS, (void*) _search_by_id, (void*) free);
}

void mover_item(char id, int x, int y) {
	ITEM_NIVEL* item = _search_item_by_id(id);

	if (item == NULL) {
		printf("WARN: Item %c no existente\n", id);
		return;
	}

	_cambiar_posicion(item, x, y);
}

void desplazar_item(char id, int x, int y) {
	ITEM_NIVEL* item = _search_item_by_id(id);

	if (item == NULL) {
		printf("WARN: Item %c no existente\n", id);
		return;
	}

	_cambiar_posicion(item, item->posx + x, item->posy + y);
}

void restar_recurso(char id) {
	ITEM_NIVEL* item = _search_item_by_id(id);

	if (item != NULL) {
		item->quantity = item->quantity > 0 ? item->quantity - 1 : 0;
	} else {
		printf("WARN: Item %c no existente\n", id);
	}
}
void sumar_recurso(char id) {
	ITEM_NIVEL* item = _search_item_by_id(id);

	if (item != NULL) {
		item->quantity++;
	} else {
		printf("WARN: Item %c no existente\n", id);
	}
}

bool items_chocan(char id1, char id2) {
	ITEM_NIVEL* item1 = _search_item_by_id(id1);
	ITEM_NIVEL* item2 = _search_item_by_id(id2);
	if(item1 == NULL || item2 == NULL) {
		return false;
	} else {
		return (item1->posx == item2->posx) && (item1->posy == item2->posy);
	}
}

void _crear_item(char id, int x , int y, char tipo, int cant_rec) {
	ITEM_NIVEL * item = malloc(sizeof(ITEM_NIVEL));

	item->id = id;
	item->posx=x;
	item->posy=y;
	item->item_type = tipo;
	item->quantity = cant_rec;

	list_add(NIVEL_GUI_ITEMS, item);
}

ITEM_NIVEL* _search_item_by_id(char id) {
	bool _search_by_id(ITEM_NIVEL* item) {
		return item->id == id;
	}

	return list_find(NIVEL_GUI_ITEMS, (void*) _search_by_id);
}

void _cambiar_posicion(ITEM_NIVEL* item, int x, int y) {
	if (_validar_posicion(x, y)) {
		item->posx = x;
		item->posy = y;
	}
}

bool _validar_posicion(int x, int y) {
	if(x < 1 || y < 1) {
		return false;
	}

	int columnas, filas;
	nivel_gui_get_area_nivel(&columnas, &filas);

	if(x > columnas || y > filas) {
		return false;
	}

	return true;
}