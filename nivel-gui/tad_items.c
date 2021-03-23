
#include "tad_items.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

extern t_list* NIVEL_GUI_ITEMS;

int _crear_item(char id, int x, int y, char tipo, int cant);
ITEM_NIVEL* _search_item_by_id(char id);
int _cambiar_posicion(ITEM_NIVEL* item, int x, int y);
bool _validar_posicion(int x, int y);

int crear_personaje(char id, int x , int y) {
	return _crear_item(id, x, y, PERSONAJE_ITEM_TYPE, 0);
}

int crear_enemigo(char id, int x , int y) {
	return _crear_item(id, x, y, ENEMIGO_ITEM_TYPE, 0);
}

int crear_caja(char id, int x , int y, int cant) {
	if(cant < 0) {
		return NGUI_ITEM_INVALID_CANT;
	}

	return _crear_item(id, x, y, RECURSO_ITEM_TYPE, cant);
}

int borrar_item(char id) {
	bool found = false;
	bool _search_by_id(ITEM_NIVEL* item) {
		found = item->id == id;
		return found;
	}
	list_remove_and_destroy_by_condition(NIVEL_GUI_ITEMS, (void*) _search_by_id, (void*) free);

	return found;
}

int mover_item(char id, int x, int y) {
	ITEM_NIVEL* item = _search_item_by_id(id);

	if (item == NULL) {
		return NGUI_ITEM_NOT_FOUND;
	}

	return _cambiar_posicion(item, x, y);
}

int desplazar_item(char id, int x, int y) {
	ITEM_NIVEL* item = _search_item_by_id(id);

	if (item == NULL) {
		return NGUI_ITEM_NOT_FOUND;
	}

	return _cambiar_posicion(item, item->posx + x, item->posy + y);
}

int restar_recurso(char id) {
	ITEM_NIVEL* item = _search_item_by_id(id);

	if (item == NULL) {
		return NGUI_ITEM_NOT_FOUND;
	}

	if(item->item_type != RECURSO_ITEM_TYPE) {
		return NGUI_NOT_RECURSO_ITEM;
	}

	if(item->quantity == 0) {
		return NGUI_EMPTY_RECURSO;
	}

	item->quantity--;
	
	return NGUI_SUCCESS;
}

int sumar_recurso(char id) {
	ITEM_NIVEL* item = _search_item_by_id(id);

	if (item == NULL) {
		return NGUI_ITEM_NOT_FOUND;
	}

	if(item->item_type != RECURSO_ITEM_TYPE) {
		return NGUI_NOT_RECURSO_ITEM;
	}

	item->quantity++;
	
	return NGUI_SUCCESS;
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

int _crear_item(char id, int x , int y, char tipo, int cant_rec) {
	if(!_validar_posicion(x, y)) {
		return NGUI_ITEM_INVALID_POSITION;
	}

	if (_search_item_by_id(id) != NULL) {
		return NGUI_ITEM_ALREADY_EXISTS;
	}

	ITEM_NIVEL* item = malloc(sizeof(ITEM_NIVEL));

	item->id = id;
	item->posx=x;
	item->posy=y;
	item->item_type = tipo;
	item->quantity = cant_rec;

	list_add(NIVEL_GUI_ITEMS, item);

	return NGUI_SUCCESS;
}

ITEM_NIVEL* _search_item_by_id(char id) {
	bool _search_by_id(ITEM_NIVEL* item) {
		return item->id == id;
	}

	return list_find(NIVEL_GUI_ITEMS, (void*) _search_by_id);
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