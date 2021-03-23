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

	/*
	* @NAME: nivel_gui_inicializar
	* @DESC: Inicializa el espacio de dibujo
	*/
	int nivel_gui_inicializar(void);

	/*
	* @NAME: nivel_gui_dibujar
	* @DESC: Dibuja cada entidad en la lista de items
	* @PARAMS:
	*       items        - lista de objetos a dibujar
	*       nombre_nivel - nombre del nivel
	*/
	int nivel_gui_dibujar(char* nombre_nivel);

	/*
	* @NAME: nivel_gui_terminar
	* @DESC: Termina el nivel de forma prolija
	*/
	int nivel_gui_terminar(void);

	/*
	* @NAME: nivel_gui_get_area_nivel
	* @DESC: Devuelve el tamanio usable de la pantalla 
	* @PARAMS:
	*       columnas - valor de retorno de columnas
	*       filas    - valor de retorno de filas
	*/
	int nivel_gui_get_area_nivel(int * columnas, int * filas);

#endif 
