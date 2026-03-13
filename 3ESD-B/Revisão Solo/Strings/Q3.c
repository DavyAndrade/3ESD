/*
Contagem de Comprimento: Implemente sua própria versão da função strlen. A função deve receber um ponteiro para a string e retornar o número de caracteres presentes antes do \0
*/

#include <stdio.h>

int strLen(char *str);

int main() {
    char word[] = "";

    int qtdChar = strLen(word);

    printf("A palavra possui %d caracteres!\n", qtdChar);

    return 0;
}

int strLen(char *str) {
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        n++;
    }

    return n;
}