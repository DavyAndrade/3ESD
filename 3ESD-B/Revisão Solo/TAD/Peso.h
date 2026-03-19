// Interface
typedef struct peso Peso;

// Criação
Peso* pes_cria(int kg, int g);

// Liberar memória
void pes_libera(Peso *p);

// Acesso aos atributos
void pes_acessa(Peso *p, int *kg, int *g);
void pes_acessaKg(Peso *p, int *kg);
void pes_acessaG(Peso *p, int *g);

// Atribuição aos atributos
void pes_atribui(Peso *p, int kg, int g);
void pes_atribuiKg(Peso *p, int kg);
void pes_atribuiG(Peso *p, int g);

// Auxiliares
int pes_compara(Peso *p1, Peso *p2);
Peso *pes_copia(Peso *p);

// exibição no formato (Kg: kg, G: g)
char* pes_getPeso(Peso *p);
void pes_exibePeso(Peso *p);