#include "Circulo.h"
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

struct circulo {
    Ponto *centro;
    float r;
};

int circ_isInvalido(Circulo *c) {
    if (c == NULL) {
        printf("Erro: Circulo nao existe (NULL).\n");
        return 1;
    }
    
    return 0;
}

void circ_setRaio(Circulo *c, float r) {
    if (circ_isInvalido(c)) return;
    
    c->r = r;
}

Circulo *circ_cria(int x, int y, float r) {
    Circulo* c = (Circulo*) malloc(sizeof(Circulo));
    
    if (circ_isInvalido(c)) {
        printf("Memoria insuficiente!\n");
        return NULL;
    }
    
    c->centro = pto_cria(x, y);
    circ_setRaio(c, r);
    return c;
    
}

void circ_libera(Circulo *c) {
    if (circ_isInvalido(c)) return;
    
    pto_libera(c->centro);
    free(c);
}

float circ_getRaio(Circulo *c) {
    if (circ_isInvalido(c)) return 0;

    return c->r;
}

float circ_area(Circulo * c) {
    if (circ_isInvalido(c)) return 0;
    
    float raio = c->r;
    return PI * (raio * raio);
}

float circ_comprimento(Circulo *c) {
    if (circ_isInvalido(c)) return 0;
    
    return 2 * PI * c->r;
}

// Compara os círculos pelo comprimento
int circ_compara(Circulo *c1, Circulo *c2) {
    if (circ_isInvalido(c1) || circ_isInvalido(c2)) return -2;
    
    float comprimentoC1 = circ_comprimento(c1);
    float comprimentoC2 = circ_comprimento(c2);
    
    if (comprimentoC1 < comprimentoC2) {
        return -1;
    } else if (comprimentoC1 == comprimentoC2) {
        return 0;
    } else {
        return 1;
    }
}

char* circ_getCirculo(Circulo *c) {
    if (circ_isInvalido(c)) return NULL;
    
    char* msg = pto_getPonto(c->centro);
    int tam = sizeof(*c) + sizeof(*msg);
    
    char *string = (char*) malloc(tam + 20);
    
    sprintf(string, "(centro:%s, raio:%.2f)", msg, c->r);
    free(msg);
    
    return string;
}

void circ_exibe(Circulo *c) {
    if (circ_isInvalido(c)) return;
    
    char* msg = pto_getPonto(c->centro);
    
    printf("(centro:%s, raio:%.2f)", msg, c->r);
    free(msg);
}

Circulo *circ_clona(Circulo *c) {
    if (circ_isInvalido(c)) return NULL;
    
    Circulo *novoCirculo = (Circulo*) malloc(sizeof(Circulo));
    
    if (novoCirculo == NULL) {
        printf("Memoria insuficiente!\n");
        return NULL;
    }
    
    float x, y;
    pto_acessa(c->centro, &x, &y);
    
    novoCirculo->centro = pto_cria(x, y);
    circ_setRaio(novoCirculo, c->r);
    
    return novoCirculo;
}