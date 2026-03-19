#include <stdio.h>
#include <stdlib.h>
#include "Circulo.h"

int main(void) {
    // 1. Criando círculos para teste
    printf("--- Teste de Criacao ---\n");
    Circulo *c1 = circ_cria(0, 0, 5.0);   // Centro (0,0), raio 5
    Circulo *c2 = circ_cria(10, 10, 12.0); // Centro (10,10), raio 12

    if (c1 == NULL || c2 == NULL) return 1;

    printf("C1: "); circ_exibe(c1); printf("\n");
    printf("C2: "); circ_exibe(c2); printf("\n");

    // 2. Testando Cálculos
    printf("\n--- Teste de Metricas (C1) ---\n");
    printf("Raio: %.2f\n", circ_getRaio(c1));
    printf("Area: %.2f\n", circ_area(c1));
    printf("Comprimento: %.2f\n", circ_comprimento(c1));

    // 3. Testando Comparação (pelo comprimento)
    printf("\n--- Teste de Comparacao ---\n");
    int res = circ_compara(c1, c2);
    if (res == -1) printf("C1 e menor que C2\n");
    else if (res == 0) printf("C1 e igual a C2\n");
    else printf("C1 e maior que C2\n");

    // 4. Testando o Clone (Deep Copy)
    printf("\n--- Teste de Clone (Independencia de Memoria) ---\n");
    Circulo *c3 = circ_clona(c1);
    printf("C3 (Clone de C1): "); circ_exibe(c3); printf("\n");

    printf("Alterando raio de C3 para 100.0...\n");
    circ_setRaio(c3, 100.0);
    
    printf("C3 atualizado: "); circ_exibe(c3); printf("\n");
    printf("C1 original: "); circ_exibe(c1); printf(" (Deve continuar raio 5.0)\n");

    // 5. Testando geração de String dinâmica
    printf("\n--- Teste de String Dinamica ---\n");
    char *s = circ_getCirculo(c2);
    if (s != NULL) {
        printf("String do C2: %s\n", s);
        free(s); // Importante: Liberar a string alocada pelo TAD [3, 4]
    }

    // 6. Liberação de Memória
    printf("\nLiberando memoria...\n");
    circ_libera(c1);
    circ_libera(c2);
    circ_libera(c3);

    printf("Concluido com sucesso.\n");
    return 0;
}