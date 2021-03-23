#ifndef __TAD_ITEMS__
#define __TAD_ITEMS__

	#include "nivel.h"
	#include <commons/collections/list.h>

	/*
	* @NAME: crear_personaje
	* @DESC: 
	* @PARAMS:
	*/
	void crear_personaje(char id, int x , int y);
	
	/*
	* @NAME: crear_enemigo
	* @DESC: 
	* @PARAMS:
	*/
	void crear_enemigo(char id, int x , int y);
	
	/*
	* @NAME: crear_caja
	* @DESC: 
	* @PARAMS:
	*/
	void crear_caja(char id, int x , int y, int cant);

	/*
	* @NAME: borrar_item
	* @DESC: 
	* @PARAMS:
	*/
	void borrar_item(char id);

	/*
	* @NAME: mover_item
	* @DESC: 
	* @PARAMS:
	*/
	void mover_item(char id, int x, int y);

	/*
	* @NAME: desplazar_item
	* @DESC: 
	* @PARAMS:
	*/
	void desplazar_item(char id, int x, int y);

	/*
	* @NAME: restar_recurso
	* @DESC: 
	* @PARAMS:
	*/
	void restar_recurso(char id);
	
	/*
	* @NAME: sumar_recurso
	* @DESC: 
	* @PARAMS:
	*/
	void sumar_recurso(char id);

	/*
	* @NAME: items_chocan
	* @DESC: 
	* @PARAMS:
	*/
	bool items_chocan(char id1, char id2);

#endif

