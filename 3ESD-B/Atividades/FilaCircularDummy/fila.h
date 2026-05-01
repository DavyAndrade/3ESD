#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;

/* Cria uma fila com a capacidade informada */
Fila* fila_criar(int capacidade);

/* Libera a memoria alocada pela fila */
void fila_liberar(Fila* f);

/* Insere um elemento na fila. Retorna 1 em caso de sucesso ou 0 em caso de erro */
int fila_inserir(Fila* f, int valor);

/* Remove um elemento da fila. Retorna 1 em caso de sucesso ou 0 em caso de erro */
int fila_remover(Fila* f, int* valor);

/* Verifica se a fila esta vazia. Retorna 1 se vazia, 0 caso contrario */
int fila_vazia(Fila* f);

/* Verifica se a fila esta cheia. Retorna 1 se cheia, 0 caso contrario */
int fila_cheia(Fila* f);

/* Imprime os elementos da fila */
void fila_imprimir(Fila* f);

#endif
