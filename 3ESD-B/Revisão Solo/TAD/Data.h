/* 
** TAD: Data (dia, mes, ano) 
** Tipo exportado para garantir o encapsulamento [2]
*/
typedef struct data tData;

/* Funções exportadas pelo módulo Data.c [4] */

/* 
** Aloca e retorna uma data com os valores de dia, mês e ano fornecidos [2]
*/
tData* dta_cria(int dia, int mes, int ano);

/* 
** Libera a memória de uma data previamente criada [5]
*/
void dta_libera(tData* p);

/* 
** Retorna os valores de dia, mês e ano de uma data através de ponteiros [5, 6]
*/
void dta_acessa(tData* p, int* dia, int* mes, int* ano);

/* 
** Atribui novos valores de dia, mês e ano a uma data existente [5]
*/
void dta_atribui(tData* p, int dia, int mes, int ano);

/* 
** Retorna um novo objeto tData com a data resultante após X dias [7]
*/
tData* dta_intervalo(tData* p, int X);

/* 
** Retorna a diferença absoluta em dias entre duas datas [8]
*/
int dta_diferenca(tData* dt1, tData * dt2);

/* 
** Escreve na tela a data no formato dd/mm/aaaa [9]
*/
tData* dta_exibe(tData* p);

/* 
** Retorna uma string alocada dinamicamente com a data no formato dd/mm/aaaa.
** O chamador da função fica responsável por liberar a memória da string [10]
*/
char* dta_getData(tData* p);

/* 
** Retorna o nome do mês da data por extenso [11]
*/
char* dta_MesExtenso(tData* p);