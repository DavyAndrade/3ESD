#include <stdio.h>
#include "../include/Pilha.h"

typedef struct
{
    int topo;
    int elementos[TAM_MAX];
} Pilha;

// Inicializa a pilha
void inicializarPilha(Pilha *p)
{
    p->topo = -1;
}

// Verifica se a pilha está vazia
int estaVazia(Pilha *p)
{
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int estaCheia(Pilha *p)
{
    return p->topo == TAM_MAX - 1;
}

// Empilha um elemento
int empilhar(Pilha *p, int valor)
{
    if (estaCheia(p))
        return 0; // Falha: Pilha cheia
    p->elementos[++p->topo] = valor;
    return 1; // Sucesso
}

// Desempilha um elemento
int desempilhar(Pilha *p, int *valor)
{
    if (estaVazia(p))
        return 0; // Falha: Pilha vazia
    *valor = p->elementos[p->topo--];
    return 1; // Sucesso
}

// Exibe a pilha
void exibirPilha(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++)
    {
        printf("%d ", p->elementos[i]);
    }
    printf("\n");
}
