#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarações de funções auxiliares
int retira_varios(tLista *pl, int no);
int busca_des_srep(tLista *pl, int chave, int *pos);
int busca_bin(tLista *pl, int chave, int *pos);
void encontra_posInicEqt(tLista *pl, int *posRet, int *qt, int valor);
void chegaparacaMC(tLista *pl, int posRet, int qt);
void chegaparalaMC(tLista *pl, int pos);

/* Em seguida, um tipo para a lista */
struct tipo_lista {
  int *vnos;
  int qtnos;
  int maximo;
  int ehclassificada; // 1: classificada 0: não classificada
  int temrepeticao;   // 1: com repetição 0: sem repetição
};

/*cria lista vazia*/
tLista *lista_cria_vazia(int maximo, int classif, int repet) {
  tLista *pl = (tLista *)malloc(sizeof(tLista));
  pl->vnos = (int *)malloc(sizeof(int) * maximo);
  pl->qtnos = 0;
  pl->maximo = maximo;
  pl->ehclassificada = classif;
  pl->temrepeticao = repet;
  return pl;
}
// lista está vazia?
int lista_vazia(const tLista *pl) { return (pl->qtnos == 0); }
// lista está cheia?
int lista_cheia(const tLista *pl) { return (pl->qtnos == pl->maximo); }
// lista com repetição?
int lista_repet(const tLista *pl) { return (pl->temrepeticao == 1); }
// lista classificada?
int lista_classif(const tLista *pl) { return (pl->ehclassificada == 1); }
// percorre a lista
void lista_percorre(const tLista *pl) {
  int i;
  for (i = 0; i < pl->qtnos; i++)
    printf("\n%d", pl->vnos[i]);
}

int lista_inclui(tLista *pl, int novo) {
  int posNovo, achou;
  if (lista_cheia(pl))
    return 0; // não pode incluir pq tá cheio

  if (!lista_classif(pl)) {
    if (!lista_repet(pl) && busca_des_srep(pl, novo, &posNovo))
      return -1; // não pode incluir pq já existe
    posNovo = pl->qtnos;
  } else {
    achou = busca_bin(pl, novo, &posNovo);
    if (achou && !lista_repet(pl))
      return -1; // não pode incluir pq já existe
    chegaparalaMC(pl, posNovo);
  }
  pl->vnos[posNovo] = novo;
  pl->qtnos++;
  return 1; // inclusão correta
}

int lista_exclui(tLista *pl, int no) {
  int posRet, achou, qt = 1;
  if (lista_vazia(pl))
    return 0;

  if (lista_repet(pl) && !lista_classif(pl))
    // return 1;
    return retira_varios(pl, no);

  if (lista_classif(pl))
    achou = busca_bin(pl, no, &posRet);
  else
    achou = busca_des_srep(pl, no, &posRet);

  if (!achou)
    return -1; // exlusão de inexistente

  if (lista_repet(pl)) {

    printf("\nantes %d %d", posRet, qt);
    encontra_posInicEqt(pl, &posRet, &qt, no);
    printf("\ndepois %d %d", posRet, qt);
  }

  chegaparacaMC(pl, posRet, qt);
  printf("\n\n%d %d ", qt, pl->qtnos);
  pl->qtnos -= qt;
  printf("\n%d %d ", qt, pl->qtnos);
  return 1;
}

// FUNÇÕES AUXILARES
// Retira vários
int retira_varios(tLista *pl, int no) { // -1 se no não existe, ou 1

  int i, j;
  int achou = 0;
  for (i = 0; i < pl->qtnos; i++) {
    if (pl->vnos[i] == no) {
      achou = 1;
      for (j = i; j < pl->qtnos - 1; j++)
        pl->vnos[j] = pl->vnos[j + 1];
      pl->qtnos--;
      i--;
    }
  }
  return (achou) ? 1 : -1;
}

// Busca DESORDENADA sem repetição
int busca_des_srep(tLista *pl, int chave, int *pos) {
  int i;
  for (i = 0; i < pl->qtnos; i++) {
    if (pl->vnos[i] == chave) {
      *pos = i;
      return 1;
    }
  }
  *pos = -1;
  return 0;
}
// Busca BINÁRIA
int busca_bin(tLista *pl, int chave, int *pos) {
  int inicio = 0, fim = pl->qtnos - 1, meio;
  int achou = 0;

  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    if (pl->vnos[meio] == chave) {
      achou = 1;
      break;
    } else if (pl->vnos[meio] < chave)
      inicio = meio + 1;
    else
      fim = meio - 1;
  }

  if (achou)
    (*pos) = meio;
  else
    (*pos) = inicio;
  return achou;
}

void encontra_posInicEqt(tLista *pl, int *posRet, int *qt, int valor) {
  int i;
  while (*posRet > 0 && pl->vnos[*posRet - 1] == valor)
    (*posRet)--;

  *qt = 0;
  i = *posRet;
  while (i < pl->qtnos && pl->vnos[i] == valor) {
    (*qt)++;
    i++;
  }
}

// CHEGA PARA CÁ  ==> TRANSFORMAR PARA  memcpy
void chegaparaca(tLista *pl, int pos, int qt) {
  int i;
  for (i = pos; i <= pl->qtnos - qt; i++)
    pl->vnos[i] = pl->vnos[i + qt];
}

// CHEGA PARA LÁ ==> TRANSFORMAR PARA  memcpy

void chegaparala(tLista *pl, int pos) {
  int i;
  for (i = pl->qtnos; i > pos; i--)
    pl->vnos[i] = pl->vnos[i - 1];
}

void chegaparacaMC(tLista *pl, int posRet, int qt) {
  if (posRet + qt < pl->qtnos)
    memmove(&pl->vnos[posRet], &pl->vnos[posRet + qt],
            sizeof(int) * (pl->qtnos - posRet - qt));
}

void chegaparalaMC(tLista *pl, int pos) {
  if (pos < pl->qtnos)
    memmove(&pl->vnos[pos + 1], &pl->vnos[pos],
            sizeof(int) * (pl->qtnos - pos));
}
