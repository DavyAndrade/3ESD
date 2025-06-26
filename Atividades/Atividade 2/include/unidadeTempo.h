/* Tipo exportado */
typedef struct unidadeTempo UnidadeTempo;

/* Cria uma Unidade de Tempo a partir de horas, minutos e segundos.
   Os valores são automaticamente normalizados (por exemplo, 70 segundos se tornam 1 minuto e 10 segundos). */
UnidadeTempo *ut_cria(int horas, int minutos, int segundos);

/* Cria uma Unidade de Tempo a partir do total de segundos */
UnidadeTempo *ut_fromSegundos(int totalSegundos);

/* Libera a memória alocada para uma Unidade de Tempo */
void ut_libera(UnidadeTempo *ut);

/* Exibe a Unidade de Tempo no formato HH:MM:SS */
void ut_exibe(UnidadeTempo *ut);

/* Converte a Unidade de Tempo para o total de segundos */
int ut_toSegundos(UnidadeTempo *ut);

/* Retorna uma nova Unidade de Tempo que é a soma de duas Unidades de Tempo */
UnidadeTempo *ut_soma(UnidadeTempo *ut1, UnidadeTempo *ut2);

/* Retorna uma nova Unidade de Tempo que é a diferença (valor absoluto) entre duas Unidades de Tempo */
UnidadeTempo *ut_subtrai(UnidadeTempo *ut1, UnidadeTempo *ut2);

/* Compara duas Unidades de Tempo:
   - Retorna -1 se ut1 for menor que ut2
   - Retorna  0 se forem iguais
   - Retorna  1 se ut1 for maior que ut2 */
int ut_compara(UnidadeTempo *ut1, UnidadeTempo *ut2);