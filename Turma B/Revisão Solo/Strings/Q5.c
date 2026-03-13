/*
Cópia Manual: Escreva uma função void copia(char* dest, char* orig) que copie os elementos da string de origem para o destino, certificando-se de "fechar" a string destino com o caractere nulo ao final.
*/

#include <stdio.h>
#include <string.h>

void copia(char* dest, char* orig);

int main() {
    char msgOrigem[] = "Origem";
    char msgDestino[] = "Destino";

    printf("Destino: %s\n", msgDestino);
    printf("Origem: %s\n", msgOrigem);

    copia(msgDestino, msgOrigem);
    printf("================\n");

    printf("Destino: %s\n", msgDestino);
    printf("Origem: %s\n", msgOrigem);

    return 0;
}

void copia(char* dest, char* orig) {
    int i;

    for (i = 0; orig[i] != '\0'; i++) {
        dest[i] = orig[i];
    }

    dest[i] = '\0';
}