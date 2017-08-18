#include "Recursoes.h"

void swap (int *vet, int p1, int p2) // função que troca dois valores de posição em um vetor
{
    int aux;
    aux = vet[p1];
    vet[p1] = vet[p2];
    vet[p2] = aux;
}

void moveDown(int *vet, int ini, int fim) // função que move o elemento da raiz para baixo na árvore
{
    int maior = 2 * ini + 1; // encontrar os nós filho do elemento, por 2*elem + 1 ou + 2
    while (maior <= fim)
    {
        if (maior < fim && vet[maior] < vet[maior + 1]) // verifica se o segundo filho é maior que o primeiro, como deve ser
        {
            maior++;
        }
        if (vet[ini] < vet[maior]) // se o começo for menor que o maior, deve-se trocá-los de lugar para organizar a árvore
        {
            swap(vet, ini, maior);
            ini = maior;
            maior = 2 * ini + 1;
        }
        else
        {
            maior = fim + 1;
        }
    }
}

void heapSort(int *vet, int n) // função recursiva que realiza a ordenação HeapSort
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--) // faz a organização do vetor em uma árvore, movendo os elementos para ordem ascendente
    {
        moveDown(vet, i, n - 1);
    }
    for (i = n - 1; i >= 1; i--) // ordenação da árvore criada movendo os elementos para sua correta posição no vetor
    {
        swap(vet, 0, i);
        moveDown(vet, 0, i - 1);
    }
}

void merge(int *vet, int ini, int fim)
{
    int meio = (ini + fim) / 2;
    int i1 = 0;
    int i2 = ini;
    int i3 = meio + 1;
    int temp[fim];
    while (ini < )
    {
        if (vet[i2] < vet[i3])
        {
            temp[i1++] = vet[i2++];
        }
        else
        {
            temp[i1++] = vet[i3++];
        }

    }
}

void mergeSort(int *vet, int ini, int fim)
{
    if (ini < fim)
    {
        int meio = (ini + fim) / 2;
        mergeSort(vet, ini, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, ini, fim);
    }
}
