#include "Ponto.h"

typedef struct circulo Circulo;

// Criação do Círculo
Circulo *circ_cria(int x, int y, float r);

// Liberar memória do Círculo
void circ_libera(Circulo *c);

// Get e Set Raio
float circ_getRaio(Circulo *c);
void circ_setRaio(Circulo *c, float r);

// Retornar o valor da área do Círculo
float circ_area(Circulo * c);

// Retornar o valor da circunferência (perímetro)
float circ_comprimento(Circulo *c);

// Compara os círculos pelo comprimento
int circ_compara(Circulo *c1, Circulo *c2);

// Retorna uma String de Circulo com o formato (c:centro,r:raio)
char* circ_getCirculo(Circulo *c);

// Exibe o círculo no formato(c:centro,r:raio)
void circ_exibe(Circulo *c);

// Clona um Circulo
Circulo *circ_clona(Circulo *c);