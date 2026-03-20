#include <stdio.h>
#include <stdlib.h>
#include "PessoaIMC.h"
#include "Peso.h"
#include "Altura.h"

int main(void) {
    // 1. Criação da instância
    // Nome: Maria Souza, Peso: 65kg 500g, Altura: 1m 60cm
    printf("--- Teste de Criacao ---\n");
    PessoaIMC *pessoa = pimc_cria(65, 0, 1, 60, "Maria Souza");

    if (pessoa == NULL) {
        printf("Erro ao alocar PessoaIMC (Memoria insuficiente).\n");
        return 1;
    }

    // 2. Teste de Exibição Direta
    printf("Dados Iniciais:\n");
    pimc_exibePessoaIMC(pessoa);
    printf("\n");

    // 3. Teste da String Dinâmica (pimc_getPessoaIMC)
    // De acordo com as fontes, quando uma função do TAD aloca memória e a retorna,
    // o programa cliente (main) é responsável por dar free() [3].
    printf("\n--- Teste de Recuperacao de String ---\n");
    char *info = pimc_getPessoaIMC(pessoa);
    if (info != NULL) {
        printf("String recuperada: %s\n", info);
        free(info); // Liberação obrigatória para evitar vazamento de memória [4]
    }

    // 4. Teste de Modificações
    printf("\n--- Teste de Alteracao de Dados ---\n");
    printf("Aumentando o peso em 5200g (5.2kg) e a altura em 5cm...\n");
    pimc_alteraPeso(pessoa, 5200);   // Usa a lógica de soma do TAD Peso
    pimc_alteraAltura(pessoa, 5);    // Usa a lógica de soma do TAD Altura

    // 5. Exibição dos dados atualizados e Categoria
    printf("\nDados Atualizados:\n");
    pimc_exibePessoaIMC(pessoa);
    printf("\nIMC calculado: %.2f\n", pimc_calcularIMC(pessoa));
    printf("Categoria final: %s\n", pimc_categorizaIMC(pessoa));

    // 6. Liberação de Memória
    // A função pimc_libera deve garantir a limpeza de toda a hierarquia (nome, peso e altura) [5, 6]
    printf("\nLimpando memoria do Heap...\n");
    pimc_libera(pessoa);

    printf("Testes concluidos com sucesso.\n");
    return 0;
}
