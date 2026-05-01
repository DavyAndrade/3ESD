// Davy Andrade Moura

#include "pilha_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

void pilha_cria(TPilha *p) {
    if (p == NULL) {
        return;
    }

    p->topo = NULL;
}

int pilha_vazia(const TPilha *p) {
    if (p == NULL) {
        return 1;
    }

    return p->topo == NULL;
}

int pilha_push(TPilha *p, int valor) {
    TNo *novo;

    if (p == NULL) {
        return 0;
    }

    novo = (TNo *)malloc(sizeof(TNo));
    if (novo == NULL) {
        return 0;
    }

    novo->info = valor;
    novo->prox = p->topo;
    p->topo = novo;

    return 1;
}

int pilha_pop(TPilha *p, int *valor) {
    TNo *removido;

    if (p == NULL || valor == NULL || pilha_vazia(p)) {
        return 0;
    }

    removido = p->topo;
    *valor = removido->info;
    p->topo = removido->prox;
    free(removido);

    return 1;
}

int pilha_consultaTopo(const TPilha *p, int *valor) {
    if (p == NULL || valor == NULL || pilha_vazia(p)) {
        return 0;
    }

    *valor = p->topo->info;
    return 1;
}

void pilha_exibe(const TPilha *p) {
    TNo *atual;

    if (p == NULL || pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Topo -> ");
    atual = p->topo;
    while (atual != NULL) {
        printf("[%d]", atual->info);
        if (atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }
    printf("\n");
}

void pilha_destroi(TPilha *p) {
    int lixo;

    if (p == NULL) {
        return;
    }

    while (pilha_pop(p, &lixo)) {
    }
}
