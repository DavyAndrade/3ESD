#include "Peso.h"
#include "Altura.h"

// Interface
typedef struct pessoaIMC PessoaIMC;

// Criação e Liberação
PessoaIMC* pimc_cria(int kg, int g, int m, int cm, char *nome);
void pimc_libera(PessoaIMC *p);

// Alterar Peso em g
void pimc_alteraPeso(PessoaIMC *p, int g);

// Alterar Altura em cm
void pimc_alteraAltura(PessoaIMC *p, int cm);

// Calcular IMC
float pimc_calcularIMC(PessoaIMC *p);

// Categorizar IMC
char* pimc_categorizaIMC(PessoaIMC *p);

// exibição no formato (Nome: nome, IMC: imc, Categoria: Categoria)
char* pimc_getPessoaIMC(PessoaIMC *p);
void pimc_exibePessoaIMC(PessoaIMC *p);