#include "Unidade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct unidade {
    tData* fabricacao;
    int lote;
};

int uni_isInvalido(Unidade* u) {
    return (u == NULL);
}

Unidade* uni_cria(int dia, int mes, int ano, int lote) {
    Unidade* u = (Unidade*)malloc(sizeof(Unidade));
    if (u == NULL) return NULL;
    
    u->fabricacao = dta_cria(dia, mes, ano);
    u->lote = lote;
    return u;
}

void uni_libera(Unidade** u) {
    if (u == NULL || uni_isInvalido(*u)) return;
    dta_libera((*u)->fabricacao);
    free(*u);
    *u = NULL;
}

int uni_idade(Unidade* u, tData* dataAlvo) {
    if (uni_isInvalido(u)) return -1;
    return dta_diferenca(u->fabricacao, dataAlvo);
}

int uni_ehMenor(Unidade* u1, Unidade* u2, tData* dataReferencia) {
    int idade1 = uni_idade(u1, dataReferencia);
    int idade2 = uni_idade(u2, dataReferencia);

    if (idade1 < idade2) return TRUE;
    if (idade1 == idade2) return (u1->lote < u2->lote) ? TRUE : FALSE;
    return FALSE;
}

int uni_get_lote(Unidade* u) {
    return (uni_isInvalido(u)) ? -1 : u->lote;
}

char* uni_getUnidade(Unidade* u) {
    if (uni_isInvalido(u)) return NULL;
    char* sData = dta_getData(u->fabricacao);
    char* str = (char*)malloc(60 * sizeof(char));
    if (str) {
        sprintf(str, "[Fab: %s | Lote: %d]", sData, u->lote);
    }
    free(sData);
    return str;
}