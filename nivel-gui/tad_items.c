
#include "tad_items.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

ITEM_NIVEL* _search_item_by_id(t_list* items, char id);

void crear_item(t_list* items, char id, int x , int y, char tipo, int cant_rec) {
	ITEM_NIVEL * item = malloc(sizeof(ITEM_NIVEL));

	item->id = id;
	item->posx=x;
	item->posy=y;
	item->item_type = tipo;
	item->quantity = cant_rec;

	list_add(items, item);
}

void crear_personaje(t_list* items, char id, int x , int y) {
	crear_item(items, id, x, y, PERSONAJE_ITEM_TYPE, 0);
}

void crear_enemigo(t_list* items, char id, int x , int y) {
	crear_item(items, id, x, y, ENEMIGO_ITEM_TYPE, 0);
}

void crear_caja(t_list* items, char id, int x , int y, int cant) {
	crear_item(items, id, x, y, RECURSO_ITEM_TYPE, cant);
}

void borrar_item(t_list* items, char id) {
	bool _search_by_id(ITEM_NIVEL* item) {
		return item->id == id;
	}

	list_remove_by_condition(items, (void*) _search_by_id);
}

void mover_personaje(t_list* items, char id, int x, int y) {
	ITEM_NIVEL* item = _search_item_by_id(items, id);

	if (item != NULL) {
		item->posx = x;
		item->posy = y;
	} else {
		printf("WARN: Item %c no existente\n", id);
	}
}

void mover_enemigo(t_list* items, char id, int x, int y) {
	mover_personaje(items, id, x, y);
}

void restar_recurso(t_list* items, char id) {
	ITEM_NIVEL* item = _search_item_by_id(items, id);

	if (item != NULL) {
		item->quantity = item->quantity > 0 ? item->quantity - 1 : 0;
	} else {
		printf("WARN: Item %c no existente\n", id);
	}
}
void sumar_recurso(t_list* items, char id) {
	ITEM_NIVEL* item = _search_item_by_id(items, id);

	if (item != NULL) {
		item->quantity++;
	} else {
		printf("WARN: Item %c no existente\n", id);
	}
}

ITEM_NIVEL* _search_item_by_id(t_list* items, char id) {
	bool _search_by_id(ITEM_NIVEL* item) {
		return item->id == id;
	}

	return list_find(items, (void*) _search_by_id);
}
