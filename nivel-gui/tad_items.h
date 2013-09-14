#ifndef __TAD_ITEMS__

#define __TAD_ITEMS__

#include "nivel.h"
#include <commons/collections/list.h>

void BorrarItem(t_list* items, char id);
void restarRecurso(t_list* items, char id);
void MoverPersonaje(t_list* items, char personaje, int x, int y);
void MoverEnemigo(t_list* items, char personaje, int x, int y);
void CrearPersonaje(t_list* items, char id, int x , int y);
void CrearEnemigo(t_list* items, char id, int x , int y);
void CrearCaja(t_list* items, char id, int x , int y, int cant);
void CrearItem(t_list* items, char id, int x, int y, char tipo, int cant);

#endif

