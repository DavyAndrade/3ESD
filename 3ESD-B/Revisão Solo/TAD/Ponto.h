/*Tipo exportado */
/* cria um ponto no pano cartesiano (x,y)*/
typedef struct ponto Ponto;

/* Funções exportadas */
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y);

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(Ponto* p);

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y);

void pto_acessaX(Ponto* pto, float *coord);

void pto_acessaY(Ponto* pto, float *coord);

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y);

void pto_atribuiX(Ponto* p, float x);
void pto_atribuiY(Ponto* p, float y);

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto* p);

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p);

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2);

/* função compara -1:se o pt1 < pt2, 0 se pt1 == pt2, +1 se o pt1 > pt2  */
/* um ponto é menor do que o outro se estiver mais próximo da origem*/
int pto_compara(Ponto*p1,Ponto*p2);

void pto_copia(Ponto *pto1, Ponto *pto2);

void pto_quadrante(Ponto *pto);