/*
Qual o valor de y no final do programa abaixo? (fonte Marcia Marra)
Escreva um comentário em cada comando de atribuição explicando o que ele faz e o
valor da variável à esquerda do &#39;=&#39; após sua execução.
int main() {
int y, *p, x;
y = 0;
p = &y;
x = *p;
x = 4;
(*p)++;
x--;
(*p) += x;
printf("y = %d\n", y);
return(0);
}
*/

// y = 4