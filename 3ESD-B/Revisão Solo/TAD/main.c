#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"

int main() {
    int i, j;
    Produto* estoque[2];

    // Criando Produtos e Unidades
    estoque[0] = prod_cria("Leite", "789001", 5.00, 2);
    prod_adicionarUnidade(estoque[0], 0, uni_cria(15, 3, 2026, 501)); // Vence em 1 dia
    prod_adicionarUnidade(estoque[0], 1, uni_cria(25, 3, 2026, 502)); 

    estoque[1] = prod_cria("Manteiga", "789002", 12.00, 1);
    prod_adicionarUnidade(estoque[1], 0, uni_cria(17, 3, 2026, 901)); // Vence em 3 dias

    // Entrada da data alvo
    int d, m, a;
    printf("Digite a data de hoje para verificacao (dd mm aaaa): ");
    scanf("%d %d %d", &d, &m, &a);
    tData* hoje = dta_cria(d, m, a);

    printf("\n--- Analise de Estoque ---\n");
    for (i = 0; i < 2; i++) {
        int aplicarDesconto = FALSE;
        char* descProd = prod_getProduto(estoque[i]);
        printf("\nProduto: %s\n", descProd);
        free(descProd);

        for (j = 0; j < prod_get_qtd(estoque[i]); j++) {
            Unidade* u = prod_get_unidade(estoque[i], j);
            if (u == NULL) continue;

            int diasRestantes = uni_idade(u, hoje);
            
            // Exibir unidades que vencem na data alvo
            if (diasRestantes == 0) {
                printf("  [ALERTA] Lote %d vence hoje!\n", uni_get_lote(u));
            }

            // Regra: desconto se vencer em ate 3 dias
            if (diasRestantes >= 0 && diasRestantes <= 3) {
                aplicarDesconto = TRUE;
            }
        }

        if (aplicarDesconto) {
            printf("  >> Promocao: Aplicando 25%% de desconto por vencimento proximo.\n");
            prod_reajuste(estoque[i], -25.0);
            printf("  >> Novo preco unitario: R$ %.2f\n", prod_get_preco(estoque[i]));
        }
    }

    // Liberação total
    dta_libera(hoje);
    for (i = 0; i < 2; i++) {
        prod_libera(&estoque[i]);
    }

    printf("\nSistema encerrado e memoria limpa.\n");
    return 0;
}