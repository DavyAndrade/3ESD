// Davy Andrade Moura

#include <stdio.h>
#include "pilha_encadeada.h"

int main(void) {
    TPilha pilha;
    int valor;

    pilha_cria(&pilha);

    pilha_push(&pilha, 10);
    pilha_push(&pilha, 20);
    pilha_push(&pilha, 30);
    pilha_push(&pilha, 40);
    pilha_push(&pilha, 50);
    pilha_push(&pilha, 60);

    printf("Pilha apos varios pushes:\n");
    pilha_exibe(&pilha);

    if (pilha_consultaTopo(&pilha, &valor)) {
        printf("Topo atual: %d\n", valor);
    }

    printf("\nRealizando 3 pops:\n");
    if (pilha_pop(&pilha, &valor)) {
        printf("Saiu no pop: %d\n", valor);
    }
    if (pilha_pop(&pilha, &valor)) {
        printf("Saiu no pop: %d\n", valor);
    }
    if (pilha_pop(&pilha, &valor)) {
        printf("Saiu no pop: %d\n", valor);
    }

    printf("\nPilha depois dos pops:\n");
    pilha_exibe(&pilha);

    pilha_destroi(&pilha);
    return 0;
}
