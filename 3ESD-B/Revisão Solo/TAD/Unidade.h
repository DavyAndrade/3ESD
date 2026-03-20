#include "Data.h"
#define TRUE 1
#define FALSE 0

typedef struct unidade Unidade;

Unidade* uni_cria(int dia, int mes, int ano, int lote);
void uni_libera(Unidade** u);
int uni_isInvalido(Unidade* u);

// Getters e Setters
tData* uni_get_data(Unidade* u);
int uni_get_lote(Unidade* u);

// Funcionalidades
int uni_idade(Unidade* u, tData* dataAlvo);
int uni_ehMenor(Unidade* u1, Unidade* u2, tData* dataReferencia);
char* uni_getUnidade(Unidade* u);
void uni_exibe(Unidade* u);