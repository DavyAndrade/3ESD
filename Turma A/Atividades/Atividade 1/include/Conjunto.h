typedef struct conj Conjunto;

Conjunto *conj_cria(void); // cria um conjunto vazio para armazenar 80 numeros

void conj_exibe(Conjunto *lst); // exibe um conjunto de numeros inteiros

Conjunto *conj_remove(Conjunto *lst, int num); // remove um elemento de um conjunto de inteiros. Se o elemento nao existir, retornar o conjunto intacto

Conjunto *conj_uniao(Conjunto *lst, Conjunto *p); // cria o conjunto que e dado pela uniao dos dois conjuntos enviados como parametro

Conjunto *conj_intersecao(Conjunto *lst, Conjunto *p);
// cria o conjunto que e dado pela intersecao dos dois conjuntos enviados como parametro

Conjunto *conj_insere(Conjunto *lst, int num); // insere um novo elemento num conjunto ja criado