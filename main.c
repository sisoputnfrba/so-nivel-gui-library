#include "main.h"
#include "nivel.h"

#include <stdlib.h>
#include <curses.h>
#include <sys/ioctl.h>

Items* ListaItems = NULL;

int main(void) {

	int rows, cols;
	int q, p;

	int x = 1;
	int y = 1;

	Inicializar();

        GetTermSize(&rows, &cols);

	q = rows - 2;
	p = cols - 2;

	CrearItem('@', q, p);
	CrearItem('#', x, y);

	CrearItem('H', 20, 40);
	CrearItem('M', 15, 8);
	CrearItem('F', 9, 19);

	Dibujar(ListaItems);

	while ( 1 ) {
		int key = getch();

		switch( key ) {

			case KEY_UP:
				if (y > 1) {
					y--;
				}
			break;

			case KEY_DOWN:
				if (y < rows - 2) {
					y++;
				}
			break;

			case KEY_LEFT:
				if (x > 1) {
					x--;
				}
			break;
			case KEY_RIGHT:
				if (x < cols - 2) {
					x++;
				}
			break;
			case 'w':
			case 'W':
				if (q > 1) {
					q--;
				}
			break;

			case 's':
			case 'S':
				if (q < rows - 2) {
					q++;
				}
			break;

			case 'a':
			case 'A':
				if (p > 1) {
					p--;
				}
			break;
			case 'D':
			case 'd':
				if (p < cols -2) {
					p++;
				}
			break;
			case 'Q':
			case 'q':
				Terminar();
				exit(0);
			break;
		}

		MoverItem('@', q, p);
		MoverItem('#', y, x);

		if ((q == y) && (x == p)) {
			BorrarItem('#');
		}

		Dibujar(ListaItems);
	}

	Terminar();
}

void GetTermSize(int * rows, int * cols) {

    struct winsize ws;


    /*  Get terminal size  */

    if ( ioctl(0, TIOCGWINSZ, &ws) < 0 ) {
        perror("couldn't get window size");
    }


    /*  Update globals  */
    *rows = ws.ws_row;
    *cols = ws.ws_col;
}


void CrearItem(char id, int x , int y) {
        Items * temp;
        temp = malloc(sizeof(Items));

        temp->id = id;
        temp->posx=x;
        temp->posy=y;
        temp->next = ListaItems;
        ListaItems = temp;
}

void BorrarItem(char id) {
        Items * temp = ListaItems;
        Items * oldtemp;

        if ((temp != NULL) && (temp->id == id)) {
                ListaItems = ListaItems->next;
        } else {
                while((temp != NULL) && (temp->id != id)) {
                        oldtemp = temp;
                        temp = temp->next;
                }
                if ((temp != NULL) && (temp->id == id)) {
                        oldtemp->next = temp->next;
                }
        }

}

void MoverItem(char id, int x, int y) {

        Items * temp;
        temp = ListaItems;

        while ((temp != NULL) && (temp->id != id)) {
                temp = temp->next;
        }
        if ((temp != NULL) && (temp->id == id)) {
                temp->posx = x;
                temp->posy = y;
        }

}

