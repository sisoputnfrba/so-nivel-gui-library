#define PERSONAJE 0
#define CAJA_DE_RECURSOS 1

struct item {
	char id;
	int posx;
	int posy;
	char is_rec; // PERSONAJE o CAJA_DE_RECURSOS
	int cant_rec;
	struct item *next;
};

typedef struct item Items;

void nivel_gui_dibujar(Items* items);
void nivel_gui_terminar(void);
void nivel_gui_inicializar(void);

void nivel_gui_get_term_size(int * rows, int * cols) ;
void nivel_gui_get_area_nivel(int * rows, int * cols);
