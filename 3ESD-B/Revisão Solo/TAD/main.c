#include <stdio.h>
#include <stdlib.h>
#include "Data.h"

int main(void) {
    // 1. Criando instâncias de data
    // O TAD oculta a estrutura real, então usamos apenas o ponteiro tData* [2, 4]
    printf("--- Teste de Criacao e Exibicao ---\n");
    tData* d1 = dta_cria(19, 3, 2024);
    tData* d2 = dta_cria(25, 12, 2024);

    if (d1 == NULL || d2 == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    printf("Data 1 (dta_exibe): "); 
    dta_exibe(d1); 
    printf("\n");

    // 2. Testando a função que retorna String formatada
    // Importante: dta_getData usa malloc no Data.c, entao devemos dar free no main [5, 6]
    char* s_data = dta_getData(d2);
    printf("Data 2 (dta_getData): %s\n", s_data);
    free(s_data); 

    // 3. Testando Mes por Extenso
    printf("Mes da Data 1 por extenso: %s\n", dta_MesExtenso(d1));

    // 4. Testando Acesso e Atribuicao
    printf("\n--- Teste de Acesso e Alteracao ---\n");
    int d, m, a;
    dta_acessa(d1, &d, &m, &a);
    printf("Valores acessados de D1: %02d/%02d/%04d\n", d, m, a);

    printf("Alterando Data 1 para 01/01/2025...\n");
    dta_atribui(d1, 1, 1, 2025);
    dta_exibe(d1);
    printf("\n");

    // 5. Testando Calculos de Data (Intervalo e Diferença)
    printf("\n--- Teste de Calculos ---\n");
    int dias = dta_diferenca(d1, d2);
    printf("Diferenca absoluta entre D1 e D2: %d dias\n", dias);

    printf("Criando nova data 45 dias apos D2...\n");
    tData* d3 = dta_intervalo(d2, 45);
    printf("Nova data (D3): ");
    dta_exibe(d3);
    printf("\n");

    // 6. Liberando a memoria alocada dinamicamente [5, 7]
    printf("\nLimpando memoria...\n");
    dta_libera(d1);
    dta_libera(d2);
    dta_libera(d3);

    printf("Testes concluidos com sucesso.\n");
    return 0;
}