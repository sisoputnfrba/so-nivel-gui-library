#define PERSONAJE_ITEM_TYPE 0
#define RECURSO_ITEM_TYPE 1
#define ENEMIGO_ITEM_TYPE 2

struct item {
	char id;
	int posx;
	int posy;
	char item_type; // PERSONAJE o CAJA_DE_RECURSOS
	int quantity;
	struct item *next;
};

typedef struct item ITEM_NIVEL;

void rnd(int *x, int max);
int nivel_gui_dibujar(ITEM_NIVEL* items, char* nom_nivel);
int nivel_gui_terminar(void);
int nivel_gui_inicializar(void);
int nivel_gui_get_area_nivel(int * rows, int * cols);
