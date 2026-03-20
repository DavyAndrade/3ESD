#include "Unidade.h"

typedef struct produto Produto;

Produto* prod_cria(const char* id, const char* cb, float preco, int qtdUnidades);
void prod_libera(Produto** p);
int prod_isInvalido(Produto* p);

// Funcionalidades
int prod_ehSemelhante(Produto* p1, Produto* p2);
int prod_ehIgual(Produto* p1, Produto* p2);
void prod_reajuste(Produto* p, float percentual);
void prod_adicionarUnidade(Produto* p, int indice, Unidade* u);
Unidade* prod_get_unidade(Produto* p, int indice);

// Getters
float prod_get_preco(Produto* p);
int prod_get_qtd(Produto* p);
char* prod_getProduto(Produto* p);