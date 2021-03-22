#ifndef __TAD_ITEMS__
#define __TAD_ITEMS__

	#include "nivel.h"
	#include <commons/collections/list.h>

	/*
	* @NAME: CrearItem
	* @DESC: 
	* @PARAMS:
	*/
	void CrearItem(t_list* items, char id, int x, int y, char tipo, int cant);

	/*
	* @NAME: CrearPersonaje
	* @DESC: 
	* @PARAMS:
	*/
	void CrearPersonaje(t_list* items, char id, int x , int y);
	
	/*
	* @NAME: CrearEnemigo
	* @DESC: 
	* @PARAMS:
	*/
	void CrearEnemigo(t_list* items, char id, int x , int y);
	
	/*
	* @NAME: CrearCaja
	* @DESC: 
	* @PARAMS:
	*/
	void CrearCaja(t_list* items, char id, int x , int y, int cant);

	/*
	* @NAME: BorrarItem
	* @DESC: 
	* @PARAMS:
	*/
	void BorrarItem(t_list* items, char id);

	/*
	* @NAME: MoverPersonaje
	* @DESC: 
	* @PARAMS:
	*/
	void MoverPersonaje(t_list* items, char personaje, int x, int y);

	/*
	* @NAME: MoverEnemigo
	* @DESC: 
	* @PARAMS:
	*/
	void MoverEnemigo(t_list* items, char personaje, int x, int y);

	/*
	* @NAME: restarRecurso
	* @DESC: 
	* @PARAMS:
	*/
	void restarRecurso(t_list* items, char id);
	
	/*
	* @NAME: sumarRecurso
	* @DESC: 
	* @PARAMS:
	*/
	void sumarRecurso(t_list* items, char id);

#endif

