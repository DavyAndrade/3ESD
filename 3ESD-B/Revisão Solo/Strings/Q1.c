// Verificação de Caracteres: Escreva uma função para determinar se um caractere recebido é uma letra.

#include <stdio.h>

int isLetra(char c);

int main() {
    char letra;

    printf("Entre com um caractere: ");
    scanf(" %c", &letra);

    if (isLetra(letra)) {
        printf("%c eh uma letra!\n", letra);
    } else {
        printf("%c NAO eh uma letra!\n", letra);
    }

    return 0;
}

int isLetra(char c) {
    if ((c >= 'A' && c <= 'Z') || c >= 'a' && c <= 'z') {
        return 1;
    } else {
        return 0;
    }
}