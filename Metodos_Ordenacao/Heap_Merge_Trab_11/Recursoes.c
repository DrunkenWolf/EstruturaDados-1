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

void merge(int *vet, int ini, int fim) // função que faz a ordenação das partes do vetor e depois as reintegra - MergeSort
{
    int meio = (ini + fim) / 2;
    int i1 = ini;
    int i2 = ini;
    int i3 = meio + 1;
    int temp[11]; // cria vetor auxiliar que receberá os subvetores ordenados
    while (i2 <= meio && i3 <= fim) // verifica se ainda existem elementos nos subvetores
    {
        if (vet[i2] <= vet[i3]) // verifica qual é maior elemento, o do subvetor da esquerda ou da direita e o copia para o vetor auxiliar
        {
            temp[i1++] = vet[i2++];
        }
        else
        {
            temp[i1++] = vet[i3++];
        }
    }
    while (i2 <= meio) // termina de preencher o subvetor da esquerda
    {
        temp[i1++] = vet[i2++];
    }
    while (i3 <= fim) // termina de preencher o subvetor da direita
    {
        temp[i1++] = vet[i3++];
    }
    for (i1 = ini; i1 <= fim; i1++) // realiza a cópia de todo o vetor auxiliar já ordenado para o vetor original
    {
        vet[i1] = temp[i1];
    }
}

void mergeSort(int *vet, int ini, int fim) // função recursiva que realiza o MergeSort
{
    if (ini < fim) // enquanto ainda existirem posições no vetor
    {
        int meio = (ini + fim) / 2; // divide o vetor em outras duas partes (ao meio)
        mergeSort(vet, ini, meio); // ordena a primeira parte do vetor
        mergeSort(vet, meio + 1, fim); // ordena a segunda parte do vetor
        merge(vet, ini, fim); // chama a função realmente de ordenação e reintegração das partes do vetor
    }
}
