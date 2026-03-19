#include "Ponto.h"

typedef struct triangulo Triangulo;

// Criação do Triangulo
Triangulo *tri_cria(float x1, float y1, float x2, float y2, float x3, float y3);

// Liberar memória do Triangulo
void tri_libera(Triangulo *t);

// Retorna o valor do perimetro
float tri_perimetro(Triangulo *t);

// Retorna o Vertice i
Ponto* tri_getVertice(Triangulo *t, int i);

// Altera o Vertice i
void tri_setVertice(Triangulo *t, int i, Ponto *p);

// Retornar o valor da área
float tri_area(Triangulo *t);

// Retorna uma String de Triangulo com o formato (v1: (x,y), v2: (x,y), v3: (x,y))
char* tri_getTriangulo(Triangulo *t);

// Exibe o triângulo no formato (v1: (x,y), v2: (x,y), v3: (x,y))
void tri_exibe(Triangulo *t);