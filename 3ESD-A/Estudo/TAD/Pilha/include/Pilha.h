#ifndef PILHA_H
#define PILHA_H

#define TAM_MAX 100 // Definição do tamanho máximo da pilha

typedef struct
{
    int topo;
    int elementos[TAM_MAX];
} Pilha;

// Funções do TAD
void inicializarPilha(Pilha *p);
int estaVazia(Pilha *p);
int estaCheia(Pilha *p);
int empilhar(Pilha *p, int valor);
int desempilhar(Pilha *p, int *valor);
void exibirPilha(Pilha *p);

#endif