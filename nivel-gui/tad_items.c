
#include "tad_items.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

extern t_list* NIVEL_GUI_ITEMS;

void _crear_item(char id, int x, int y, char tipo, int cant);
ITEM_NIVEL* _search_item_by_id(char id);

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

void mover_personaje(char id, int x, int y) {
	ITEM_NIVEL* item = _search_item_by_id(id);

	if (item != NULL) {
		item->posx = x;
		item->posy = y;
	} else {
		printf("WARN: Item %c no existente\n", id);
	}
}

void mover_enemigo(char id, int x, int y) {
	mover_personaje(id, x, y);
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
