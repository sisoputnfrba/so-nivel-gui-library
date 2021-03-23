#ifndef __TAD_ITEMS__
#define __TAD_ITEMS__

	#include "nivel.h"
	#include <commons/collections/list.h>

	/*
	* @NAME: crear_personaje
	* @DESC: Crea una instancia de personaje que se mostrará
	* en el mapa con el caracter que lo identifica en color 
	* blanco y fondo en negro.
	* @PARAMS:
	*     id - identificador único de acceso
	*     x  - posición inicial en x
	*     y  - posición inicial en y
	*/
	int crear_personaje(char id, int x , int y);
	
	/*
	* @NAME: crear_enemigo
	* @DESC: Crea una instancia de enemigo que se mostrará
	* en el mapa con el caracter '*' en color negro y fondo
	* en azul.
	* @PARAMS:
	*     id - identificador único de acceso
	*     x  - posición inicial en x
	*     y  - posición inicial en y
	*/
	int crear_enemigo(char id, int x , int y);
	
	/*
	* @NAME: crear_caja
	* @DESC: Crea una instancia de caja que se mostrará en
	* el mapa con el caracter que lo identifica en color negro
	* y fondo en amarillo.
	* @PARAMS:
	* @PARAMS:
	*     id   - identificador único de acceso
	*     x    - posición inicial en x
	*     y    - posición inicial en y
	*     cant - cantidad inicial de recursos contenidos en la caja
	*/
	int crear_caja(char id, int x , int y, int cant);

	/*
	* @NAME: borrar_item
	* @DESC: Elimina un item que se encuentre en el mapa.
	* @PARAMS:
	*     id - identificador único de acceso
	*/
	int borrar_item(char id);

	/*
	* @NAME: mover_item
	* @DESC: Mueve el item a la posición indicada. En caso de 
	* moverse fuera de la pantalla, no realiza ninguna acción.
	* @PARAMS:
	*     id - identificador único de acceso
	*     x  - nueva posición en x
	*     y  - nueva posición en y
	*/
	int mover_item(char id, int x, int y);

	/*
	* @NAME: desplazar_item
	* @DESC: Desplaza el item tomando a su posición actual
	* como pivote. En caso de desplazarse fuera de la pantalla, 
	* no realiza ninguna acción.
	* @PARAMS:
	*     id - identificador único de acceso
	*     x  - desplazamiento en x
	*     y  - desplazamiento en y
	*/
	int desplazar_item(char id, int x, int y);

	/*
	* @NAME: restar_recurso
	* @DESC: Quita un recurso de la caja. Si la caja está
	* vacía, no realiza ninguna acción.
	* @PARAMS:
	*     id - identificador único de acceso
	*/
	int restar_recurso(char id);
	
	/*
	* @NAME: sumar_recurso
	* @DESC: Agrega un recurso a la caja.
	* @PARAMS:
	*     id - identificador único de acceso
	*/
	int sumar_recurso(char id);

	/*
	* @NAME: items_chocan
	* @DESC: Devuelve true si ambos items se encuentran
	* en la misma posición
	* @PARAMS:
	*     id1 - identificador único de acceso del ítem 1
	*     id2 - identificador único de acceso del ítem 2
	*/
	bool items_chocan(char id1, char id2);

#endif

