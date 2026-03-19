#include "Ponto.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

/* Implementação TAD: Ponto (x,y) */
/*definição do tipo exportado*/ 
struct ponto {
   double x;
   double y;
};

/*definição das funções exportadas*/ 
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y){
   Ponto* p = (Ponto*) malloc(sizeof(Ponto));
   if (p == NULL) {
      printf("Memoria insuficiente!\n");
      return NULL;
   }
   else {
    p->x = x;
    p->y = y;
   }
   return p;
}

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(Ponto* p) {
  free(p);
}

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y) {
  *x=p->x;
  *y=p->y;
}

void pto_acessaX(Ponto* pto, float *coord) {
    *coord=pto->x;
}

void pto_acessaY(Ponto* pto, float *coord) {
    *coord=pto->y;
}

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y) {
  p->x=x;
  p->y=y;
}

void pto_atribuiX(Ponto* p, float x) {
    p->x=x;
}

void pto_atribuiY(Ponto* p, float y) {
    p->y=y;
}

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2) {
  float dx = p2->x - p1->x;
  float dy = p2->y - p1->y;
  return sqrt(dx*dx + dy*dy);

  
}

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p1) {
  char* pt;
  int tam = sizeof(*p1)+ 8;
  pt = (char*)malloc(tam);
  sprintf(pt,"( %.2f , %.2f )", p1->x, p1->y);
  return pt;

}

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto* p) {
  printf(" (%.2f,%.2f) ",p->x,p->y);
}

/* função compara -1:se o pt1 < pt2, 0 se pt1 == pt2, +1 se o pt1 > pt2  */
/* um ponto é menor do que o outro se estiver mais próximo da origem*/
int pto_compara(Ponto*p1,Ponto*p2){
    if (p1->x ==p2->x  && p1->y ==p2->y)
        return 0;
     Ponto* origem=pto_cria(0,0);
     float dist1=pto_distancia(p1,origem);
     float dist2=pto_distancia(p2,origem);
     pto_libera(origem);
     if (dist1 == dist2)
        if (p1->x < p2->x ||p1->y < p2->y )
            return -1;
        else
            return 1;
     else if (dist1 < dist2)
        return -1;
    else
        return 1;
     
}


void pto_copia(Ponto *ptoOrig, Ponto *ptoDest) {
    ptoDest->x=ptoOrig->x;
    ptoDest->y=ptoOrig->y;
}

void pto_quadrante(Ponto *pto) {
    float coordX = pto->x;
    float coordY = pto->y;
    
    if (coordX == 0 && coordY == 0) {
        printf("Ponto de Origem");
        return;
    }
    
    if (coordX > 0 && coordY > 0) {
        printf("Primeiro Quadrante");
    } else if (coordX < 0 && coordY > 0) {
        printf("Segundo Quadrante");
    } else if (coordX < 0 && coordY < 0) {
        printf("Terceiro Quadrante");
    } else {
        printf("Quarto Quadrante");
    }
}