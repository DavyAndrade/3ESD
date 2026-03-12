#include <stdio.h>
#include "../include/ContaBancaria.h"

int main()
{

    char nome[100] = "Davy";
    double saldo = 1000;
    int idade = 20;

    ContaBancaria *cb = criarConta(nome, idade, saldo);

    exibirSaldo(cb);
    depositar(cb, 500);
    exibirSaldo(cb);
    sacar(cb, 200);
    exibirSaldo(cb);
    excluirConta(cb);
}
