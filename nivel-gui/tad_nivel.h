#ifndef __TAD_ITEMS__
#define __TAD_ITEMS__

	#include "nivel-gui.h"
	#include <commons/collections/list.h>
	#include <commons/string.h>

	/*
	* @NAME: nivel_crear
	* @DESC: Crea una instancia de estructura nivel.
	* @PARAMS:
	*     nombre - nombre del nivel
	*/
	NIVEL* nivel_crear(char* nombre);

	/*
	* @NAME: nivel_destruir
	* @DESC: Libera la memoria ocupada por una estructura nivel 
	* y sus items.
	*/
	void nivel_destruir(NIVEL* nivel);

	/*
	* @NAME: personaje_crear
	* @DESC: Crea una instancia de personaje que se mostrará
	* en el nivel con el caracter que lo identifica en color 
	* blanco y fondo en negro.
	* @PARAMS:
	*     nivel - nivel donde se encontrará el personaje
	*     id    - identificador único de acceso del item
	*     x     - posición inicial en x
	*     y     - posición inicial en y
	*/
	int personaje_crear(NIVEL* nivel, char id, int x , int y);
	
	/*
	* @NAME: enemigo_crear
	* @DESC: Crea una instancia de enemigo que se mostrará
	* en el nivel con el caracter '*' en color negro y fondo
	* en azul.
	* @PARAMS:
	*     nivel - nivel donde se encontrará el enemigo
	*     id    - identificador único de acceso del item
	*     x     - posición inicial en x
	*     y     - posición inicial en y
	*/
	int enemigo_crear(NIVEL* nivel, char id, int x , int y);
	
	/*
	* @NAME: caja_crear
	* @DESC: Crea una instancia de caja que se mostrará en
	* el nivel con el caracter que lo identifica en color negro
	* y fondo en amarillo.
	* @PARAMS:
	* @PARAMS:
	*     nivel - nivel donde se encontrará la caja
	*     id    - identificador único de acceso del item
	*     x     - posición inicial en x
	*     y     - posición inicial en y
	*     srcs  - cantidad inicial de recursos contenidos en la caja
	*/
	int caja_crear(NIVEL* nivel, char id, int x, int y, int srcs);

	/*
	* @NAME: item_borrar
	* @DESC: Elimina un item que se encuentre en el nivel.
	* @PARAMS:
	*     nivel - nivel donde se encuentra el item
	*     id    - identificador único de acceso del item
	*/
	int item_borrar(NIVEL* nivel, char id);

	/*
	* @NAME: item_mover
	* @DESC: Mueve el item a la posición indicada. En caso de 
	* moverse fuera de la pantalla, no realiza ninguna acción.
	* @PARAMS:
	*     nivel - nivel donde se encuentra el item
	*     id    - identificador único de acceso del item
	*     x     - nueva posición en x
	*     y     - nueva posición en y
	*/
	int item_mover(NIVEL* nivel, char id, int x, int y);

	/*
	* @NAME: item_desplazar
	* @DESC: Desplaza el item tomando a su posición actual
	* como pivote. En caso de desplazarse fuera de la pantalla, 
	* no realiza ninguna acción.
	* @PARAMS:
	*     nivel - nivel donde se encuentra el item
	*     id    - identificador único de acceso del item
	*     x     - desplazamiento en x
	*     y     - desplazamiento en y
	*/
	int item_desplazar(NIVEL* nivel, char id, int x, int y);

	/*
	* @NAME: caja_quitar_recurso
	* @DESC: Quita un recurso de la caja. Si la caja está
	* vacía, no realiza ninguna acción.
	* @PARAMS:
	*     nivel - nivel donde se encuentra el item
	*     id    - identificador único de acceso del item
	*/
	int caja_quitar_recurso(NIVEL* nivel, char id);
	
	/*
	* @NAME: caja_agregar_recurso
	* @DESC: Agrega un recurso a la caja.
	* @PARAMS:
	*     nivel - nivel donde se encuentra el item
	*     id    - identificador único de acceso del item
	*/
	int caja_agregar_recurso(NIVEL* nivel, char id);

	/*
	* @NAME: items_chocan
	* @DESC: Devuelve true si ambos items se encuentran
	* en la misma posición
	* @PARAMS:
	*     nivel - nivel donde se encuentra el item
	*     id1   - identificador único de acceso del ítem 1
	*     id2   - identificador único de acceso del ítem 2
	*/
	bool items_chocan(NIVEL* nivel, char id1, char id2);

#endif

