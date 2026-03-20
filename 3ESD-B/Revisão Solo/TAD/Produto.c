#include "Produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
    char* identificacao;
    char* codigoBarras;
    float preco;
    int qtd;
    Unidade** unidades;
};

int prod_isInvalido(Produto* p) {
    return (p == NULL);
}

Produto* prod_cria(const char* id, const char* cb, float preco, int qtd) {
    Produto* p = (Produto*)malloc(sizeof(Produto));
    if (p == NULL) return NULL;

    p->identificacao = (char*)malloc(strlen(id ? id : "Produto") + 1);
    strcpy(p->identificacao, id ? id : "Produto");

    p->codigoBarras = (char*)malloc(strlen(cb ? cb : "") + 1);
    strcpy(p->codigoBarras, cb ? cb : "");

    p->preco = (preco > 0) ? preco : 0;
    p->qtd = qtd;

    p->unidades = (Unidade**)malloc(qtd * sizeof(Unidade*));
    for(int i = 0; i < qtd; i++) p->unidades[i] = NULL;

    return p;
}

void prod_libera(Produto** p) {
    if (p == NULL || prod_isInvalido(*p)) return;
    
    int i;
    for(i = 0; i < (*p)->qtd; i++) {
        if ((*p)->unidades[i] != NULL)
            uni_libera(&((*p)->unidades[i]));
    }
    free((*p)->unidades);
    free((*p)->identificacao);
    free((*p)->codigoBarras);
    free(*p);
    *p = NULL;
}

void prod_adicionarUnidade(Produto* p, int indice, Unidade* u) {
    if (!prod_isInvalido(p) && indice >= 0 && indice < p->qtd) {
        p->unidades[indice] = u;
    }
}

Unidade* prod_get_unidade(Produto* p, int indice) {
    if (prod_isInvalido(p) || indice < 0 || indice >= p->qtd) return NULL;
    return p->unidades[indice];
}

void prod_reajuste(Produto* p, float perc) {
    if (!prod_isInvalido(p)) {
        p->preco += p->preco * (perc / 100.0);
    }
}

int prod_ehSemelhante(Produto* p1, Produto* p2) {
    if (prod_isInvalido(p1) || prod_isInvalido(p2)) return FALSE;
    return (strcmp(p1->identificacao, p2->identificacao) == 0) ? TRUE : FALSE;
}

int prod_ehIgual(Produto* p1, Produto* p2) {
    if (!prod_ehSemelhante(p1, p2)) return FALSE;
    if (strcmp(p1->codigoBarras, p2->codigoBarras) != 0) return FALSE;
    if (p1->preco != p2->preco) return FALSE;
    return TRUE;
}

char* prod_getProduto(Produto* p) {
    if (prod_isInvalido(p)) return NULL;
    char* str = (char*)malloc(250 * sizeof(char));
    if (str) {
        sprintf(str, "ID: %s | CB: %s | Preco: %.2f | Estoque: %d", 
                p->identificacao, p->codigoBarras, p->preco, p->qtd);
    }
    return str;
}

float prod_get_preco(Produto* p) { return p->preco; }
int prod_get_qtd(Produto* p) { return p->qtd; }