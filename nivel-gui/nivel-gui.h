#ifndef __NIVEL_H__
#define __NIVEL_H__

	#define PERSONAJE_ITEM_TYPE 2
	#define CAJA_ITEM_TYPE      3
	#define ENEMIGO_ITEM_TYPE   4

	#include <commons/collections/list.h>
	#include <commons/string.h>

	typedef struct nivel {
		char* nombre;
		t_list* items;
	} NIVEL;

	typedef struct item {
		char id;
		int posx;
		int posy;
		int item_type; // PERSONAJE, ENEMIGO o CAJA
		int quantity;
	} ITEM_NIVEL;

	/*
	* @NAME: nivel_gui_inicializar
	* @DESC: Inicializa el espacio de dibujo
	* @ERRORS:
	*     NGUI_ALREADY_INIT
	*/
	int nivel_gui_inicializar(void);

	/*
	* @NAME: nivel_gui_dibujar
	* @DESC: Dibuja cada entidad en la lista de items
	* @PARAMS:
	*       nivel - nivel a dibujar
	* @ERRORS:
	*     NGUI_NO_INIT
	*/
	int nivel_gui_dibujar(NIVEL* nivel);

	/*
	* @NAME: nivel_gui_terminar
	* @DESC: Termina el nivel de forma prolija
	* @ERRORS:
	*     NGUI_NO_INIT
	*/
	int nivel_gui_terminar(void);

	/*
	* @NAME: nivel_gui_get_area_nivel
	* @DESC: Devuelve el tamanio usable de la pantalla 
	* @PARAMS:
	*       columnas - valor de retorno de columnas
	*       filas    - valor de retorno de filas
	* @ERRORS:
	*     NGUI_NO_INIT
	*     NGUI_TERM_SIZE_FAIL
	*/
	int nivel_gui_get_area_nivel(int * columnas, int * filas);

	/*
	* @NAME: nivel_gui_string_error
	* @DESC: Devuelve un string según el código de error recibido
	* @PARAMS:
	*     errnum - código de error
	*/
	char* nivel_gui_string_error(int errnum);

	/*
	* @NAME: NGUI_SUCCESS
	* @DESC: Operacion exitosa.
	*/
	#define NGUI_SUCCESS                0
	/*
	* @NAME: NGUI_ITEM_NOT_FOUND
	* @DESC: No se encontro el item.
	*/
	#define NGUI_ITEM_NOT_FOUND        -1
	/*
	* @NAME: NGUI_ITEM_ALREADY_EXISTS
	* @DESC: El item ya existe.
	*/
	#define NGUI_ITEM_ALREADY_EXISTS   -2
	/*
	* @NAME: NGUI_ITEM_NOT_A_BOX
	* @DESC: El item no es una caja de recursos.
	*/
	#define NGUI_ITEM_NOT_A_BOX        -3
	/*
	* @NAME: NGUI_ITEM_INVALID_POSITION
	* @DESC: La posicion se encuentra fuera del tablero.
	*/
	#define NGUI_ITEM_INVALID_POSITION -4
	/*
	* @NAME: NGUI_ITEM_INVALID_SRCS
	* @DESC: La cantidad de recursos recibida no es valida.
	*/
	#define NGUI_ITEM_INVALID_SRCS     -5
	/*
	* @NAME: NGUI_ITEM_EMPTY_BOX
	* @DESC: "La caja de recursos se encuentra vacia."
	*/
	#define NGUI_ITEM_EMPTY_BOX        -6
	/*
	* @NAME: NGUI_NO_INIT
	* @DESC: Library no inicializada.
	*/
	#define NGUI_NO_INIT               -7
	/*
	* @NAME: NGUI_ALREADY_INIT
	* @DESC: Library ya inicializada.
	*/
	#define NGUI_ALREADY_INIT          -8
	/*
	* @NAME: NGUI_TERM_SIZE_FAIL
	* @DESC: Error al obtener el tamaño de la terminal.
	*/
	#define NGUI_TERM_SIZE_FAIL        -9

#endif 
