#include <stdio.h>
#include "../include/Pilha.h"

int main()
{
    Pilha p;
    inicializarPilha(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    exibirPilha(&p);

    int removido;
    if (desempilhar(&p, &removido))
    {
        printf("Removido: %d\n", removido);
    }

    exibirPilha(&p);

    return 0;
}
