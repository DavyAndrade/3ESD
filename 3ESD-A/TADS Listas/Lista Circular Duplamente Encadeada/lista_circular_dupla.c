// --------------------------------------------
// LISTA CIRCULAR DUPLAMENTE ENCADEADA
// --------------------------------------------
#include "lista_circular_dupla.h"

struct no_cduplo
{
    int valor;
    NoCDuplo *ant, *prox;
};

struct lista_circular_dupla
{
    NoCDuplo *inicio;
};

ListaCircularDupla *lcd_cria()
{
    ListaCircularDupla *l = malloc(sizeof(ListaCircularDupla));
    l->inicio = NULL;
    return l;
}

void lcd_insere(ListaCircularDupla *l, int valor)
{
    NoCDuplo *novo = malloc(sizeof(NoCDuplo));
    novo->valor = valor;
    if (l->inicio == NULL)
    {
        novo->prox = novo->ant = novo;
        l->inicio = novo;
    }
    else
    {
        NoCDuplo *fim = l->inicio->ant;
        novo->prox = l->inicio;
        novo->ant = fim;
        fim->prox = novo;
        l->inicio->ant = novo;
    }
}

void lcd_remove(ListaCircularDupla *l, int valor)
{
    if (l->inicio == NULL)
        return;
    NoCDuplo *aux = l->inicio;
    do
    {
        if (aux->valor == valor)
        {
            if (aux->prox == aux)
            {
                l->inicio = NULL;
            }
            else
            {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                if (aux == l->inicio)
                    l->inicio = aux->prox;
            }
            free(aux);
            return;
        }
        aux = aux->prox;
    } while (aux != l->inicio);
}

void lcd_imprime(ListaCircularDupla *l)
{
    if (l->inicio == NULL)
        return;
    NoCDuplo *aux = l->inicio;
    do
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    } while (aux != l->inicio);
    printf("\n");
}

void lcd_imprime_reverso(ListaCircularDupla *l)
{
    if (l->inicio == NULL)
        return;
    NoCDuplo *aux = l->inicio->ant;
    do
    {
        printf("%d ", aux->valor);
        aux = aux->ant;
    } while (aux != l->inicio->ant);
    printf("\n");
}

void lcd_libera(ListaCircularDupla *l)
{
    if (l->inicio == NULL)
    {
        free(l);
        return;
    }
    NoCDuplo *aux = l->inicio->prox;
    while (aux != l->inicio)
    {
        NoCDuplo *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(l->inicio);
    free(l);
}
