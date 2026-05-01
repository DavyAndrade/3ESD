#include "Horario.h"
#include "entregador.h"
#include "pedido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pedido {
int id;
char cliente[50];
float valor;
Horario* horaPedido; // criado internamente
Horario* horaSaida; // criado internamente (NULL se não atribuído)
Horario* horaEntrega; // criado internamente (NULL se não entregue)
Entregador* entregador; // referência para entregador
int status; // 0, 1 ou 2
};

Pedido* pedido_criar(int id, char* cliente, float valor, int hora, int minuto) {
    Pedido *p = (Pedido*) malloc(sizeof(Pedido));
    
    if (p == NULL) {
        printf("Memoria insuficiente!\n");
        return NULL;
    }
    
    p->id = id;
    p->valor = valor;
    
    p->horaSaida = NULL;
    p->horaEntrega = NULL;
    p->entregador = NULL;
    
    p->status = 0;
    
    p->horaPedido = hor_criar(hora, minuto);
    
    strcpy(p->cliente, cliente);
    
    return p;
}

void pedido_liberar(Pedido* p) {
    if (p->horaPedido != NULL) {
        hor_liberar(p->horaPedido);
    }
    
    if (p->horaSaida != NULL) {
        hor_liberar(p->horaSaida);
    }
    
    if (p->horaEntrega != NULL) {
        hor_liberar(p->horaEntrega);
    }

    free(p);
}

int pedido_getID(Pedido* p) {
    return p->id;
}

int pedido_getStatus(Pedido* p) {
    return p->status;
}

void pedido_atribuir(Pedido* p, Entregador* ent, int horaSaida, int minutoSaida) {
    if (p->status != 0){
        return;
    }
    
    p->horaSaida = hor_criar(horaSaida, minutoSaida);
    
    if (p->horaSaida == NULL) {
        printf("Memoria insuficiente!");
        return;
    }

    p->status = 1;
    
    p->entregador = ent;
}

void pedido_entregar(Pedido* p, int horaEntrega, int minutoEntrega) {
    if (p->status != 1 && p->entregador == NULL) {
        return;
    }
    
    p->horaEntrega = hor_criar(horaEntrega, minutoEntrega);
    p->status = 2;
    
    entregador_contabilizarEntrega(p->entregador);
}

int pedido_tempoTotal(Pedido* p) {
    if (p->status != 2) {
        return -1;
    }
    
    int tempoTotal = hor_diferencaMinutos(p->horaEntrega, p->horaPedido);
    
    return tempoTotal;
}

int pedido_tempoRota(Pedido* p) {
    if (p->status != 2) {
        return -1;
    }
    
    int tempoRota = hor_diferencaMinutos(p->horaEntrega, p->horaSaida);
    
    return tempoRota;
}

float pedido_getValor(Pedido *p) {
    return p->valor;
}

Entregador* pedido_getEntregador(Pedido *p) {
    return p->entregador;
}

// formato aguardando: #1 | João Silva | R$ 32.50 | Aguardando
// formato em rota: #1 | João Silva | R$ 32.50 | Em rota | Carlos Moto | Saída: 09:30
// formato entregue: #1 | João Silva | R$ 32.50 | Entregue | 09:55 | Tempo: 100min
char* pedido_paraString(Pedido* p) {
    
    int tam = strlen(p->cliente) + 100;
    
    char *string = (char*) malloc(tam);
    char *nomeEntregador = entregador_getNome(p->entregador);
    char *horaSaida = hor_paraString(p->horaSaida);
    char *horaEntrega = hor_paraString(p->horaEntrega);
    int tempoRota = pedido_tempoRota(p);
    
     if (p->status == 0) {
        sprintf(string, "#%d | %s | R$ %.2f | Aguardando", p->id, p->cliente, p->valor);
    } else if (p->status == 1) {
        sprintf(string, "#%d | %s | R$ %.2f | Em rota | %s | Saída: %s", p->id, p->cliente, p->valor, nomeEntregador, horaSaida);
    } else {
        sprintf(string, "#%d | %s | R$ %.2f | Entregue | %s | Tempo: %dmin", p->id, p->cliente, p->valor, horaEntrega, tempoRota);
    }

   return string;
}