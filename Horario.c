// Davy Andrade e Derek Gossani

#include "Horario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ==================== TAD HORÁRIO (FORNECIDO) ====================*/
struct horario {
    int hora;
    int minuto;
} ;

/**
 * Cria um novo horário com hora e minuto especificados
 * @param hora Hora (0-23)
 * @param minuto Minuto (0-59)
 * @return Ponteiro para o Horario alocado
 */
Horario* hor_criar(int hora, int minuto) {
    Horario* h = (Horario*)malloc(sizeof(Horario));
    h->hora = hora;
    h->minuto = minuto;
    return h;
}

/**
 * Cria um horário com o momento atual do sistema
 * @return Ponteiro para o Horario com a hora atual
 */
Horario* hor_atual() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return hor_criar(tm.tm_hour, tm.tm_min);
}

/**
 * Calcula a diferença absoluta em minutos entre dois horários
 * @param h1 Primeiro horário
 * @param h2 Segundo horário
 * @return Número de minutos de diferença (sempre positivo)
 */
int hor_diferencaMinutos(Horario* h1, Horario* h2) {
    int mins1 = h1->hora * 60 + h1->minuto;
    int mins2 = h2->hora * 60 + h2->minuto;
    return abs(mins1 - mins2);
}

/**
 * Compara dois horários
 * @param h1 Primeiro horário
 * @param h2 Segundo horário
 * @return 0 se iguais, positivo se h1 > h2, negativo se h1 < h2
 */
int hor_comparar(Horario* h1, Horario* h2) {
    if (h1->hora > h2->hora) return 1;
    if (h1->hora < h2->hora) return -1;
    if (h1->minuto > h2->minuto) return 1;
    if (h1->minuto < h2->minuto) return -1;
    return 0;
}

/**
 * Retorna uma representação em string do horário no formato "HH:MM"
 * @param h Horário
 * @return String alocada dinamicamente (deve ser liberada com free())
 */
char* hor_paraString(Horario* h) {
    if (h == NULL) return strdup("NULL");
    char* str = (char*)malloc(6 * sizeof(char)); // "HH:MM" + '\0' = 6 bytes
    sprintf(str, "%02d:%02d", h->hora, h->minuto);
    return str;
}

/**
 * Libera a memória de um horário
 * @param h Horário a ser liberado
 */
void hor_liberar(Horario* h) {
    free(h);
}

void hor_somarMinutos(Horario* h, int minutos) {
    if (h == NULL) return;
    
    int totalMinutos = h->hora * 60 + h->minuto + minutos;
    h->hora = (totalMinutos / 60) % 24;
    h->minuto = totalMinutos % 60;
}

int hor_getHora(Horario* h) {
    if (h == NULL) return -1;
    return h->hora;
}

int hor_getMinuto(Horario* h) {
    if (h == NULL) return -1;
    return h->minuto;
}