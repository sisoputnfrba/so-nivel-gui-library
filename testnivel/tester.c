#include "nivel.h"
#include "tad_items.h"

#include <stdlib.h>
#include <curses.h>


int main(void) {

	Items* ListaItems = NULL;

	int rows, cols;
	int q, p;

	int x = 1;
	int y = 1;


        getAreaNivel(&rows, &cols);

	q = rows;
	p = cols;

	CrearPersonaje(&ListaItems, '@', q, p);
	CrearPersonaje(&ListaItems, '#', x, y);

	CrearCaja(&ListaItems, 'H', 20, 40, 5); 
	CrearCaja(&ListaItems, 'M', 15, 8, 3);
	CrearCaja(&ListaItems, 'F', 9, 19, 2);

	imprimir (ListaItems);

	MoverPersonaje(ListaItems, '@', 4, 4);
	MoverPersonaje(ListaItems, '#', 5, 5);


	restarRecurso(ListaItems, 'H');
	restarRecurso(ListaItems, 'F');

	imprimir (ListaItems);

	CrearCaja(&ListaItems, 'K', 25, 8, 3);
	CrearCaja(&ListaItems, 'J', 8, 19, 2);

	BorrarItem(&ListaItems, '#');
	BorrarItem(&ListaItems, 'F');
	BorrarItem(&ListaItems, 'H');
	BorrarItem(&ListaItems, 'M');
	BorrarItem(&ListaItems, '@');
	CrearPersonaje(&ListaItems, '@', q, p);
	BorrarItem(&ListaItems, 'K');
	MoverPersonaje(ListaItems, 'K', p++, q++);
	MoverPersonaje(ListaItems, 'J', 5, 5);

	imprimir (ListaItems);

	BorrarItem(&ListaItems, 'J');
	BorrarItem(&ListaItems, '@');

	imprimir (ListaItems);


}

void imprimir(Items* test) {
	printf("---INIT-----\n");

        while (test != NULL) {
                printf("%c: %d %d\n", test->id, test->posx, test->posy);
                test = test->next;
        }
	printf("---FIN-----\n");


}
