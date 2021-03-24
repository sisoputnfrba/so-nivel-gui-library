#ifndef __NIVEL_H__
#define __NIVEL_H__

	#define PERSONAJE_ITEM_TYPE 0
	#define CAJA_ITEM_TYPE 1
	#define ENEMIGO_ITEM_TYPE 2

	#define NGUI_SUCCESS                0
	#define NGUI_ITEM_NOT_FOUND        -1
	#define NGUI_ITEM_ALREADY_EXISTS   -2
	#define NGUI_NOT_RECURSO_ITEM      -3
	#define NGUI_ITEM_INVALID_POSITION -4
	#define NGUI_ITEM_INVALID_CANT     -5
	#define NGUI_EMPTY_RECURSO         -6
	#define NGUI_NO_INIT               -7
	#define NGUI_ALREADY_INIT          -8
	#define NGUI_WINDOW_SIZE_ERR       -9

	#include <commons/collections/list.h>

	typedef struct nivel {
		char* nombre;
		t_list* items;
	} NIVEL;

	typedef struct item {
		char id;
		int posx;
		int posy;
		char item_type; // PERSONAJE, ENEMIGO o CAJA
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
	int nivel_gui_dibujar(NIVEL* nivel);

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

	/*
	* @NAME: nivel_gui_string_error
	* @DESC: Devuelve un string según el código de error recibido
	* @PARAMS:
	*     errnum - código de error
	*/
	char* nivel_gui_string_error(int errnum);

#endif 
