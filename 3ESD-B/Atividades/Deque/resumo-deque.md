# Resumo Acadêmico: Deque (Double-Ended Queue)

## 1. O que é um Deque?
O **Deque** (acrônimo para *Double-Ended Queue*, ou Fila Duplamente Terminada) é um Tipo Abstrato de Dados que generaliza o conceito de uma fila padrão. Enquanto filas tradicionais seguem o princípio estrito FIFO (*First In, First Out* — o primeiro a entrar é o primeiro a sair), e pilhas seguem o LIFO (*Last In, First Out*), o Deque oferece uma flexibilidade muito maior. 

Em um Deque, os elementos podem ser **inseridos e removidos em ambas as extremidades**: tanto no **início** (frente/front) quanto no **final** (ré/rear). Dependendo de como suas operações são restringidas em uma aplicação específica, o Deque pode simular perfeitamente o comportamento tanto de uma Fila quanto de uma Pilha.

---

## 2. Diferenças dos Algoritmos em Relação à Fila Padrão

A diferença central nos algoritmos de um Deque, quando comparados aos de uma Fila Circular, reside na **bidirecionalidade das operações**. Na fila padrão, os ponteiros (ou índices, na alocação sequencial) movem-se sempre em um único sentido lógico. Já no Deque, ambos os ponteiros precisam suportar avanços e recuos.

### Fila Padrão (FIFO)
* **Inclusão (*Enqueue*):** Ocorre **exclusivamente no Final** (`R`). O ponteiro avança: `R = (R + 1) % N`.
* **Exclusão (*Dequeue*):** Ocorre **exclusivamente no Início** (`F`). O ponteiro avança: `F = (F + 1) % N`.

### Deque
O Deque herda as duas operações da fila, mas implementa os algoritmos "inversos" para cada extremidade:

#### Operações de Inclusão
1. **Inclusão no Final (Igual à Fila):** 
   * O algoritmo verifica se há espaço.
   * O ponteiro `R` (Ré) avança no sentido horário na estrutura circular: `R = (R + 1) % N`.
   * O elemento é armazenado na nova posição.
2. **Inclusão no Início (Novo no Deque):**
   * Em vez de avançar, o ponteiro `F` (Frente) precisa "dar um passo para trás", caminhando no sentido anti-horário da estrutura circular.
   * Matematicamente: `F = (F - 1 + N) % N`.
   * O elemento é armazenado na nova posição recuada.

#### Operações de Exclusão
1. **Exclusão no Início (Igual à Fila):**
   * O elemento em `F` é removido/retornado.
   * O ponteiro `F` (Frente) avança no sentido horário para apontar ao próximo elemento: `F = (F + 1) % N`.
2. **Exclusão no Final (Novo no Deque):**
   * O elemento atualizado em `R` é removido/retornado.
   * O ponteiro `R` (Ré) "dá um passo para trás", retraindo o final lógico da fila no sentido anti-horário.
   * Matematicamente: `R = (R - 1 + N) % N`.

### Resumo Comparativo de Comportamento e Algoritmo

#### Fila
* **Inclusão:** Somente no Fim (`R` avança `+1`).
* **Exclusão:** Somente no Início (`F` avança `+1`).

#### Deque
* **Inclusão:** No Fim (`R` avança `+1`) e no Início (`F` recua `-1`).
* **Exclusão:** No Início (`F` avança `+1`) e no Fim (`R` recua `-1`).

*Aritmética modular considerando `N` como o tamanho total do arranjo circular.*
