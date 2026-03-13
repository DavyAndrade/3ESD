/*
Impressão Inversa: Construa uma função para imprimir uma sequência de caracteres de trás para frente.
*/

#include <stdio.h>
#include <string.h>

void printReverso(char *str);

int main() {
    char msg[] = "mensagem";

    printReverso(msg);

    return 0;
}

void printReverso(char *str) {
    int strTam = strlen(str);

    for (int i = strTam; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");
}