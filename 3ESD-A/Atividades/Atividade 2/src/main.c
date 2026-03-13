/*
Davy Andrade Moura

Este main manipula com o TAD de unidadeTempo. O TAD PONTO fora alterado conforme o dever solicitado
e também se encontra presente nesta atividade.
*/

#include <stdio.h>
#include "../include/unidadeTempo.h"

#define MAX_ATLETAS 10

void atletas(int tempos[], int qtd)
{
    int i, contAtletas = 0;
    UnidadeTempo *tempoAtual, *maiorTempo;

    /* Inicializa o maior tempo com o primeiro atleta */
    maiorTempo = ut_fromSegundos(tempos[0] * 60);

    /* Exibe os tempos dos atletas e atualiza o maior tempo */
    for (i = 0; i < qtd; i++)
    {
        tempoAtual = ut_fromSegundos(tempos[i] * 60);
        printf("Atleta %d: ", i + 1);
        ut_exibe(tempoAtual);
        printf("\n");

        if (ut_compara(tempoAtual, maiorTempo) > 0)
        {
            ut_libera(maiorTempo);
            maiorTempo = ut_fromSegundos(tempos[i] * 60);
        }
        ut_libera(tempoAtual);
    }

    /* Conta quantos atletas possuem o maior tempo */
    for (i = 0; i < qtd; i++)
    {
        if (tempos[i] * 60 == ut_toSegundos(maiorTempo))
            contAtletas++;
    }

    printf("\nMaior tempo: ");
    ut_exibe(maiorTempo);
    printf("\nAtletas com maior tempo: %d\n", contAtletas);

    ut_libera(maiorTempo);
}

int main()
{
    int tempoAtletas[MAX_ATLETAS] = {15, 15, 30, 30, 45, 45, 60, 60, 75, 75};
    atletas(tempoAtletas, MAX_ATLETAS);
    return 0;
}
