#ifndef __NIVEL_H__

#define __NIVEL_H__

#define PERSONAJE_ITEM_TYPE 0
#define RECURSO_ITEM_TYPE 1
#define ENEMIGO_ITEM_TYPE 2

#include <commons/collections/list.h>

typedef struct item {
	char id;
	int posx;
	int posy;
	char item_type; // PERSONAJE o CAJA_DE_RECURSOS
	int quantity;
} ITEM_NIVEL;


int nivel_gui_dibujar(t_list* items, char* nombre_nivel);
int nivel_gui_terminar(void);
int nivel_gui_inicializar(void);
int nivel_gui_get_area_nivel(int * filas, int * columnas);

#endif 
