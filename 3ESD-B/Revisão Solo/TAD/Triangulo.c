#include "Triangulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangulo {
  Ponto *v1;
  Ponto *v2;
  Ponto *v3;
};

int tri_isInvalido(Triangulo *t) {
    if (t == NULL) {
        printf("Erro: Triangulo nao existe (NULL).\n");
        return 1;
    }
    
    return 0;
}

// Criação do Triangulo
Triangulo *tri_cria(float x1, float y1, float x2, float y2, float x3, float y3) {
    Triangulo *t = (Triangulo*) malloc(sizeof(Triangulo));
    
    if (tri_isInvalido(t)) {
        printf("Memoria insuficiente!\n");
        return NULL;
    }
    
    t->v1 = pto_cria(x1, y1);
    t->v2 = pto_cria(x2, y2);
    t->v3 = pto_cria(x3, y3);
    
    return t;
}

// Liberar memória do Triangulo
void tri_libera(Triangulo *t) {
    if (tri_isInvalido(t)) return;
    
    pto_libera(t->v1);
    pto_libera(t->v2);
    pto_libera(t->v3);
    
    free(t);
}

// Retorna o valor do perimetro
float tri_perimetro(Triangulo *t) {
    if (tri_isInvalido(t)) return 0;
    
    float dist1 = pto_distancia(t->v1, t->v2);
    float dist2 = pto_distancia(t->v2, t->v3);
    float dist3 = pto_distancia(t->v3, t->v1);
    
    return dist1 + dist2 + dist3;
}

// Retorna o Vertice i
Ponto* tri_getVertice(Triangulo *t, int i) {
     if (tri_isInvalido(t)) return NULL;
     
     if (i == 1) {
         return t->v1;
     } else if (i == 2) {
         return t->v2;
     } else if (i == 3) {
         return t->v3;
     } else {
         printf("Insira um vertice valido!\n");
         return NULL;
     }
}

// Altera o Vertice i
void tri_setVertice(Triangulo *t, int i, Ponto *p) {
    if (tri_isInvalido(t)) return;
    
    if (i == 1) {
        pto_libera(t->v1);
         t->v1 = p;
     } else if (i == 2) {
         pto_libera(t->v2);
         t->v2 = p;
     } else if (i == 3) {
         pto_libera(t->v3);
         t->v3 = p;
     } else {
         printf("Insira um vertice valido!\n");
         return;
     }
}

// Retornar o valor da área
float tri_area(Triangulo *t) {
    if (tri_isInvalido(t)) return 0;
    
    float a = pto_distancia(t->v1, t->v2);
    float b = pto_distancia(t->v2, t->v3);
    float c = pto_distancia(t->v3, t->v1);
    float s = (a + b + c) / 2;
    
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

// Retorna uma String de Triangulo com o formato (v1: (x,y), v2: (x,y), v3: (x,y))
char* tri_getTriangulo(Triangulo *t) {
    if (tri_isInvalido(t)) return NULL;
    
    char *v1 = pto_getPonto(t->v1);
    char *v2 = pto_getPonto(t->v2);
    char *v3 = pto_getPonto(t->v3);
    int tam = sizeof(*t) + sizeof(v1) + sizeof(v2) + sizeof(v3); 
    
    char *string = (char*) malloc(tam + 40);
    
     float x1, y1, x2, y2, x3, y3;
    
    pto_acessa(t->v1, &x1, &y1);
    pto_acessa(t->v2, &x2, &y2);
    pto_acessa(t->v3, &x3, &y3);
    
    sprintf(string, "v1: (%.2f,%.2f), v2: (%.2f,%.2f), v3: (%.2f,%.2f)\n", x1, y1, x2, y2, x3, y3);
    
    return string;
}

// Exibe o triângulo no formato (v1: (x,y), v2: (x,y), v3: (x,y))
void tri_exibe(Triangulo *t) {
    if (tri_isInvalido(t)) return;
    
    float x1, y1, x2, y2, x3, y3;

    pto_acessa(t->v1, &x1, &y1);
    pto_acessa(t->v2, &x2, &y2);
    pto_acessa(t->v3, &x3, &y3);
    
    printf("v1: (%.2f,%.2f), v2: (%.2f,%.2f), v3: (%.2f,%.2f)\n", x1, y1, x2, y2, x3, y3);
}