/*
Conversão para Maiúscula: Crie uma função que converta um caractere para maiúscula. Se ele já for maiúsculo ou não for uma letra, deve retornar o caractere original sem alteração.
*/

#include <stdio.h>
#include <ctype.h>

char uppercaseChar(char c);

int main() {
    char caractere;

    printf("Entre com um caractere: ");
    scanf(" %c", &caractere);

    char uppercaseMsg = uppercaseChar(caractere);

    printf("%c\n", uppercaseMsg);

    return 0;
}

char uppercaseChar(char c) {
    if (c >= 'a' && c <= 'z') {
        return toupper(c);
    } else {
        return c;
    }
}