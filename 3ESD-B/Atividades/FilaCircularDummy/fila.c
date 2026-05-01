#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct fila {
    int *dados;
    int F; // Frente: aponta para o primeiro elemento
    int R; // Ré: aponta para o DUMMY (próximo espaço vazio)
    int N; // Capacidade total do vetor (inclui o espaço do dummy)
};

Fila* fila_criar(int capacidade) {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    
    if (f == NULL) {
        printf("Memoria insuficiente!\n");
        return NULL;
    }
    
    // N é a capacidade solicitada + 1 espaço para o dummy
    f->N = capacidade + 1;
    f->dados = (int*) malloc(f->N * sizeof(int));
    
    if (f->dados == NULL) {
        printf("Memoria insuficiente!\n");
        free(f);
        return NULL;
    }
    
    f->F = 0;
    f->R = 0; // Inicialmente R aponta para 0 (que é o dummy)
    
    return f;
}

void fila_liberar(Fila* f) {
    if (f != NULL) {
        free(f->dados);
        free(f);
    }
}

int fila_vazia(Fila* f) {
    if (f == NULL) return 1;
    // Fila vazia quando Frente e Ré apontam para o mesmo índice
    return f->F == f->R;
}

int fila_cheia(Fila* f) {
    if (f == NULL) return 0;
    // Fila cheia quando o próximo índice após R for igual a F
    return ((f->R + 1) % f->N) == f->F;
}

int fila_inserir(Fila* f, int valor) {
    if (f == NULL || fila_cheia(f)) {
        return 0;
    }
    
    // R aponta para o dummy (espaço vazio), então inserimos em R
    f->dados[f->R] = valor;
    
    // R avança para o próximo espaço, que passará a ser o novo dummy
    f->R = (f->R + 1) % f->N;
    
    return 1;
}

int fila_remover(Fila* f, int* valor) {
    if (f == NULL || fila_vazia(f)) {
        return 0;
    }
    
    // F aponta para o primeiro elemento válido
    *valor = f->dados[f->F];
    
    // F avança para o próximo elemento
    f->F = (f->F + 1) % f->N;
    
    return 1;
}

void fila_imprimir(Fila* f) {
    if (f == NULL) return;
    
    printf("Fila: [ ");
    int i = f->F;
    while (i != f->R) {
        printf("%d ", f->dados[i]);
        i = (i + 1) % f->N;
    }
    printf("]\n");
}
