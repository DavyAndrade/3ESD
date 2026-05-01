// Davy Andrade Moura

typedef struct no {
    int info;
    struct no *prox;
} TNo;

typedef struct {
    TNo *topo;
} TPilha;

void pilha_cria(TPilha *p);
int pilha_vazia(const TPilha *p);
int pilha_push(TPilha *p, int valor);
int pilha_pop(TPilha *p, int *valor);
int pilha_consultaTopo(const TPilha *p, int *valor);
void pilha_exibe(const TPilha *p);
void pilha_destroi(TPilha *p);
