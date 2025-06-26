#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/Lista.h"

typedef struct No
{
    int valor;
    struct No *proximo;
} TNo;

struct lista
{
    TNo *inicio;
};

Lista *inicializar_lista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

void inserirNaLista(Lista *lista, int valor) {
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        
    }
}