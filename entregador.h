// Davy Andrade e Derek Gossani

typedef struct entregador Entregador;

Entregador* entregador_criar(char* nome, char* veiculo);
void entregador_liberar(Entregador* e);
char* entregador_getNome(Entregador* e);
void entregador_setDisponivel(Entregador* e, int disp);
int entregador_estaDisponivel(Entregador* e);
void entregador_contabilizarEntrega(Entregador* e);
int entregador_getEntregas(Entregador* e);
char* entregador_paraString(Entregador* e);