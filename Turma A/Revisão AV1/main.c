// Questão 2) Usando os TADs Data e Produto, construa uma main que:

// a) crie um vetor para armazenar 6 produtos
// b) preencha o vetor com 6 produtos. ( sem leitura de dados)
// c) Mostre para cada produto: seu nome e mês por extenso que o produto estará fora da
// validade

// I

// // Representação do TAD: TData
// //-----------
// // Interface
// //-----------
// typedef struct data tData;
// /* Funções exportadas */
// /* Função cria - Aloca e retorna uma data
// dia/mes/ano */
// tData *dta_cria(int dia, int mes, int ano);
// /* Função libera - Libera memória de uma Data
// criada */
// void dta_libera(tData *p);
// /* Função acessa - Retorna os valores de uma Data
//  */
// void dta_acessa(tData *p, int *dia, int *mes, int *ano);
// /* Função atribui - Atribui novos valores à Data
//  */
// void dta_atribui(tData *p, int dia, int mes, int ano);
// /* Função Intervalo - Retorna a data após X dias
//  */
// tData *dta_intervalo(tData *p1, int X);
// /* Função Exibe - Escreve na tela a data no
// formato dd/mm/aaaa */
// tData *dta_exibe(tData *p1);
// /* Função getData - Retorna uma string com os
// valores da data no formato dd/mm/aaaa*/
// char *dta_getData(tData *p);

// /* Função maiorIgual - Recebe duas datas e retorna
// 1 se a dta1 for maior ou igual a data 2 (mais
// recente) ou 0 caso contrário
// 12/10/2022 é maior ou igual a 12/09/2022
// */
// int dta_maiorIgual(tData *p1, tData *p2);
// /* Função dta_MesExtensol - Recebe uma data e
// retorna o mês da data por extenso*/
// char *dta_MesExtenso(tData *p);
// ____________________________________________
// // Representação do TAD: tProduto
// typedef struct tProd tProduto;
// /*
// Um produto possui:
// nome: string
// codBarras: string;
// dta de Fabricação: Data
// dias de validade:int
// preco: float
// */
// // Interface
// // cria um produto: recebe nome, codBarras,
// dia, mes, ano da fabricação, n de dias da validade,
//     preço

#include "tData.h"
#include "tProduto.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    tProduto *produtos[6];

    // Criando produtos diretamente (nome, codBarras, dia, mes, ano, validade, preco)
    produtos[0] = prd_cria("Leite", "789123456001", 12, 3, 2025, 30, 5.99);
    produtos[1] = prd_cria("Arroz", "789123456002", 5, 1, 2025, 180, 18.75);
    produtos[2] = prd_cria("Feijão", "789123456003", 20, 2, 2025, 120, 9.50);
    produtos[3] = prd_cria("Macarrão", "789123456004", 10, 4, 2025, 365, 4.20);
    produtos[4] = prd_cria("Açúcar", "789123456005", 1, 5, 2025, 730, 3.80);
    produtos[5] = prd_cria("Café", "789123456006", 25, 12, 2024, 540, 14.99);

    printf("Produtos e mês de vencimento:\n");

    for (int i = 0; i < 6; i++)
    {
        char *nome = prd_getNome(produtos[i]);

        // Obtendo a data de validade
        tData *dataValidade;
        prd_getDataValidade(produtos[i], &dataValidade);

        // Pegando o mês por extenso
        char *mesExt = dta_MesExtenso(dataValidade);

        printf("Produto: %s - Mês de validade: %s\n", nome, mesExt);

        // Liberar memória da data de validade retornada
        dta_libera(dataValidade);
    }

    for (int i = 0; i < 6; i++)
    {
        prd_libera(produtos[i]);
    }

    return 0;
}