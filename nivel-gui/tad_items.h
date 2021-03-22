#ifndef __TAD_ITEMS__
#define __TAD_ITEMS__

	#include "nivel.h"
	#include <commons/collections/list.h>

	/*
	* @NAME: crear_personaje
	* @DESC: 
	* @PARAMS:
	*/
	void crear_personaje(t_list* items, char id, int x , int y);
	
	/*
	* @NAME: crear_enemigo
	* @DESC: 
	* @PARAMS:
	*/
	void crear_enemigo(t_list* items, char id, int x , int y);
	
	/*
	* @NAME: crear_caja
	* @DESC: 
	* @PARAMS:
	*/
	void crear_caja(t_list* items, char id, int x , int y, int cant);

	/*
	* @NAME: borrar_item
	* @DESC: 
	* @PARAMS:
	*/
	void borrar_item(t_list* items, char id);

	/*
	* @NAME: mover_personaje
	* @DESC: 
	* @PARAMS:
	*/
	void mover_personaje(t_list* items, char personaje, int x, int y);

	/*
	* @NAME: mover_enemigo
	* @DESC: 
	* @PARAMS:
	*/
	void mover_enemigo(t_list* items, char personaje, int x, int y);

	/*
	* @NAME: restar_recurso
	* @DESC: 
	* @PARAMS:
	*/
	void restar_recurso(t_list* items, char id);
	
	/*
	* @NAME: sumar_recurso
	* @DESC: 
	* @PARAMS:
	*/
	void sumar_recurso(t_list* items, char id);

#endif

