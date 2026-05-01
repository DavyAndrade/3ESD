// Davy Andrade e Derek Gossani

#include "Horario.h"
#include "entregador.h"

typedef struct pedido Pedido;

Pedido *pedido_criar(int id, char *cliente, float valor, int hora, int minuto);
void pedido_liberar(Pedido *p);
int pedido_getID(Pedido *p);
int pedido_getStatus(Pedido *p);
float pedido_getValor(Pedido *p);
Entregador* pedido_getEntregador(Pedido *p);
void pedido_atribuir(Pedido *p, Entregador *ent, int horaSaida, int minutoSaida);
void pedido_entregar(Pedido *p, int horaEntrega, int minutoEntrega);
int pedido_tempoTotal(Pedido *p);
int pedido_tempoRota(Pedido *p);
char *pedido_paraString(Pedido *p);
