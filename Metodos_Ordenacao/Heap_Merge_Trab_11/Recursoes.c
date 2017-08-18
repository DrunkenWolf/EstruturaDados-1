#include "Recursoes.h"

void swap (int *vet, int p1, int p2) // fun��o que troca dois valores de posi��o em um vetor
{
    int aux;
    aux = vet[p1];
    vet[p1] = vet[p2];
    vet[p2] = aux;
}

void moveDown(int *vet, int ini, int fim) // fun��o que move o elemento da raiz para baixo na �rvore
{
    int maior = 2 * ini + 1; // encontrar os n�s filho do elemento, por 2*elem + 1 ou + 2
    while (maior <= fim)
    {
        if (maior < fim && vet[maior] < vet[maior + 1]) // verifica se o segundo filho � maior que o primeiro, como deve ser
        {
            maior++;
        }
        if (vet[ini] < vet[maior]) // se o come�o for menor que o maior, deve-se troc�-los de lugar para organizar a �rvore
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

void heapSort(int *vet, int n) // fun��o recursiva que realiza a ordena��o HeapSort
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--) // faz a organiza��o do vetor em uma �rvore, movendo os elementos para ordem ascendente
    {
        moveDown(vet, i, n - 1);
    }
    for (i = n - 1; i >= 1; i--) // ordena��o da �rvore criada movendo os elementos para sua correta posi��o no vetor
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
