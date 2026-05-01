// Davy Andrade e Derek Gossani

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ==================== TAD HORÁRIO (FORNECIDO) ====================*/
typedef struct horario  Horario;

/**
 * Cria um novo horário com hora e minuto especificados
 * @param hora Hora (0-23)
 * @param minuto Minuto (0-59)
 * @return Ponteiro para o Horario alocado
 */
Horario* hor_criar(int hora, int minuto) ;

/**
 * Cria um horário com o momento atual do sistema
 * @return Ponteiro para o Horario com a hora atual
 */
Horario* hor_atual() ;
/**
 * Calcula a diferença absoluta em minutos entre dois horários
 * @param h1 Primeiro horário
 * @param h2 Segundo horário
 * @return Número de minutos de diferença (sempre positivo)
 */
int hor_diferencaMinutos(Horario* h1, Horario* h2) ;

/**
 * Compara dois horários
 * @param h1 Primeiro horário
 * @param h2 Segundo horário
 * @return 0 se iguais, positivo se h1 > h2, negativo se h1 < h2
 */
int hor_comparar(Horario* h1, Horario* h2) ;

/**
 * Retorna uma representação em string do horário no formato "HH:MM"
 * @param h Horário
 * @return String alocada dinamicamente (deve ser liberada com free())
 */
char* hor_paraString(Horario* h) ;

/**
 * Libera a memória de um horário
 * @param h Horário a ser liberado
 */
void hor_liberar(Horario* h);

/**
 * Soma minutos a um horário
 * @param h Horário
 * @param minutos Minutos a somar
 */
void hor_somarMinutos(Horario* h, int minutos);

/**
 * Obtém a hora de um horário
 * @param h Horário
 * @return Hora (0-23)
 */
int hor_getHora(Horario* h);

/**
 * Obtém o minuto de um horário
 * @param h Horário
 * @return Minuto (0-59)
 */
int hor_getMinuto(Horario* h);