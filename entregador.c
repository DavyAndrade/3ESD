// Davy Andrade e Derek Gossani

#include "entregador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entregador {
char nome[50];
char veiculo[20];
int disponivel; // 1 = livre, 0 = ocupado
int entregas; // total de entregas realizadas
};

int entregador_isInvalido(Entregador *e) {
    if (e == NULL) {
        printf("ERRO: Memoria insuficiente para Entregador!\n");
        return 1;
    }
    
    return 0;
}

Entregador* entregador_criar(char* nome, char* veiculo) {
    Entregador *e = (Entregador*) malloc(sizeof(Entregador));
    
    if (entregador_isInvalido(e)) {
        return NULL;
    }
    
    strcpy(e->nome, nome);
    strcpy(e->veiculo, veiculo);
    
    e->disponivel = 1;
    e->entregas = 0;
    
    return e;
}

void entregador_liberar(Entregador* e) {
    if (entregador_isInvalido(e)) return;
    
    free(e);
}

char* entregador_getNome(Entregador* e) {
    if (entregador_isInvalido(e)) return NULL;
    
    return e->nome;
}

void entregador_setDisponivel(Entregador* e, int disp) {
    if (entregador_isInvalido(e)) return;
    
    e->disponivel = disp;
}

int entregador_estaDisponivel(Entregador* e) {
    if (entregador_isInvalido(e)) return -1;
    
    if (e->disponivel == 1) {
        return 1;
    } else {
        return 0;
    }
}

void entregador_contabilizarEntrega(Entregador* e) {
    if (entregador_isInvalido(e)) return;
    
    e->entregas += 1;
}

int entregador_getEntregas(Entregador* e) {
    if (entregador_isInvalido(e)) return 0;
    
    return e->entregas;
}

// formato esperado: Carlos Moto | Moto | Disponível | Entregas: 0
char* entregador_paraString(Entregador* e) {
    if (entregador_isInvalido(e)) return NULL;
    
    char *disponibilidade;
    
    if (e->disponivel == 1) {
        disponibilidade = "Disponivel";
    } else {
        disponibilidade = "Ocupado";
    }
    
    int tam = strlen(e->nome) + strlen(e->veiculo) + strlen(disponibilidade) + 50;
    
    char* string = (char*) malloc(tam);
    
    sprintf(string, "%s | %s | %s | Entregas: %d", e->nome, e->veiculo, disponibilidade, e->entregas);
    
    return string;
}