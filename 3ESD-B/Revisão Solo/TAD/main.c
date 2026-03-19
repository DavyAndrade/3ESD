#include <stdio.h>
#include <stdlib.h>
#include "Altura.h"

int main(void) {
    // 1. Teste de Criação e Exibição
    printf("--- Teste de Criacao e Exibicao ---\n");
    Altura *a1 = alt_cria(1, 75); // 1,75m
    Altura *a2 = alt_cria(1, 90); // 1,90m

    if (a1 == NULL || a2 == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("Altura 1 (alt_exibe):");
    alt_exibe(a1); 
    printf("\n");

    // 2. Testando a função que retorna String formatada
    // De acordo com as fontes, o chamador é responsável por liberar strings alocadas pelo TAD [4].
    char *s_altura = alt_getAltura(a2);
    printf("Altura 2 (alt_getAltura): %s\n", s_altura);
    free(s_altura); 

    // 3. Testando Acesso e Atribuição
    printf("\n--- Teste de Acesso e Alteracao ---\n");
    int m, cm;
    alt_acessa(a1, &m, &cm);
    printf("Valores acessados de A1: %d metros e %d centimetros\n", m, cm);

    printf("Alterando Altura 1 para 2,10m...");
    alt_atribui(a1, 2, 10);
    alt_exibe(a1);
    printf("\n");

    // 4. Testando Comparação
    printf("\n--- Teste de Comparacao ---\n");
    int diff = alt_compara(a1, a2);
    if (diff > 0) printf("A1 e maior que A2 por %d cm.\n", diff);
    else if (diff < 0) printf("A1 e menor que A2 por %d cm.\n", -diff);
    else printf("As alturas sao iguais.\n");

    // 5. Testando Soma
    // Note que alt_soma retorna um NOVO ponteiro alocado, que deve ser liberado [5].
    printf("\n--- Teste de Soma ---\n");
    printf("Somando 15cm a Altura 2 (1,90m)...");
    Altura *a3 = alt_soma(a2, 15);
    alt_exibe(a3); // Esperado: 2,05m
    printf("\n");

    // 6. Testando Cópia (Deep Copy)
    printf("\n--- Teste de Copia ---\n");
    Altura *a4 = alt_copia(a3);
    printf("Copia de A3 (A4):");
    alt_exibe(a4);
    printf("\n");

    // 7. Liberação de Memória
    // É essencial liberar toda a memória alocada dinamicamente no Heap [6, 7].
    printf("\nLimpando memoria...\n");
    alt_libera(a1);
    alt_libera(a2);
    alt_libera(a3);
    alt_libera(a4);

    printf("Testes concluidos com sucesso.\n");
    return 0;
}