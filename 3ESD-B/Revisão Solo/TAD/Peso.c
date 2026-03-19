#include "Peso.h"
#include <stdio.h>
#include <stdlib.h>

// Interface
struct peso {
    int kg;
    int g;
};

int pes_converteParaGrama(Peso *p) {
    return (p->kg * 1000) + p->g;
}

int pes_isInvalido(Peso *p) {
    if (p == NULL) {
        printf("Erro: Peso nao existe (NULL).\n");
        return 1;
    } 
    
    return 0;
}

// Criação
Peso* pes_cria(int kg, int g) {
    Peso *p = (Peso*) malloc(sizeof(Peso));
    
    if (pes_isInvalido(p)) {
        printf("Memoria insuficiente!\n");
        return NULL;
    }
    
    p->kg=kg;
    p->g=g;
    
    return p;
}

// Liberar memória
void pes_libera(Peso *p) {
    if (pes_isInvalido(p)) return;
    
    free(p);
}

// Acesso aos atributos
void pes_acessa(Peso *p, int *kg, int *g) {
    if (pes_isInvalido(p)) return;
    
    *kg=p->kg;
    *g=p->g;
}

void pes_acessaKg(Peso *p, int *kg) {
    if (pes_isInvalido(p)) return;
    
    *kg=p->kg;
}

void pes_acessaG(Peso *p, int *g) {
    if (pes_isInvalido(p)) return;
    
    *g=p->g;
}

// Atribuição aos atributos
void pes_atribui(Peso *p, int kg, int g) {
    if (pes_isInvalido(p)) return;
    
    p->kg = kg;
    p->g = g;
}

void pes_atribuiKg(Peso *p, int kg) {
    if (pes_isInvalido(p)) return;
    
    p->kg = kg;
}

void pes_atribuiG(Peso *p, int g) {
    if (pes_isInvalido(p)) return;
    
    p->g = g;
}

// Auxiliares
int pes_compara(Peso *p1, Peso *p2) {
    if (pes_isInvalido(p1) || pes_isInvalido(p2)) return -2;
    int peso1 = pes_converteParaGrama(p1);
    int peso2 = pes_converteParaGrama(p2);

    if (peso1 > peso2) {
        return 1;
    } else if (peso1 == peso2) {
        return 0;
    } else {
        return -1;
    }
}

Peso *pes_copia(Peso *p) {
    if (pes_isInvalido(p)) return NULL;
    
    return pes_cria(p->kg, p->g);
}

Peso *pes_soma(Peso *p, int g) {
    int peso_total = pes_converteParaGrama(p) + g;
    int novo_kg = peso_total / 1000;
    int novo_g = peso_total % 1000;
    
    return pes_cria(novo_kg, novo_g);
}

// exibição no formato (Kg: kg, G: g)
char* pes_getPeso(Peso *p) {
    if (pes_isInvalido(p)) return NULL;
    
    int tam = sizeof(*p) + 40;
    char *string = (char*) malloc(tam);
    
    sprintf(string, "(Kg:%d, G:%d)\n", p->kg, p->g);
    return string;
}

void pes_exibePeso(Peso *p) {
    if (pes_isInvalido(p)) return;

    
    printf("(Kg:%d, G:%d)\n", p->kg, p->g);
}