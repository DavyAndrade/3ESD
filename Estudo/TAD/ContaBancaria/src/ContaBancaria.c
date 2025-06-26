#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ContaBancaria.h"

struct contaBancaria
{
    char nome[100];
    int idade;
    float saldo;
};

ContaBancaria *criarConta(char nome[100], int idade, float saldo)
{
    ContaBancaria *cb = (ContaBancaria *)malloc(sizeof(ContaBancaria));

    if (cb == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    if (idade < 18)
    {
        printf("Conta criada com sucesso, mas a idade é insuficiente.\n");
        free(cb);
        return NULL;
    }
    else
    {
        strcpy(cb->nome, nome);
        cb->idade = idade;
        cb->saldo = saldo;
        return cb;
    }
}

ContaBancaria *depositar(ContaBancaria *cb, float valor)
{
    cb->saldo += valor;
    return cb;
}

ContaBancaria *sacar(ContaBancaria *cb, float valor)
{
    if (cb->saldo >= valor)
    {
        cb->saldo -= valor;
        return cb;
    }
    else
    {
        printf("Saldo insuficiente.\n");
        return cb;
    }
}

void exibirSaldo(ContaBancaria *cb)
{
    printf("Saldo: %.2f\n", cb->saldo);
}

void excluirConta(ContaBancaria *cb) {
    free(cb);
    printf("Conta excluída com sucesso.\n");
}