#include "../include/Conjunto.h"
#include <stdio.h>
#include <stdlib.h>

// Struct
struct conj
{
    int vet[80];
    int qtElem;
};

// Funções Auxiliares
int buscaElemento(Conjunto *A, int x)
{
    int i;

    for (i = 0; i < A->qtElem; i++)
    {
        if (A->vet[i] == x)
        {
            return 1;
        }
    }

    return 0;
}

// Funções TAD
Conjunto *conj_cria()
{
    Conjunto *p = (Conjunto *)malloc(sizeof(Conjunto));
    p->qtElem = 0;
    return p;
}

void conj_exibe(Conjunto *lst)
{
    int i;

    for (i = 0; i < lst->qtElem; i++)
    {
        printf("%d ", lst->vet[i]);
    }
    printf("\n");
}

Conjunto *conj_remove(Conjunto *lst, int num)
{
    int i, j;

    for (i = 0; i < lst->qtElem; i++)
    {
        if (buscaElemento(lst, num))
        {
            for (j = i; j < lst->qtElem - 1; j++)
            {
                lst->vet[j] = lst->vet[j + 1];
            }
            lst->qtElem--;
        }
    }
    return lst;
}

Conjunto *conj_uniao(Conjunto *lst, Conjunto *p)
{
    int i;
    Conjunto *novoConjunto = conj_cria();

    for (i = 0; i < lst->qtElem; i++)
    {
        novoConjunto->vet[novoConjunto->qtElem] = lst->vet[i];
        novoConjunto->qtElem++;
    }

    for (i = 0; i < p->qtElem; i++)
    {
        if (!buscaElemento(novoConjunto, p->vet[i]))
        {
            novoConjunto->vet[novoConjunto->qtElem] = p->vet[i];
            novoConjunto->qtElem++;
        }
    }

    return novoConjunto;
}

Conjunto *conj_intersecao(Conjunto *lst, Conjunto *p)
{
    int i;
    Conjunto *novoConjunto = conj_cria();

    for (i = 0; i < lst->qtElem; i++)
    {
        if (buscaElemento(p, lst->vet[i]))
        {
            novoConjunto->vet[novoConjunto->qtElem] = lst->vet[i];
            novoConjunto->qtElem++;
        }
    }
    return novoConjunto;
}

Conjunto *conj_insere(Conjunto *c, int num)
{
    if (c->qtElem < 80)
    {
        c->vet[c->qtElem] = num;
        c->qtElem++;
        return c;
    }
    else
    {
        printf("O Conjunto já possui 80 elementos.");
        return c;
    }
}