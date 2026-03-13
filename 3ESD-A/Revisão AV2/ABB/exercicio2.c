/*
Escreva uma função que conta o número de nós de uma árvore binária.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *esquerda;
    struct no *direita;
} NoArv;

NoArv *cria_no(int valor)
{
    NoArv *novo = (NoArv *)malloc(sizeof(NoArv));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória para o nó.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

NoArv *inserir(NoArv *raiz, int valor)
{
    if (raiz == NULL)
    {
        return cria_no(valor);
    }
    if (valor < raiz->valor)
    {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

int contarNos(NoArv *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int main()
{
    NoArv *raiz = NULL;

    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    int totalNos = contarNos(raiz);
    printf("Total de nos na arvore: %d\n", totalNos);

    free(raiz);
    return 0;
}