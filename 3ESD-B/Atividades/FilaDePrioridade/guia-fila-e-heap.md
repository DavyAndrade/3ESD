# Guia de estudo: Fila Sequencial e Base para Fila de Prioridade (Heap)

## Objetivo
Organizar os conceitos de fila sequencial (linear e circular) para servir de base da atividade de FilaDePrioridade com max heap e min heap.

## 1) Fila linear

### Definicao
Fila segue estrategia FIFO (First In, First Out):
- Entra no fim (R = rear)
- Sai no inicio (F = front)

Use quando a ordem de chegada precisa ser preservada.

### Estrutura base (exemplo)
```c
typedef struct {
    int info;
} TNO;

typedef struct {
    TNO vnos[MAX];
    int F, R;
    int maximo;
} TFILA;
```

### Operacoes abstratas
- Incluir no fim (enqueue)
- Excluir da frente (dequeue)
- Acessar frente (peek/front)

### Primeira forma (fila "virgem")
Representacao de fila vazia:
- F = -1 e R = -1 (fila nunca usada)
- Ou F > R (fila ja usada e ficou vazia)

Criacao:
```c
void cria_fila_vazia(TFILA *pfila){
    pfila->F = pfila->R = -1;
}
```

Vazia:
```c
int fila_vazia(TFILA *fila){
    if (fila->F == -1) return 1;
    if (fila->F > fila->R) return 1;
    return 0;
}
```

Cheia:
```c
int fila_cheia(TFILA *fila){
    return (fila->R == MAX - 1);
}
```

Enqueue (com caso especial da fila virgem):
```c
int enqueue(TFILA *pfila, TNO no){
    if (fila_cheia(pfila)) return 0;
    (pfila->R)++;
    if (pfila->F == -1) (pfila->F)++;
    pfila->vnos[pfila->R] = no;
    return 1;
}
```

Dequeue:
```c
int dequeue(TFILA *pfila, TNO *no){
    if (fila_vazia(pfila)) return 0;
    *no = pfila->vnos[pfila->F];
    (pfila->F)++;
    return 1;
}
```

### Segunda forma (remove estado "virgem")
Criacao:
```c
void cria_fila_vazia(TFILA *pfila){
    pfila->F = 0;
    pfila->R = -1;
}
```

Vazia:
```c
int fila_vazia(TFILA *fila){
    return (fila->F > fila->R);
}
```

Vantagem:
- Evita parte dos casos especiais de F = -1.

### Terceira forma (ajuste apos remover ultimo)
Problema das formas anteriores:
- F e R "andam" para a direita.
- Pode ocorrer overflow mesmo com poucos elementos validos no vetor.

Solucao pratica na fila linear:
- Ao remover o ultimo elemento, recriar a fila vazia.

## 2) Fila circular

### Motivacao
Na fila linear, espacos liberados no inicio do vetor nao sao reaproveitados. A fila circular trata o vetor como anel e reaproveita slots.

### Sucessor circular
```c
int sucessor(int max, int atual){
    return (atual + 1) % max;
}
```

Regra:
- Proximo R: `sucessor(max, R)`
- Proximo F: `sucessor(max, F)`

### Problema novo: detectar cheia e vazia
Em circular, relacao F > R nao indica vazio.

Cheia (sem contador):
- Se `sucessor(max, R) == F`, nao ha espaco.

Exemplo:
```c
int fila_cheia(const TFILA *pfila){
    int proxR = sucessor(pfila->maximo, pfila->R);
    return (proxR == pfila->F) && (pfila->R != -1);
}
```

Vazia (sem contador):
- Estado "virgem" (ex.: R == -1), ou recriacao apos retirar ultimo.

Enqueue circular:
```c
int enqueue(TFILA *pfila, TNO no){
    if (fila_cheia(pfila)) return 0;
    pfila->R = sucessor(pfila->maximo, pfila->R);
    pfila->vnos[pfila->R] = no;
    return 1;
}
```

Dequeue circular:
```c
int dequeue(TFILA *pfila, TNO *no){
    if (fila_vazia(pfila)) return 0;
    *no = pfila->vnos[pfila->F];
    if (pfila->F == pfila->R)
        cria_fila_vazia(pfila);
    else
        pfila->F = sucessor(pfila->maximo, pfila->F);
    return 1;
}
```

## 3) Circular com contador
Adicionar campo `qtd` em `TFILA` simplifica verificacoes:
- Vazia: `qtd == 0`
- Cheia: `qtd == MAX`

Fluxo:
- Enqueue: grava em R, depois `qtd++`
- Dequeue: le de F, depois `qtd--`

Vantagem:
- Logica de estado mais simples e legivel.

## 4) Circular com no bobo (dummy)
Ideia:
- F e R podem apontar para mesma posicao para representar vazio.
- Existe um "slot dummy" para remover ambiguidades de estado.

Variante comum (dummy em F):
- Vazia: `F == R`
- Cheia: `sucessor(max, R) == F`

Criacao:
```c
void cria_fila_vazia(TFILA *pfila){
    pfila->F = pfila->R = 0;
}
```

## 5) Relacao com Max Heap e Min Heap

### Ponto importante
Fila FIFO e Heap sao estruturas diferentes:
- Fila comum respeita ordem de chegada.
- Fila de prioridade (heap) remove por prioridade.

### Heap em vetor
Para atividade de FilaDePrioridade:
- Max heap: maior prioridade sai primeiro.
- Min heap: menor prioridade sai primeiro.

Operacoes principais (heap):
- Inserir: coloca no fim e sobe (heapify-up).
- Remover topo: troca topo com ultimo, reduz tamanho e desce (heapify-down).
- Consultar topo: O(1)

Complexidades tipicas:
- Inserir: O(log n)
- Remover topo: O(log n)
- Consultar topo: O(1)

### Estrutura base sugerida para sua atividade
```c
typedef struct {
    int prioridade;
    // outros campos do item
} TItem;

typedef struct {
    TItem v[MAX];
    int n; // quantidade atual
} THeap;
```

## 6) Roteiro pratico para comecar a atividade
1. Implementar fila sequencial linear (enqueue, dequeue, front, vazio, cheia).
2. Implementar max heap no mesmo estilo de vetor sequencial.
3. Duplicar comparador para min heap (ou usar funcao de comparacao).
4. Criar testes de mesa para:
   - insercao crescente
   - insercao decrescente
   - repeticao de prioridades
   - remocao ate esvaziar
5. Comparar comportamento FIFO x prioridade.

## 7) Checklist de erros comuns
- Esquecer de atualizar F/R ao remover ultimo elemento.
- Confundir condicao de fila cheia na circular.
- Em heap, errar calculo de pai e filhos:
  - pai(i) = (i - 1) / 2
  - esq(i) = 2*i + 1
  - dir(i) = 2*i + 2
- Nao validar overflow/underflow.

## 8) Resumo rapido
- Fila linear e boa para fixar FIFO.
- Fila circular resolve desperdicio de slots.
- Heap resolve fila de prioridade com eficiencia.
- Para sua atividade, usar vetor sequencial e o caminho mais direto para max/min heap.
