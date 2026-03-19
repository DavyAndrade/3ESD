#include <stdio.h>
#include <stdlib.h>
#include "Peso.h"

int main(void) {
    // 1. Criação de pesos para teste
    printf("--- Teste de Criacao e Exibicao ---\n");
    Peso *p1 = pes_cria(70, 500); // 70kg e 500g
    Peso *p2 = pes_cria(82, 900); // 82kg e 900g

    if (p1 == NULL || p2 == NULL) {
        printf("Falha na alocação de memoria.\n");
        return 1;
    }

    printf("Peso 1: "); pes_exibePeso(p1);
    printf("Peso 2: "); pes_exibePeso(p2);

    // 2. Teste de Acesso e Atribuição
    printf("\n--- Teste de Atribuicao ---\n");
    printf("Alterando Peso 1 para 75kg fixos...\n");
    pes_atribui(p1, 75, 0);
    pes_exibePeso(p1);

    // 3. Teste da Funcionalidade Extra: Soma (Aumento de Peso)
    printf("\n--- Teste de Funcionalidade Extra (Soma) ---\n");
    printf("Somando 1200g ao Peso 1 (75kg)...\n");
    Peso *p3 = pes_soma(p1, 1200); // Deve gerar 76kg e 200g
    printf("Novo Peso 3 (Resultado da soma): ");
    pes_exibePeso(p3);

    // 4. Teste de Comparação
    printf("\n--- Teste de Comparacao ---\n");
    int comp = pes_compara(p2, p3);
    if (comp > 0) printf("Peso 2 e maior que Peso 3.\n");
    else if (comp < 0) printf("Peso 3 e maior que Peso 2.\n");
    else printf("Os pesos sao iguais.\n");

    // 5. Teste da String Dinâmica (Gestão de Memória)
    printf("\n--- Teste de String Dinamica ---\n");
    char *str = pes_getPeso(p3);
    if (str != NULL) {
        printf("String gerada pelo TAD: %s", str);
        free(str); // OBRIGATÓRIO: Liberar a string alocada internamente [5]
    }

    // 6. Teste de Cópia
    printf("\n--- Teste de Copia ---\n");
    Peso *p_copia = pes_copia(p2);
    printf("Copia do Peso 2: ");
    pes_exibePeso(p_copia);

    // 7. Liberação Final de Memória
    printf("\nLimpando memoria do Heap...\n");
    pes_libera(p1);
    pes_libera(p2);
    pes_libera(p3);
    pes_libera(p_copia);

    printf("Testes concluidos com sucesso.\n");
    return 0;
}