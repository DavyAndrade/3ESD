// Davy Andrade e Derek Gossani

#include "entregas.h"
#include "Horario.h"
#include "entregador.h"
#include "pedido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entregas
{
    Entregador **entregadores; // vetor dinâmico
    int qtdEntregadores;
    int capEntregadores;
    Pedido **pedidos; // vetor dinâmico
    int qtdPedidos;
    int capPedidos;
    int proximoID; // próximo ID disponível (começa em 1)
};

Entregas *entregas_criar()
{
    Entregas *e = (Entregas *)malloc(sizeof(Entregas));
    if (e == NULL)
    {
        return NULL;
    }

    e->entregadores = (Entregador **)malloc(5 * sizeof(Entregador *));
    e->capEntregadores = 5;
    e->qtdEntregadores = 0;

    e->pedidos = (Pedido **)malloc(5 * sizeof(Pedido *));
    e->capPedidos = 5;
    e->qtdPedidos = 0;

    e->proximoID = 1;

    return e;
}

void entregas_liberar(Entregas *e)
{
    if (e == NULL)
        return;

    for (int i = 0; i < e->qtdEntregadores; i++)
    {
        entregador_liberar(e->entregadores[i]);
    }
    free(e->entregadores);

    for (int i = 0; i < e->qtdPedidos; i++)
    {
        pedido_liberar(e->pedidos[i]);
    }
    free(e->pedidos);

    free(e);
}

void entregas_cadastrarEntregador(Entregas *e, Entregador *ent)
{
    if (e == NULL || ent == NULL)
        return;

    if (e->qtdEntregadores == e->capEntregadores)
    {
        e->capEntregadores *= 2;
        e->entregadores = (Entregador **)realloc(e->entregadores, e->capEntregadores * sizeof(Entregador *));
    }
    e->entregadores[e->qtdEntregadores] = ent;
    e->qtdEntregadores++;
}

int entregas_novoPedido(Entregas *e, char *cliente, float valor, int hora, int minuto)
{
    if (e == NULL)
        return -1;

    if (e->qtdPedidos == e->capPedidos)
    {
        e->capPedidos *= 2;
        e->pedidos = (Pedido **)realloc(e->pedidos, e->capPedidos * sizeof(Pedido *));
    }

    Pedido *p = pedido_criar(e->proximoID, cliente, valor, hora, minuto);
    if (p == NULL)
        return -1;

    e->pedidos[e->qtdPedidos] = p;
    e->qtdPedidos++;

    int id = e->proximoID;
    e->proximoID++;
    return id;
}

int entregas_buscarEntregadorLivre(Entregas *e)
{
    if (e == NULL)
        return -1;

    for (int i = 0; i < e->qtdEntregadores; i++)
    {
        if (entregador_estaDisponivel(e->entregadores[i]))
        {
            return i;
        }
    }
    return -1;
}

int entregas_atribuirPedido(Entregas *e, int idPedido, int horaSaida, int minutoSaida)
{
    if (e == NULL)
        return 0;

    Pedido *p = NULL;
    for (int i = 0; i < e->qtdPedidos; i++)
    {
        if (pedido_getID(e->pedidos[i]) == idPedido)
        {
            p = e->pedidos[i];
            break;
        }
    }

    if (p == NULL)
        return 0;

    int idxEntregador = entregas_buscarEntregadorLivre(e);
    if (idxEntregador == -1)
        return 0;

    Entregador *ent = e->entregadores[idxEntregador];
    pedido_atribuir(p, ent, horaSaida, minutoSaida);
    entregador_setDisponivel(ent, 0);

    return 1;
}

int entregas_finalizarPedido(Entregas *e, int idPedido, int horaEntrega, int minutoEntrega)
{
    if (e == NULL)
        return 0;

    Pedido *p = NULL;
    for (int i = 0; i < e->qtdPedidos; i++)
    {
        if (pedido_getID(e->pedidos[i]) == idPedido)
        {
            p = e->pedidos[i];
            break;
        }
    }

    if (p == NULL || pedido_getStatus(p) != 1)
        return 0;

    pedido_entregar(p, horaEntrega, minutoEntrega);

    Entregador *ent = pedido_getEntregador(p);
    if (ent != NULL)
    {
        entregador_setDisponivel(ent, 1);
    }

    return 1;
}

char *entregas_listarPendentes(Entregas *e)
{
    if (e == NULL)
        return NULL;

    char *lista = (char *)malloc(e->qtdPedidos * 200 * sizeof(char));
    lista[0] = '\0';

    for (int i = 0; i < e->qtdPedidos; i++)
    {
        if (pedido_getStatus(e->pedidos[i]) == 0 || pedido_getStatus(e->pedidos[i]) == 1)
        {
            char *pStr = pedido_paraString(e->pedidos[i]);
            strcat(lista, pStr);
            strcat(lista, "\n");
            free(pStr);
        }
    }
    return lista;
}

float entregas_faturamento(Entregas *e)
{
    if (e == NULL)
        return 0;

    float total = 0;
    for (int i = 0; i < e->qtdPedidos; i++)
    {
        if (pedido_getStatus(e->pedidos[i]) == 2)
        {
            total += pedido_getValor(e->pedidos[i]);
        }
    }
    return total;
}

char *entregas_melhorEntregador(Entregas *e)
{
    if (e == NULL || e->qtdEntregadores == 0)
        return NULL;

    Entregador *melhor = e->entregadores[0];
    for (int i = 1; i < e->qtdEntregadores; i++)
    {
        if (entregador_getEntregas(e->entregadores[i]) > entregador_getEntregas(melhor))
        {
            melhor = e->entregadores[i];
        }
    }

    char *resultado = (char *)malloc(100 * sizeof(char));
    sprintf(resultado, "%s | %d entregas", entregador_getNome(melhor), entregador_getEntregas(melhor));

    return resultado;
}