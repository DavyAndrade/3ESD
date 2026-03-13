typedef struct contaBancaria ContaBancaria;

ContaBancaria *criarConta(char nome[100], int idade, float saldo);
ContaBancaria *depositar(ContaBancaria *cb, float valor);
ContaBancaria *sacar(ContaBancaria *cb, float valor);
void exibirSaldo(ContaBancaria *cb);
void excluirConta(ContaBancaria *cb);