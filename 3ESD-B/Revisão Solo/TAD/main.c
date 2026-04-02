/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP,
Ruby, C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS,
JS Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "Lista.h"
#include <stdio.h>
int main() {
  tLista *lista;
  lista = lista_cria_vazia(5, 1, 1); //  classif , com repet
  // lista_inclui(lista,2);
  lista_inclui(lista, 1);
  // lista_inclui(lista,2);
  lista_inclui(lista, 1);
  lista_inclui(lista, 5);
  lista_inclui(lista, 5);
  lista_inclui(lista, 5);

  lista_percorre(lista);

  lista_exclui(lista, 1);

  lista_percorre(lista);

  return 0;
}