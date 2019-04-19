# Divide and Conquer algorithms
Implementações de quicksort e mergesort para comparar seu tempo de execução em algumas situações

## Implementações do Quicksort
1. First Element as Pivot

    Descrição: Sempre escolhe o primeiro elemento do array como pivô

2. Last Element as Pivot

    Descrição: Sempre escolhe o último elemento do array como pivô

3. Median Element as Pivot

    Descrição: Sempre escolhe o elemento mediano, entre o primeiro, o último e o do meio elementos,  do array

4. Randomized Quicksort

    Descrição: Escolhe um elemento aleatório no array como pivô


## Situações testadas

1. Vetores com números aleatórios

    São vetores com ``` n ``` elementos aleatórios
    
2. Vetores em ordem decrescente

    São vetores com ``` n ``` elementos já em ordem decrescente
    
3. Vetores em ordem crescente

    São vetores com ``` n ``` elementos já ordenados

4. Vetores quase ordenados

    São vetores com ``` n ``` elementos, onde ocorrem ```n/2 - 1``` trocas de elementos aleatórios de um vetor já ordenado
    
5. Vetores com pouca variedade numérica

    São vetores com ``` n ``` elementos, onde só há 10 números distintos colocados aleatoriamente

