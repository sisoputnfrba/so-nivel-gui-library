#include "nivel.h"
#include "tad_items.h"
#include "stdlib.h"

void CrearItem(Items** ListaItems, char id, int x , int y, char tipo, int cant_rec) {
        Items * temp;
        temp = malloc(sizeof(Items));

        temp->id = id;
        temp->posx=x;
        temp->posy=y;
        temp->is_rec = tipo;
        temp->cant_rec = cant_rec;
        temp->next = *ListaItems;
        *ListaItems = temp;
}



void CrearPersonaje(Items** ListaItems, char id, int x , int y) {
        CrearItem(ListaItems, id, x, y, PERSONAJE, 0);
}

void CrearCaja(Items** ListaItems, char id, int x , int y, int cant) {
        CrearItem(ListaItems, id, x, y, CAJA_DE_RECURSOS, cant);
}

void BorrarItem(Items** ListaItems, char id) {
        Items * temp = *ListaItems;
        Items * oldtemp;

        if ((temp != NULL) && (temp->id == id)) {
                *ListaItems = (*ListaItems)->next;
		free(temp);
        } else {
                while((temp != NULL) && (temp->id != id)) {
                        oldtemp = temp;
                        temp = temp->next;
                }
                if ((temp != NULL) && (temp->id == id)) {
                        oldtemp->next = temp->next;
			free(temp);
                }
        }

}

void MoverPersonaje(Items* ListaItems, char id, int x, int y) {

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


void restarRecurso(Items* ListaItems, char id) {

        Items * temp;
        temp = ListaItems;

        while ((temp != NULL) && (temp->id != id)) {
                temp = temp->next;
        }
        if ((temp != NULL) && (temp->id == id)) {
                if ((temp->is_rec) && (temp->cant_rec > 0)) {
                        temp->cant_rec = temp->cant_rec--;
                }
        }

}

