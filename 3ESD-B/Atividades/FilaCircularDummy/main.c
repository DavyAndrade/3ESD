#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    printf("--- Teste Fila Sequencial Circular com R apontando para Dummy ---\n");
    
    // Cria fila com capacidade para 3 elementos (N = 4 internamente devido ao dummy)
    Fila* f = fila_criar(3);
    
    if (f == NULL) return 1;
    
    fila_imprimir(f); // Deve exibir vazio
    
    printf("\nInserindo 10, 20, 30...\n");
    fila_inserir(f, 10);
    fila_inserir(f, 20);
    fila_inserir(f, 30);
    fila_imprimir(f);
    
    if (fila_cheia(f)) {
        printf("Fila esta cheia!\n");
    }
    
    printf("\nTentando inserir 40...\n");
    if (!fila_inserir(f, 40)) {
        printf("Falha ao inserir 40: fila cheia.\n");
    }
    
    int valor;
    printf("\nRemovendo 2 elementos...\n");
    if (fila_remover(f, &valor)) printf("Removido: %d\n", valor);
    if (fila_remover(f, &valor)) printf("Removido: %d\n", valor);
    fila_imprimir(f);
    
    printf("\nInserindo 40, 50...\n");
    fila_inserir(f, 40);
    fila_inserir(f, 50);
    fila_imprimir(f);
    
    if (fila_cheia(f)) {
        printf("Fila esta cheia novamente!\n");
    }
    
    printf("\nEsvaziando a fila...\n");
    while (!fila_vazia(f)) {
        if (fila_remover(f, &valor)) printf("Removido: %d\n", valor);
    }
    fila_imprimir(f);
    
    fila_liberar(f);
    printf("\nFim do teste.\n");
    
    return 0;
}
