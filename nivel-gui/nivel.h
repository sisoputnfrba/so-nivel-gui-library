#define PERSONAJE 0
#define CAJA_DE_RECURSOS 1

struct s_items {
	char id;
	int posx;
	int posy;
	char is_rec; // PERSONAJE o CAJA_DE_RECURSOS
	int cant_rec;
	struct s_items *next;
};

typedef struct s_items Items;

void Dibujar(Items* items);
void Terminar(void);
void Inicializar(void);

void GetTermSize(int * rows, int * cols) ;
