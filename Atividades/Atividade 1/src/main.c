/*

Davy Andrade Moura

*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/Conjunto.h"

void popularConjunto(Conjunto *c, int inicio, int fim)
{
    for (int i = inicio; i <= fim; i++)
    {
        conj_insere(c, i);
    }
}

int main()
{
    Conjunto *jc = conj_cria();
    Conjunto *marlene = conj_cria();
    Conjunto *valeria = conj_cria();

    popularConjunto(jc, 2, 28);
    popularConjunto(marlene, 5, 30);
    popularConjunto(valeria, 1, 25);

    Conjunto *intersecao1 = conj_intersecao(jc, marlene);
    Conjunto *diasViagem = conj_intersecao(intersecao1, valeria);

    printf("A família pode viajar nos seguintes dias: ");
    conj_exibe(diasViagem);

    free(jc);
    free(marlene);
    free(valeria);
    free(intersecao1);
    free(diasViagem);

    return 0;
}
