// --------------------------------------------
// LISTA CIRCULAR SIMPLESMENTE ENCADEADA
// --------------------------------------------
#include "lista_circular_simples.h"

struct no_csimples
{
    int valor;
    NoCSimples *prox;
};

struct lista_circular_simples
{
    NoCSimples *fim;
};

ListaCircularSimples *lcs_cria()
{
    ListaCircularSimples *l = malloc(sizeof(ListaCircularSimples));
    l->fim = NULL;
    return l;
}

void lcs_insere(ListaCircularSimples *l, int valor)
{
    NoCSimples *novo = malloc(sizeof(NoCSimples));
    novo->valor = valor;
    if (l->fim == NULL)
    {
        novo->prox = novo;
    }
    else
    {
        novo->prox = l->fim->prox;
        l->fim->prox = novo;
    }
    l->fim = novo;
}

void lcs_remove(ListaCircularSimples *l, int valor)
{
    if (l->fim == NULL)
        return;
    NoCSimples *ant = l->fim, *atual = l->fim->prox;
    do
    {
        if (atual->valor == valor)
        {
            if (atual == ant)
            {
                l->fim = NULL;
            }
            else
            {
                ant->prox = atual->prox;
                if (atual == l->fim)
                    l->fim = ant;
            }
            free(atual);
            return;
        }
        ant = atual;
        atual = atual->prox;
    } while (atual != l->fim->prox);
}

void lcs_imprime(ListaCircularSimples *l)
{
    if (l->fim == NULL)
        return;
    NoCSimples *aux = l->fim->prox;
    do
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    } while (aux != l->fim->prox);
    printf("\n");
}

void lcs_libera(ListaCircularSimples *l)
{
    if (l->fim == NULL)
    {
        free(l);
        return;
    }
    NoCSimples *inicio = l->fim->prox;
    NoCSimples *atual = inicio;
    do
    {
        NoCSimples *temp = atual;
        atual = atual->prox;
        free(temp);
    } while (atual != inicio);
    free(l);
}