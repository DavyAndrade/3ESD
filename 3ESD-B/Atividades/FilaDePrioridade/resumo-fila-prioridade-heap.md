# Resumo Acadêmico: Fila de Prioridade e Heap Binário

## 1. Fila de Prioridade (Alocação Sequencial)

### Conceito
A Fila de Prioridade é um Tipo Abstrato de Dados (TAD) semelhante a uma fila comum ou pilha, porém, a regra de exclusão não é determinada pelo tempo de chegada (FIFO) ou pela última entrada (LIFO). Cada elemento inserido possui uma **prioridade** associada. O processo de remoção garante que o elemento de mais alta (ou mais baixa) prioridade seja sempre atendido primeiro.

### Implementação Básica em Alocação Sequencial (Vetores)
Na alocação sequencial comum usando arranjos unidimensionais (vetores), implementar uma Fila de Prioridade sofre com problemas de desempenho e custo computacional dependendo da estratégia:

1. **Vetor Desordenado:**
   * **Inclusão:** $O(1)$ - O novo elemento é rapidamente adicionado no final do vetor.
   * **Exclusão:** $O(N)$ - Para remover, é obrigatório realizar uma busca linear por todo o vetor para encontrar o elemento com a maior prioridade. Além disso, a remoção exige deslocamento (`shift`) dos elementos subsequentes.

2. **Vetor Ordenado:**
   * **Inclusão:** $O(N)$ - Ao inserir, é preciso procurar a posição correta para manter a ordem e deslocar todos os elementos à direita.
   * **Exclusão:** $O(1)$ - Como o elemento de maior prioridade estará sempre em uma extremidade do vetor, a remoção é direta.

Para contornar as ineficiências matemáticas dessas abordagens lineares, a Fila de Prioridade é majoritariamente implementada sobre a alocação sequencial através da estrutura lógica conhecida como **Heap Binário**, que balanceia as complexidades alcançando $O(\log N)$ para ambas as operações.

---

## 2. Heap Binário (Max-Heap ou Min-Heap)

O **Heap Binário** é conceitualmente uma Árvore Binária Completa (ou quase completa) que pode ser facilmente mapeada, posição a posição, de forma extremamente eficiente dentro de um **vetor (alocação sequencial)**, dispensando o uso de ponteiros reais para referenciar os nós filhos.

Em um vetor indexado a partir de `0`, para um dado elemento no índice `i`:
* **Índice do Pai:** `(i - 1) / 2` (divisão inteira)
* **Filho à Esquerda:** `2*i + 1`
* **Filho à Direita:** `2*i + 2`

Existem duas propriedades estruturais e de ordem possíveis:
* **Max-Heap:** O valor do nó Pai é sempre **maior ou igual** ao valor de seus filhos. A raiz possui o elemento máximo.
* **Min-Heap:** O valor do nó Pai é sempre **menor ou igual** ao valor de seus filhos. A raiz possui o elemento mínimo.

### Algoritmo de Inclusão (Inserção / *Sift-Up* ou *Up-Heap*)
O objetivo da inclusão é inserir o elemento mantendo a árvore estruturalmente completa, de cima para baixo e da esquerda para a direita.

**Passos do algoritmo (exemplo para Max-Heap):**
1. O novo elemento é inserido no **final lógico do vetor** (na primeira posição vazia, tornando-se a última folha).
2. Compara-se o recém-inserido com o seu nó Pai.
3. Se o novo nó for **maior** que seu Pai (violando a propriedade), realiza-se a troca de posições (*swap*) entre eles (o elemento "sobe").
4. Repete-se os passos 2 e 3 recursiva ou iterativamente até que o elemento não seja maior que o Pai atual, ou até que o elemento se torne a nova Raiz.

**Complexidade:** O número de comparações não passa da altura da árvore, logo o custo no pior caso é de $O(\log N)$.

### Algoritmo de Exclusão (Remoção / *Sift-Down* ou *Down-Heap*)
Em Heaps, a remoção acontece obrigatoriamente na **Raiz** (índice 0), onde está armazenado o elemento de mais alta prioridade. 

**Passos do algoritmo (exemplo para Max-Heap):**
1. O elemento na Raiz é armazenado ou retornado (este é o valor desejado).
2. O **último elemento** do Heap (última folha no final do vetor) é movido imediatamente para a **Raiz**, assumindo sua posição, e o tamanho lógico do vetor é subtraído em 1.
3. Compara-se o novo nó na Raiz com seus nós Filhos (Esquerdo e Direito).
4. Se o Pai for **menor** que qualquer um de seus Filhos (violando a regra), ele realiza um *swap* (troca) com o **filho de maior valor** entre os dois (o elemento "desce").
5. Repete-se os passos 3 e 4 enquanto houver filhos ou até que o nó assuma uma posição em que ele seja maior ou igual aos seus respectivos filhos.

**Complexidade:** O nó pode descer desde a raiz até uma folha. Consequentemente, o custo de exclusão no pior caso é sempre limitado pela altura da árvore, isto é, $O(\log N)$.
