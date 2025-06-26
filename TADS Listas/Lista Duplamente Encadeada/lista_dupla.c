// ---------------------------
// LISTA DUPLAMENTE ENCADEADA
// ---------------------------
#include "lista_dupla.h"

struct no_duplo
{
    int valor;
    NoDuplo *ant, *prox;
};

struct lista_dupla
{
    NoDuplo *inicio;
};

ListaDupla *ld_cria()
{
    ListaDupla *l = malloc(sizeof(ListaDupla));
    l->inicio = NULL;
    return l;
}

void ld_insere_inicio(ListaDupla *l, int valor)
{
    NoDuplo *novo = malloc(sizeof(NoDuplo));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = l->inicio;
    if (l->inicio != NULL)
        l->inicio->ant = novo;
    l->inicio = novo;
}

void ld_insere_fim(ListaDupla *l, int valor)
{
    NoDuplo *novo = malloc(sizeof(NoDuplo));
    novo->valor = valor;
    novo->prox = NULL;
    if (l->inicio == NULL)
    {
        novo->ant = NULL;
        l->inicio = novo;
    }
    else
    {
        NoDuplo *aux = l->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
    }
}

void ld_remove(ListaDupla *l, int valor)
{
    NoDuplo *aux = l->inicio;
    while (aux != NULL && aux->valor != valor)
        aux = aux->prox;
    if (aux != NULL)
    {
        if (aux->ant != NULL)
            aux->ant->prox = aux->prox;
        else
            l->inicio = aux->prox;
        if (aux->prox != NULL)
            aux->prox->ant = aux->ant;
        free(aux);
    }
}

void ld_imprime(ListaDupla *l)
{
    NoDuplo *aux = l->inicio;
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void ld_imprime_reverso(ListaDupla *l)
{
    NoDuplo *aux = l->inicio;
    if (aux == NULL)
        return;
    while (aux->prox != NULL)
        aux = aux->prox;
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->ant;
    }
    printf("\n");
}

void ld_libera(ListaDupla *l)
{
    NoDuplo *aux = l->inicio;
    while (aux != NULL)
    {
        NoDuplo *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(l);
}
