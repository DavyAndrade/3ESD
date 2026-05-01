// Davy Andrade e Derek Gossani

#include "entregador.h"
#include "Horario.h"
#include "pedido.h"

typedef struct entregas Entregas;

Entregas *entregas_criar();
void entregas_liberar(Entregas *e);
void entregas_cadastrarEntregador(Entregas *e, Entregador *ent);
int entregas_novoPedido(Entregas *e, char *cliente, float valor, int hora, int minuto);
int entregas_buscarEntregadorLivre(Entregas *e);
int entregas_atribuirPedido(Entregas *e, int idPedido, int horaSaida, int minutoSaida);
int entregas_finalizarPedido(Entregas *e, int idPedido, int horaEntrega, int minutoEntrega);
char *entregas_listarPendentes(Entregas *e);
float entregas_faturamento(Entregas *e);
char *entregas_melhorEntregador(Entregas *e);