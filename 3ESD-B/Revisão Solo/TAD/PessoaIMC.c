#include "PessoaIMC.h"
#include "Peso.h"
#include "Altura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Interface
struct pessoaIMC {
    char *nome;
    Peso* peso;
    Altura* altura;
};

int pimc_isInvalido(PessoaIMC *p) {
    if (p == NULL) {
        printf("Erro: PessoaIMC nao existe (NULL).\n");
        return 1;
    }
    
    return 0;
}

// Criação e Liberação
PessoaIMC* pimc_cria(int kg, int g, int m, int cm, char *nome) {
    PessoaIMC *p = (PessoaIMC*) malloc(sizeof(PessoaIMC));
    
    if (pimc_isInvalido(p)) {
        printf("Memoria insuficiente!\n");
        return NULL;
    }
    
    p->nome = (char*) malloc(strlen(nome) * sizeof(char) + 1);
    
    if (p->nome != NULL) {
        strcpy(p->nome, nome);
    }
    
    p->peso=pes_cria(kg, g);
    p->altura=alt_cria(m, cm);
    
    return p;
}

void pimc_libera(PessoaIMC *p) {
    if (pimc_isInvalido(p)) return;
    
    pes_libera(p->peso);
    alt_libera(p->altura);

    free(p->nome);
    free(p);
}

// Alterar Peso em g
void pimc_alteraPeso(PessoaIMC *p, int g) {
    if (pimc_isInvalido(p)) return;
    
    Peso *novo_peso = pes_soma(p->peso, g);
    pes_libera(p->peso);
 
    p->peso=novo_peso;
}

// Alterar Altura em cm
void pimc_alteraAltura(PessoaIMC *p, int cm) {
    if (pimc_isInvalido(p)) return;
    
    Altura *nova_altura = alt_soma(p->altura, cm);
    alt_libera(p->altura);
    
    p->altura=nova_altura;
}

// Calcular IMC
float pimc_calcularIMC(PessoaIMC *p) {
    if (pimc_isInvalido(p)) return 0;
    
    // Peso (Kg) / Altura (m)²
    int kg, g, m, cm;
    
    pes_acessa(p->peso, &kg, &g);
    alt_acessa(p->altura, &m, &cm);
    
    float peso_kg = kg + (g + 1000.0);
    float altura_m = m + (cm / 100.0);
    
    return peso_kg / (altura_m * altura_m);
}

// Categorizar IMC
char* pimc_categorizaIMC(PessoaIMC *p) {
    if (pimc_isInvalido(p)) return NULL;
    
    float imc = pimc_calcularIMC(p);
    
    if (imc < 18.5) {
        return "Abaixo do Peso";
    } else if (imc < 25) {
        return "Peso Ideal (Normal)";
    } else if (imc < 30) {
        return "Sobrepeso";
    } else  {
        return "Obesidade";
    }
}

// Exibição no formato (Nome: nome, IMC: imc, Categoria: Categoria)
char* pimc_getPessoaIMC(PessoaIMC *p) {
    if (pimc_isInvalido(p)) return NULL;
    
    float imc = pimc_calcularIMC(p);
    char* categoria = pimc_categorizaIMC(p);

    int tam = strlen(p->nome) + strlen(categoria) + 50;
    char *string = (char*) malloc(tam);

    sprintf(string, "(Nome: %s, IMC: %.2f, Categoria: %s)", p->nome, imc, categoria);
    return string;
}

void pimc_exibePessoaIMC(PessoaIMC *p) {
    if (pimc_isInvalido(p)) return;
    
    float imc = pimc_calcularIMC(p);
    char* categoria = pimc_categorizaIMC(p);
    
    printf("(Nome: %s, IMC: %.2f, Categoria: %s)", p->nome, imc, categoria);
}