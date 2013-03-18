struct s_items {
	char id;
	int posx;
	int posy;
	struct s_items *next;
};

typedef struct s_items Items;

void Dibujar(Items* items);
void Terminar(void);
void Inicializar(void);

