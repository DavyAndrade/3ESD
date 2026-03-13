#include "../include/unidadeTempo.h"
#include <stdlib.h>
#include <stdio.h>

/* Definição interna da estrutura */
struct unidadeTempo
{
    int horas;
    int minutos;
    int segundos;
};

/* Função auxiliar para normalizar os valores de tempo */
static void ut_normaliza(UnidadeTempo *ut)
{
    if (ut->segundos >= 60)
    {
        ut->minutos += ut->segundos / 60;
        ut->segundos = ut->segundos % 60;
    }
    if (ut->minutos >= 60)
    {
        ut->horas += ut->minutos / 60;
        ut->minutos = ut->minutos % 60;
    }
}

/* Cria e retorna uma Unidade de Tempo, normalizando os valores */
UnidadeTempo *ut_cria(int horas, int minutos, int segundos)
{
    UnidadeTempo *ut = (UnidadeTempo *)malloc(sizeof(UnidadeTempo));
    if (ut == NULL)
    {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    ut->horas = horas;
    ut->minutos = minutos;
    ut->segundos = segundos;
    ut_normaliza(ut);
    return ut;
}

/* Cria uma Unidade de Tempo a partir do total de segundos */
UnidadeTempo *ut_fromSegundos(int totalSegundos)
{
    int horas = totalSegundos / 3600;
    int resto = totalSegundos % 3600;
    int minutos = resto / 60;
    int segundos = resto % 60;
    return ut_cria(horas, minutos, segundos);
}

/* Libera a memória da Unidade de Tempo */
void ut_libera(UnidadeTempo *ut)
{
    free(ut);
}

/* Exibe a Unidade de Tempo no formato HH:MM:SS */
void ut_exibe(UnidadeTempo *ut)
{
    printf("%02d:%02d:%02d", ut->horas, ut->minutos, ut->segundos);
}

/* Converte a Unidade de Tempo para segundos */
int ut_toSegundos(UnidadeTempo *ut)
{
    return ut->horas * 3600 + ut->minutos * 60 + ut->segundos;
}

/* Soma duas Unidades de Tempo e retorna uma nova Unidade de Tempo */
UnidadeTempo *ut_soma(UnidadeTempo *ut1, UnidadeTempo *ut2)
{
    int totalSegundos = ut_toSegundos(ut1) + ut_toSegundos(ut2);
    return ut_fromSegundos(totalSegundos);
}

/* Subtrai duas Unidades de Tempo e retorna a diferença absoluta */
UnidadeTempo *ut_subtrai(UnidadeTempo *ut1, UnidadeTempo *ut2)
{
    int s1 = ut_toSegundos(ut1);
    int s2 = ut_toSegundos(ut2);
    int diff = s1 - s2;
    if (diff < 0)
        diff = -diff;
    return ut_fromSegundos(diff);
}

/* Compara duas Unidades de Tempo */
int ut_compara(UnidadeTempo *ut1, UnidadeTempo *ut2)
{
    int s1 = ut_toSegundos(ut1);
    int s2 = ut_toSegundos(ut2);
    if (s1 < s2)
        return -1;
    else if (s1 == s2)
        return 0;
    else
        return 1;
}
