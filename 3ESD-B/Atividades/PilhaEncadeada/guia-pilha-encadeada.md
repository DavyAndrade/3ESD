# Guia de estudo: Pilha e TAD Pilha Encadeada

## Objetivo
Consolidar os conceitos de pilha (LIFO) e mapear para a implementacao do TAD Pilha Encadeada.

## 1) Pilha

### Definicao
Em uma pilha, os itens sao colocados um sobre o outro:
- o ultimo inserido fica no topo;
- o primeiro inserido fica na base.

Modelo intuitivo: pilha de pratos.

### Caracteristica principal
- Inclusao e exclusao acontecem na mesma extremidade: topo.
- Estrategia: LIFO (Last In, First Out).

### Quando utilizar
1. Quando qualquer no pode ser utilizado (sem busca por posicao interna).
2. Para inverter ordem de processamento.
3. Para estruturas aninhadas com profundidade imprevisivel, priorizando as mais internas.

### Operacoes abstratas
- Inserir no topo (push)
- Remover do topo (pop)
- Acessar topo sem remover (consultaTopo)

## 2) Pilha sequencial (apostila)

Estruturas apresentadas:
```c
typedef struct {
    int info;
} TNO;

typedef struct {
    TNO vnos[MAX];
    int topo;
    int maximo;
} TPILHA;
```

Criacao:
```c
void cria_pilha_vazia(TPILHA *ppilha, int max){
    ppilha->topo = -1;
    ppilha->max = max;
}
```

Pilha vazia:
```c
int pilha_vazia(const TPILHA *ppilha){
    return (ppilha->topo == -1);
}
```

Pilha cheia:
```c
int pilha_cheia(const TPILHA *ppilha){
    return (ppilha->topo == ppilha->max - 1);
}
```

Push:
```c
int push(TPILHA *ppilha, const TNO *no){
    if (pilha_cheia(ppilha)) return 0;
    (ppilha->topo)++;
    ppilha->vnos[ppilha->topo] = *no;
    return 1;
}
```

Pop:
```c
int pop(TPILHA *ppilha, TNO *no){
    if (pilha_vazia(ppilha)) return 0;
    *no = ppilha->vnos[ppilha->topo];
    (ppilha->topo)--;
    return 1;
}
```

## 3) Mapeamento para Pilha Encadeada

Na pilha encadeada:
- Nao existe limite fixo de MAX (limite depende da memoria disponivel).
- O topo e um ponteiro para o primeiro no da lista encadeada.
- Push e pop continuam O(1).

Estruturas tipicas:
```c
typedef struct no {
    int info;
    struct no *prox;
} TNO;

typedef struct {
    TNO *topo;
    size_t tamanho;
} TPILHA;
```

## 4) Funcionalidades pedidas na atividade
Implementar:
- pilha_cria
- pilha_vazia
- pilha_push
- pilha_pop
- pilha_consultaTopo
- pilha_exibe

## 5) Regras de comportamento
- pilha_cria: inicializa topo como NULL.
- pilha_vazia: retorna verdadeiro se topo == NULL.
- pilha_push: aloca novo no e coloca no topo.
- pilha_pop: remove topo, devolve valor e libera memoria.
- pilha_consultaTopo: apenas le o topo, sem remover.
- pilha_exibe: imprime do topo para a base.

## 6) Checklist de erros comuns
- Esquecer de liberar memoria no pop.
- Acessar topo sem validar pilha vazia.
- Perder referencia da pilha ao fazer push incorreto.
- Nao tratar falha de malloc.

## 7) Complexidade
- push: O(1)
- pop: O(1)
- consultaTopo: O(1)
- exibe: O(n)
