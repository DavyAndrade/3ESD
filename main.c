// Davy Andrade e Derek Gossani

#include <stdio.h>
#include <stdlib.h>
#include "entregas.h"
#include "entregador.h"
#include "pedido.h"
#include "Horario.h"

// Função auxiliar para imprimir a lista de pedidos em um determinado estado
void imprimir_pedidos(Entregas* e, const char* titulo) {
    printf("%s\n", titulo);
    char* lista = entregas_listarPendentes(e);
    if (lista != NULL && strlen(lista) > 0) {
        printf("%s", lista);
    } else {
        // Se a lista de pendentes estiver vazia, pode ser que todos foram entregues
        // Vamos verificar e listar todos os pedidos
        int todos_entregues = 1;
        for(int i = 0; i < 4; i++){ // 4 é o número de pedidos criados
             // Esta é uma simplificação, o ideal seria ter uma função para pegar todos os pedidos
        }
         printf("Nenhum pedido no estado solicitado.\n");
    }
    free(lista);
}


int main() {
    printf("=== SISTEMA DE ENTREGAS RÁPIDO EXPRESS ===\n");

    // 1. Crie um sistema de entregas
    Entregas* rapidoExpress = entregas_criar();

    // 2. Cadastre 3 entregadores
    printf("=== ENTREGADORES CADASTRADOS ===\n");
    Entregador* e1 = entregador_criar("Carlos Moto", "Moto");
    Entregador* e2 = entregador_criar("Ana Bike", "Bicicleta");
    Entregador* e3 = entregador_criar("Pedro Carro", "Carro");
    entregas_cadastrarEntregador(rapidoExpress, e1);
    entregas_cadastrarEntregador(rapidoExpress, e2);
    entregas_cadastrarEntregador(rapidoExpress, e3);
    
    // A listagem de entregadores não é uma função direta do TAD entregas.
    // Para a simulação, vamos imprimir manualmente com base nos dados que temos.
    char* str_e1 = entregador_paraString(e1);
    char* str_e2 = entregador_paraString(e2);
    char* str_e3 = entregador_paraString(e3);
    printf("%s\n%s\n%s\n", str_e1, str_e2, str_e3);
    free(str_e1);
    free(str_e2);
    free(str_e3);


    // 3. Crie 4 pedidos
    entregas_novoPedido(rapidoExpress, "Joao Silva", 32.50, 8, 15);
    entregas_novoPedido(rapidoExpress, "Maria Santos", 45.90, 8, 30);
    entregas_novoPedido(rapidoExpress, "Pedro Oliveira", 28.00, 8, 45);
    entregas_novoPedido(rapidoExpress, "Ana Costa", 67.30, 9, 00);

    // 4. Mostre o estado inicial dos pedidos
    printf("=== PEDIDOS RECEBIDOS ===\n");
    char* pendentes_inicio = entregas_listarPendentes(rapidoExpress);
    printf("%s", pendentes_inicio);
    free(pendentes_inicio);

    // 5. Solicite ao usuário o horário atual
    int hora_atual, minuto_atual;
    printf("=== CONSULTA ===\n");
    printf("Horario atual para simulacao (hora minuto): ");
    scanf("%d %d", &hora_atual, &minuto_atual);

    // 6. Simule as operações
    printf("=== INICIANDO OPERACOES (referencia: %02d:%02d) ===\n", hora_atual, minuto_atual);

    // Atribuir Pedido #1
    if (entregas_atribuirPedido(rapidoExpress, 1, hora_atual, minuto_atual)) {
        printf("%02d:%02d - Atribuindo Pedido #1 para Carlos Moto\n", hora_atual, minuto_atual);
    }

    // Atribuir Pedido #2
    if (entregas_atribuirPedido(rapidoExpress, 2, hora_atual, minuto_atual)) {
        printf("%02d:%02d - Atribuindo Pedido #2 para Ana Bike\n", hora_atual, minuto_atual);
    }

    // Mostrar pedidos em rota e aguardando
    printf("=== PEDIDOS EM ROTA (%02d:%02d) ===\n", hora_atual, minuto_atual);
    char* em_rota = entregas_listarPendentes(rapidoExpress);
    printf("%s", em_rota);
    free(em_rota);

    // Finalizar Pedido #1
    Horario* h_final1 = hor_criar(hora_atual, minuto_atual);
    hor_somarMinutos(h_final1, 25);
    if (entregas_finalizarPedido(rapidoExpress, 1, hor_getHora(h_final1), hor_getMinuto(h_final1))) {
        printf("%02d:%02d - Pedido #1 ENTREGUE por Carlos Moto\n", hor_getHora(h_final1), hor_getMinuto(h_final1));
    }

    // Finalizar Pedido #2
    Horario* h_final2 = hor_criar(hora_atual, minuto_atual);
    hor_somarMinutos(h_final2, 40);
    if (entregas_finalizarPedido(rapidoExpress, 2, hor_getHora(h_final2), hor_getMinuto(h_final2))) {
        printf("%02d:%02d - Pedido #2 ENTREGUE por Ana Bike\n", hor_getHora(h_final2), hor_getMinuto(h_final2));
    }

    // Atribuir Pedido #3
    if (entregas_atribuirPedido(rapidoExpress, 3, hor_getHora(h_final2), hor_getMinuto(h_final2))) {
         printf("%02d:%02d - Atribuindo Pedido #3 para Carlos Moto (disponivel)\n", hor_getHora(h_final2), hor_getMinuto(h_final2));
    }

    // Finalizar Pedido #3
    Horario* h_final3 = hor_criar(hora_atual, minuto_atual);
    hor_somarMinutos(h_final3, 70);
     if (entregas_finalizarPedido(rapidoExpress, 3, hor_getHora(h_final3), hor_getMinuto(h_final3))) {
        printf("%02d:%02d - Pedido #3 ENTREGUE por Carlos Moto\n", hor_getHora(h_final3), hor_getMinuto(h_final3));
    }

    // 7. Mostre o resumo final
    printf("=== RESUMO FINAL ===\n");
    printf("Faturamento Total: R$ %.2f\n", entregas_faturamento(rapidoExpress));
    
    printf("=== SITUACAO DOS PEDIDOS ===\n");
    char* todos_pedidos = entregas_listarPendentes(rapidoExpress); // Reutilizando para mostrar todos os status
    printf("%s", todos_pedidos);
    free(todos_pedidos);

    printf("=== MELHOR ENTREGADOR DO DIA ===\n");
    char* melhor = entregas_melhorEntregador(rapidoExpress);
    printf("%s\n", melhor);
    free(melhor);

    // 9. Libere toda a memória ao final
    entregas_liberar(rapidoExpress);
    hor_liberar(h_final1);
    hor_liberar(h_final2);
    hor_liberar(h_final3);
    printf("\n=== SISTEMA FINALIZADO. MEMORIA LIBERADA ===\n");

    return 0;
}
